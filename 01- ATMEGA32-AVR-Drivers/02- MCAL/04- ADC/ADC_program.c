/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 24 October 2023                                               */
/*   Logs      : V01 : Initial Creation                                        */
/*******************************************************************************/

#include  "../inc/STD_TYPES.h"
#include  "../inc/BIT_MATH.h"

#include "../inc/ADC_interface.h"
#include "../inc/ADC_private.h"
#include "../inc/ADC_config.h"

void (* ADC_CallBack)(void) = '\0';

/****************  Functions Decleration  ******************/


void MADC_Init(ADC_VREF_t Copy_ADC_VREF, ADC_ADJUST_t Copy_ADC_Adjust,ADC_TRIGGER_t Copy_ADC_Trigger,ADC_PRESCALER_t Copy_ADC_Prescaler )
{
	/******* FOR ADJUST *********/
	if (Copy_ADC_Adjust == ADC_LEFT_ADJUST)
	{
		SET_BIT(ADC->ADMUX ,ADLAR_BIT);
	}
	else if(Copy_ADC_Adjust == ADC_RIGHT_ADJUST)
	{
		CLR_BIT(ADC->ADMUX ,ADLAR_BIT);
	}
	
	/********** FOR VREF *********/
	/* Bit Masking */
	ADC->ADMUX &= 0b00111111;
	/* Assign VREF Value */
	ADC->ADMUX |= (Copy_ADC_VREF << 6);
	

	/******* FOR TRIGGER *********/
	if (Copy_ADC_Trigger == ADC_AUTO_TRIGGER_ON)
	{
		SET_BIT(ADC->ADCSRA ,ADATE_BIT);
	}
	else if(Copy_ADC_Trigger == ADC_AUTO_TRIGGER_OFF)
	{
		CLR_BIT(ADC->ADCSRA ,ADATE_BIT);
	}
	
	/******* FOR PRESCALER *********/
	/* Bit Masking */
	ADC->ADCSRA &= 0b11111000;
	/* Assign PRESCALER Value */
	ADC->ADCSRA |= Copy_ADC_Prescaler;
	
	
	/******* FOR ADC ENABLE *********/
	SET_BIT(ADC->ADCSRA ,ADEN_BIT);

}

void MADC_getDigitalValueSynchNonBlocking (ADC_CHANNELS_t Copy_ADC_Channel,u16 * ADC_GET_Data)
{	
	u8 TempADC_Data = 0;
	/* Bit Masking */
	ADC->ADMUX &= 0b11100000;
	/* Assign Channel Value */
	ADC->ADMUX |= Copy_ADC_Channel;
		
	/**** The conversion is complete ****/
	if(GET_BIT(ADC->ADCSRA ,ADSC_BIT) == 0)
	{
		TempADC_Data = ADC->ADCL;
		*ADC_GET_Data = TempADC_Data|((ADC->ADCH)<<8);
	}

	/* Start Conversion */
	SET_BIT(ADC->ADCSRA ,ADSC_BIT);

}



/************  CallBack Functions Declerations  *************/

void MADC_getDigitalValueAsynchCallBack(ADC_CHANNELS_t Copy_ADC_Channel ,void (*ptr)(void))
{
	/* Bit Masking */
	ADC->ADMUX &= 0b11100000;
	/* Assign Channel Value */
	ADC->ADMUX |= Copy_ADC_Channel;

	if(ptr != NULL)
	{
		ADC_CallBack = ptr ;

		/* Enable Interrupt */
		SET_BIT(ADC->ADCSRA ,ADIE_BIT);
		
		/* Start Conversion */
		SET_BIT(ADC->ADCSRA ,ADSC_BIT);

	}
}


/*************************  ADC Complete ***************************/
ADC_IRQHandler
{
	ADC_CallBack();

}

