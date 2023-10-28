/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 26 October 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*******************************************************************************/
/* Library includes */
#include  "../inc/STD_TYPES.h"
#include  "../inc/BIT_MATH.h"
/*******************************************************************************/
/* Module includes */
#include  "../inc/TIMER0_interface.h"
#include  "../inc/TIMER0_private.h"
#include  "../inc/TIMER0_config.h"
/*******************************************************************************/
/* CallBack Function for TIMER0  */
void (*TIMER0_CallBack[2]) () ;
u32 Global_u32Number_Of_Overflow = 0;
u32 Global_u32RemainingTime = 0;
TIMER0_GLOBAL_t TIM0_GLOBAL_FUN = TIMER0_NO_OPERATION ;
/*******************************************************************************/
void M_TIMER0_voidInit(void)
{
	/******* Waveform Generation Mode ********/
	TIMER0->TCCR0 &= TIMER0_MODE_MASKING ;
	TIMER0->TCCR0 |= (TIMER0_MODE << 3)  ;
	
	
	/********* Compare Output Mode  **********/
	TIMER0->TCCR0 &= TIMER0_OC0_MASKING 				;
	TIMER0->TCCR0 |= (TIMER0_COMPARE_MATCH_MODE << 4)  	;

}
/*******************************************************************************/
void M_TIMER0_voidStart(void)
{
	/************ Prescaler Options **********/
	TIMER0->TCCR0 &= TIMER0_PRESCALER_MASKING 			;
	TIMER0->TCCR0 |= TIMER0_PRESCALER  					;
}
/*******************************************************************************/
void M_TIMER0_voidStop(void)
{
	TIMER0->TCCR0 &= TIMER0_PRESCALER_MASKING 			;
	TIMER0->TCCR0 |= TIMER0_NO_CLK  					;
}
/*******************************************************************************/
void M_TIMER0_voidSetBusyWait(u32 Copy_u32Time, TIMER0_TIME_t Copy_timeUnit)
{
	TIM0_GLOBAL_FUN = TIMER0_BUSY_WAIT_FUNCTION;
	M_TIMER0_voidInterrupt_Disable(TIMER0_OVERFLOW_INTERRUPT);

	u32 Local_u32Load = 0;
	u32 Timer0_CLK = 0 ;
	#if TIMER0_PRESCALER   == TIMER0_NO_CLK
		Timer0_CLK = 0 ;
	#elif TIMER0_PRESCALER == TIMER0_PRESCALER_1
		Timer0_CLK = SYSTEM_CLOCK_SOURCE ;
	#elif TIMER0_PRESCALER == TIMER0_PRESCALER_8
		Timer0_CLK = (SYSTEM_CLOCK_SOURCE/8) ;
	#elif TIMER0_PRESCALER == TIMER0_PRESCALER_64
		Timer0_CLK = (SYSTEM_CLOCK_SOURCE/64) ;
	#elif TIMER0_PRESCALER == TIMER0_PRESCALER_256
		Timer0_CLK = (SYSTEM_CLOCK_SOURCE/256) ;
	#elif TIMER0_PRESCALER == TIMER0_PRESCALER_1024
		Timer0_CLK = (SYSTEM_CLOCK_SOURCE/1024) ;
	#else
		#error (" Configuration error")
	#endif
	
		/* Calculate */
		switch(Copy_timeUnit)
		{
			/*----------------------------------------------------------------------------------*/
			case TIME_S :
					Local_u32Load = Copy_u32Time * Timer0_CLK ;
					Global_u32Number_Of_Overflow = Local_u32Load / TIMER0_MAXIMUM_VALUE ;
					Global_u32RemainingTime  = Local_u32Load % TIMER0_MAXIMUM_VALUE;

	 				break;
			/*----------------------------------------------------------------------------------*/
			case TIME_MS :
					Local_u32Load = Copy_u32Time * (Timer0_CLK / 1000) ;
					Global_u32Number_Of_Overflow = Local_u32Load / TIMER0_MAXIMUM_VALUE ;
					Global_u32RemainingTime  = Local_u32Load % TIMER0_MAXIMUM_VALUE;

	 				break;
			/*----------------------------------------------------------------------------------*/
			case TIME_US :
					/* Calculate Numbers of Ticks */
					Local_u32Load = Copy_u32Time * (Timer0_CLK / 1000000) ;
					Global_u32Number_Of_Overflow = Local_u32Load / TIMER0_MAXIMUM_VALUE ;
					Global_u32RemainingTime  = Local_u32Load % TIMER0_MAXIMUM_VALUE;

	 				break;
			/*----------------------------------------------------------------------------------*/
			default :
					break;
			/*----------------------------------------------------------------------------------*/
		}
	
	/* Start Timer */
	M_TIMER0_voidStart();
	
	/* Enable Interrupt */
	M_TIMER0_voidInterrupt_Enable(TIMER0_OVERFLOW_INTERRUPT);

	while(TIM0_GLOBAL_FUN == TIMER0_BUSY_WAIT_FUNCTION);

}
/*******************************************************************************/
void M_TIMER0_voidSetPeriodic(u32 Copy_u32Time, TIMER0_TIME_t Copy_timeUnit, void (*func)(void))
{
	TIM0_GLOBAL_FUN = TIMER0_PERIODIC_INTERRUPT_FUNCTION;

	M_TIMER0_voidInterrupt_Disable(TIMER0_OVERFLOW_INTERRUPT);
	
	u32 Local_u32Load = 0;
	u32 Timer0_CLK = 0 ;
	#if TIMER0_PRESCALER   == TIMER0_NO_CLK
		Timer0_CLK = 0 ;
	#elif TIMER0_PRESCALER == TIMER0_PRESCALER_1
		Timer0_CLK = SYSTEM_CLOCK_SOURCE ;
	#elif TIMER0_PRESCALER == TIMER0_PRESCALER_8
		Timer0_CLK = (SYSTEM_CLOCK_SOURCE/8) ;
	#elif TIMER0_PRESCALER == TIMER0_PRESCALER_64
		Timer0_CLK = (SYSTEM_CLOCK_SOURCE/64) ;
	#elif TIMER0_PRESCALER == TIMER0_PRESCALER_256
		Timer0_CLK = (SYSTEM_CLOCK_SOURCE/256) ;
	#elif TIMER0_PRESCALER == TIMER0_PRESCALER_1024
		Timer0_CLK = (SYSTEM_CLOCK_SOURCE/1024) ;
	#else
		#error (" Configuration error")
	#endif
	
	/* Calculate */
	switch(Copy_timeUnit)
	{
		/*----------------------------------------------------------------------------------*/
		case TIME_S :
				Local_u32Load = Copy_u32Time * Timer0_CLK ;
				Global_u32Number_Of_Overflow = Local_u32Load / TIMER0_MAXIMUM_VALUE ;
				Global_u32RemainingTime  = Local_u32Load % TIMER0_MAXIMUM_VALUE;

				break;
		/*----------------------------------------------------------------------------------*/	
		case TIME_MS :
				Local_u32Load = Copy_u32Time * (Timer0_CLK / 1000) ;
				Global_u32Number_Of_Overflow = Local_u32Load / TIMER0_MAXIMUM_VALUE ;
				Global_u32RemainingTime  = Local_u32Load % TIMER0_MAXIMUM_VALUE;

 				break;
		/*----------------------------------------------------------------------------------*/		
		case TIME_US :
				/* Calculate Numbers of Ticks */
				Local_u32Load = Copy_u32Time * (Timer0_CLK / 1000000) ;
				Global_u32Number_Of_Overflow = Local_u32Load / TIMER0_MAXIMUM_VALUE ;
				Global_u32RemainingTime  = Local_u32Load % TIMER0_MAXIMUM_VALUE;

 				break;
		/*----------------------------------------------------------------------------------*/		
		default : 
				break;
		/*----------------------------------------------------------------------------------*/			
	}
	
	
	/* Set call back function */
	TIMER0_CallBack[0] = func ;
	
	/* Start Timer */
	M_TIMER0_voidStart();
	
	/* Enable Interrupt */
	M_TIMER0_voidInterrupt_Enable(TIMER0_OVERFLOW_INTERRUPT);

}
/*******************************************************************************/
void M_TIMER0_voidInterrupt_Enable(TIMER0_INT_t Copy_Interrupt_ID)
{
	if(Copy_Interrupt_ID == TIMER0_OUTPUT_COMPARE_MATCH_INTERRUPT)
	{
		SET_BIT( TIMER0->TIMSK , 1);

	}
	else if(Copy_Interrupt_ID == TIMER0_OVERFLOW_INTERRUPT)
	{
		SET_BIT( TIMER0->TIMSK , 0);
	}
}
/*******************************************************************************/
void M_TIMER0_voidInterrupt_Disable(TIMER0_INT_t Copy_Interrupt_ID)
{
	if(Copy_Interrupt_ID == TIMER0_OUTPUT_COMPARE_MATCH_INTERRUPT)
	{
		CLR_BIT( TIMER0->TIMSK , 1);

	}
	else if(Copy_Interrupt_ID == TIMER0_OVERFLOW_INTERRUPT)
	{
		CLR_BIT( TIMER0->TIMSK , 0);
	}
}
/*******************************************************************************/

