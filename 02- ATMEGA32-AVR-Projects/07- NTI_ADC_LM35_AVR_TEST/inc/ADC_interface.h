/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V02                                                           */
/*   Date      : 26 October 2023                                               */
/*   Logs      : V01 : Initial Creation                                        */
/*               V02 : Adding Trigger Mode and Get ADC_Data Function           */
/*******************************************************************************/
#ifndef  ADC_INTERFACE_H
#define  ADC_INTERFACE_H

/* Enum for 8 ADC CHANNELS  */
typedef enum
{
	ADC_CHANNEL_0  = 0,
	ADC_CHANNEL_1  ,
	ADC_CHANNEL_2  ,
	ADC_CHANNEL_3  ,
	ADC_CHANNEL_4  ,
	ADC_CHANNEL_5  ,
	ADC_CHANNEL_6  ,
	ADC_CHANNEL_7  
 
}ADC_CHANNELS_t;
	

/* Enum for ADC ADJUST  */
typedef enum
{
	ADC_LEFT_ADJUST     ,
	ADC_RIGHT_ADJUST
}ADC_ADJUST_t;
	

/* Enum for ADC VOLTAGE REFERENCE  */
typedef enum
{
	ADC_VREF_OFF  = 0	,
	ADC_AVCC      		, 
	ADC_VREF_ON   = 3
}ADC_VREF_t;
	
/* Enum for ADC INTERRUPT  */
typedef enum
{
	ADC_INTERRUPT_OFF = 0,
	ADC_INTERRUPT_ON
}ADC_INTERRUPT_t;
	
/* Enum for ADC AUTO TRIGGER  */
typedef enum
{
	ADC_AUTO_TRIGGER_OFF = 0,
	ADC_AUTO_TRIGGER_ON
}ADC_TRIGGER_t;

/* Enum for ADC AUTO TRIGGER MODES  */
typedef enum
{
	ADC_FREE_RUNNING    = 0	   	,
	ADC_ANALOG_COMPARATOR      	,
	ADC_EXTI0   			   	,
	ADC_TIMER0_COMPARE_MATCH   	,
	ADC_TIMER0_OVERFLOW   		,
	ADC_TIMER1_COMPARE_MATCH_B  ,
	ADC_TIMER1_OVERFLOW   		,
	ADC_TIMER1_CAPTURE_EVENT
}ADC_TRIG_MOD_t;



/* Enum for ADC PRE-SCALER  */
typedef enum
{
	ADC_PRESCALER_DIVID_2 = 1 ,
	ADC_PRESCALER_DIVID_4     ,
	ADC_PRESCALER_DIVID_8     ,
	ADC_PRESCALER_DIVID_16    ,
	ADC_PRESCALER_DIVID_32    ,
	ADC_PRESCALER_DIVID_64    ,
	ADC_PRESCALER_DIVID_128   
}ADC_PRESCALER_t;
	


/****************  Functions Decleration  ******************/


void MADC_Init(ADC_VREF_t Copy_ADC_VREF          	,
			   ADC_ADJUST_t Copy_ADC_Adjust		 	,
			   ADC_PRESCALER_t Copy_ADC_Prescaler	,
			   ADC_TRIGGER_t Copy_ADC_Trigger    	,
			   ADC_TRIG_MOD_t Copy_ADC_Trigger_Mode
			   );

void MADC_getDigitalValueSynchNonBlocking (ADC_CHANNELS_t Copy_ADC_Channel,u16 * ADC_GET_Data);

u16 MADC_getDigitalValue(void);



/************  CallBack Functions Declerations  *************/

void MADC_getDigitalValueAsynchCallBack(ADC_CHANNELS_t Copy_ADC_Channel ,void (*ptr)(void)) ;






#endif