void M_TIMER0_voidSetFastPWM(u8 Copy_u8DutyCycle)
{
	#if TIMER0_MODE == TIMER0_FAST_PWM_MODE
		u8 Local_u8DutyCycle = 0;
		M_TIMER0_voidInterrupt_Disable(TIMER0_OUTPUT_COMPARE_MATCH_INTERRUPT);
		#if TIMER0_COMPARE_MATCH_MODE == TIMER0_OC0_CLEAR
			Local_u8DutyCycle = (Copy_u8DutyCycle * TIMER0_MAXIMUM_VALUE)/100 ;
			TIMER0->OCR0 	  = Local_u8DutyCycle ;
			/* Start Timer */
			M_TIMER0_voidStart();
			/* Enable Interrupt */
			M_TIMER0_voidInterrupt_Enable(TIMER0_OUTPUT_COMPARE_MATCH_INTERRUPT);

		#elif TIMER0_COMPARE_MATCH_MODE == TIMER0_OC0_SET
			Local_u8DutyCycle = (Copy_u8DutyCycle * TIMER0_MAXIMUM_VALUE)/100 ;
			TIMER0->OCR0 	  = TIMER0_MAXIMUM_VALUE - Local_u8DutyCycle ;
			/* Start Timer */
			M_TIMER0_voidStart();
			/* Enable Interrupt */
			M_TIMER0_voidInterrupt_Enable(TIMER0_OUTPUT_COMPARE_MATCH_INTERRUPT);
		#endif
	#else
		#warning "[Fast PWM] is Disabled"
	#endif
}

void M_TIMER0_voidSetPhaseCorrectPWM(u8 Copy_u8DutyCycle)
{
	#if TIMER0_MODE == TIMER0_PHASE_CORRECT_PWM_MODE
		u8 Local_u8DutyCycle = 0;
		M_TIMER0_voidInterrupt_Disable(TIMER0_OUTPUT_COMPARE_MATCH_INTERRUPT);
		#if TIMER0_COMPARE_MATCH_MODE == TIMER0_OC0_CLEAR
			Local_u8DutyCycle = (Copy_u8DutyCycle * TIMER0_MAXIMUM_VALUE)/100 ;
			TIMER0->OCR0 	  = Local_u8DutyCycle ;
			/* Start Timer */
			M_TIMER0_voidStart();
			/* Enable Interrupt */
			M_TIMER0_voidInterrupt_Enable(TIMER0_OUTPUT_COMPARE_MATCH_INTERRUPT);

		#elif TIMER0_COMPARE_MATCH_MODE == TIMER0_OC0_SET
			Local_u8DutyCycle = (Copy_u8DutyCycle * TIMER0_MAXIMUM_VALUE)/100 ;
			TIMER0->OCR0 	  = TIMER0_MAXIMUM_VALUE - Local_u8DutyCycle ;
			/* Start Timer */
			M_TIMER0_voidStart();
			/* Enable Interrupt */
			M_TIMER0_voidInterrupt_Enable(TIMER0_OUTPUT_COMPARE_MATCH_INTERRUPT);
		#endif
	#else
		#warning "[Phase Correct PWM] is Disabled"
	#endif

}
/*******************************************************************************/
/* Timer/Counter0 Compare Match  ISR */
TIMER0_CompareMatch_IRQHandler
{
//	TIMER0_CallBack[1]();
}
/*******************************************************************************/
/* Timer/Counter0 Overflow ISR */
TIMER0_Overflow_IRQHandler
{
	if(	TIM0_GLOBAL_FUN == TIMER0_PERIODIC_INTERRUPT_FUNCTION)
	{
		static u32 Timer_Overflow_counter = 0;
		Timer_Overflow_counter++;
		if(Timer_Overflow_counter == Global_u32Number_Of_Overflow)
		{
			TIMER0->OCR0 = Global_u32RemainingTime;
			Timer_Overflow_counter = 0 ;
			TIMER0_CallBack[0]();
		}
	}

	else if (TIM0_GLOBAL_FUN == TIMER0_BUSY_WAIT_FUNCTION)
	{
		static u32 Timer_Overflow_counter = 0;
		Timer_Overflow_counter++;
		if(Timer_Overflow_counter == Global_u32Number_Of_Overflow)
		{
			TIMER0->OCR0 = Global_u32RemainingTime;
			Timer_Overflow_counter = 0 ;
			TIM0_GLOBAL_FUN = TIMER0_NO_OPERATION ;

		}
	}
}
/*******************************************************************************/






