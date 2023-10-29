/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V02                                                           */
/*   Date      : 29 October 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*               V02 : Fix Errors in Calculations for Delay                    */
/*******************************************************************************/
/* Library includes */
#include  "../inc/STD_TYPES.h"
#include  "../inc/BIT_MATH.h"
/*******************************************************************************/
/* Module includes */
#include  "../inc/TIMER2_interface.h"
#include  "../inc/TIMER2_private.h"
#include  "../inc/TIMER2_config.h"
/*******************************************************************************/
/* CallBack Function for TIMER2  */
void (*TIMER2_CallBack[2]) () ;
u32 Global_u32Number_Of_Overflow = 0;
u8 Global_u8RemainingTime = 0;
TIMER2_GLOBAL_t TIM2_GLOBAL_FUN = TIMER2_NO_OPERATION ;
/*******************************************************************************/
void M_TIMER2_voidInit(void)
{
	/******* Waveform Generation Mode ********/
	TIMER2->TCCR2 &= TIMER2_MODE_MASKING ;
	TIMER2->TCCR2 |= (TIMER2_MODE << 3)  ;
	
	
	/********* Compare Output Mode  **********/
	TIMER2->TCCR2 &= TIMER2_OC2_MASKING 				;
	TIMER2->TCCR2 |= (TIMER2_COMPARE_MATCH_MODE << 4)  	;

}
/*******************************************************************************/
void M_TIMER2_voidStart(void)
{
	/************ Prescaler Options **********/
	TIMER2->TCCR2 &= TIMER2_PRESCALER_MASKING 			;
	TIMER2->TCCR2 |= TIMER2_PRESCALER  					;
}
/*******************************************************************************/
void M_TIMER2_voidStop(void)
{
	TIMER2->TCCR2 &= TIMER2_PRESCALER_MASKING 			;
	TIMER2->TCCR2 |= TIMER2_NO_CLK  					;
}
/*******************************************************************************/
void M_TIMER2_voidSetBusyWait(u32 Copy_u32Time, TIMER2_TIME_t Copy_timeUnit)
{
	TIM2_GLOBAL_FUN = TIMER2_BUSY_WAIT_FUNCTION;
	M_TIMER2_voidInterrupt_Disable(TIMER2_OVERFLOW_INTERRUPT);

	u32 Local_u32Load = 0;
	u32 TIMER2_CLK = 0 ;
	#if TIMER2_PRESCALER   == TIMER2_NO_CLK
		TIMER2_CLK = 0 ;
	#elif TIMER2_PRESCALER == TIMER2_PRESCALER_1
		TIMER2_CLK = SYSTEM_CLOCK_SOURCE ;
	#elif TIMER2_PRESCALER == TIMER2_PRESCALER_8
		TIMER2_CLK = (SYSTEM_CLOCK_SOURCE/8) ;
	#elif TIMER2_PRESCALER == TIMER2_PRESCALER_32
		TIMER2_CLK = (SYSTEM_CLOCK_SOURCE/32) ;
	#elif TIMER2_PRESCALER == TIMER2_PRESCALER_64
		TIMER2_CLK = (SYSTEM_CLOCK_SOURCE/64) ;
	#elif TIMER2_PRESCALER == TIMER2_PRESCALER_128
		TIMER2_CLK = (SYSTEM_CLOCK_SOURCE/128) ;
	#elif TIMER2_PRESCALER == TIMER2_PRESCALER_256
		TIMER2_CLK = (SYSTEM_CLOCK_SOURCE/256) ;
	#elif TIMER2_PRESCALER == TIMER2_PRESCALER_1024
		TIMER2_CLK = (SYSTEM_CLOCK_SOURCE/1024) ;
	#else
		#error (" Configuration error")
	#endif
	
		/* Calculate */
		switch(Copy_timeUnit)
		{
			/*----------------------------------------------------------------------------------*/
			case TIME_S :
					Local_u32Load = Copy_u32Time * TIMER2_CLK ;
					Global_u32Number_Of_Overflow = Local_u32Load / TIMER2_MAXIMUM_VALUE ;
					Global_u8RemainingTime       = Local_u32Load % TIMER2_MAXIMUM_VALUE ;
					Global_u8RemainingTime       = (TIMER2_MAXIMUM_VALUE - Global_u8RemainingTime);
					TIMER2->TCNT2 = Global_u8RemainingTime ;
	 				break;
			/*----------------------------------------------------------------------------------*/
			case TIME_MS :
					Local_u32Load = Copy_u32Time * (TIMER2_CLK / 1000) ;
					Global_u32Number_Of_Overflow = Local_u32Load / TIMER2_MAXIMUM_VALUE ;
					Global_u8RemainingTime       = Local_u32Load % TIMER2_MAXIMUM_VALUE ;
					Global_u8RemainingTime       = (TIMER2_MAXIMUM_VALUE - Global_u8RemainingTime);
					TIMER2->TCNT2 = Global_u8RemainingTime ;
	 				break;
			/*----------------------------------------------------------------------------------*/
			case TIME_US :
					/* Calculate Numbers of Ticks */
					Local_u32Load = Copy_u32Time * (TIMER2_CLK / 1000000) ;
					Global_u32Number_Of_Overflow = Local_u32Load / TIMER2_MAXIMUM_VALUE ;
					Global_u8RemainingTime       = Local_u32Load % TIMER2_MAXIMUM_VALUE ;
					Global_u8RemainingTime       = (TIMER2_MAXIMUM_VALUE - Global_u8RemainingTime);
					TIMER2->TCNT2 = Global_u8RemainingTime ;
	 				break;
			/*----------------------------------------------------------------------------------*/
			default :
					break;
			/*----------------------------------------------------------------------------------*/
		}
	
	/* Start Timer */
	M_TIMER2_voidStart();
	
	/* Enable Interrupt */
	M_TIMER2_voidInterrupt_Enable(TIMER2_OVERFLOW_INTERRUPT);

	while(TIM2_GLOBAL_FUN == TIMER2_BUSY_WAIT_FUNCTION);

}
/*******************************************************************************/
void M_TIMER2_voidSetPeriodic(u32 Copy_u32Time, TIMER2_TIME_t Copy_timeUnit, void (*func)(void))
{
	TIM2_GLOBAL_FUN = TIMER2_PERIODIC_INTERRUPT_FUNCTION;

	M_TIMER2_voidInterrupt_Disable(TIMER2_OVERFLOW_INTERRUPT);
	
	u32 Local_u32Load = 0;
	u32 TIMER2_CLK = 0 ;
	#if TIMER2_PRESCALER   == TIMER2_NO_CLK
		TIMER2_CLK = 0 ;
	#elif TIMER2_PRESCALER == TIMER2_PRESCALER_1
		TIMER2_CLK = SYSTEM_CLOCK_SOURCE ;
	#elif TIMER2_PRESCALER == TIMER2_PRESCALER_8
		TIMER2_CLK = (SYSTEM_CLOCK_SOURCE/8) ;
	#elif TIMER2_PRESCALER == TIMER2_PRESCALER_32
		TIMER2_CLK = (SYSTEM_CLOCK_SOURCE/32) ;
	#elif TIMER2_PRESCALER == TIMER2_PRESCALER_64
		TIMER2_CLK = (SYSTEM_CLOCK_SOURCE/64) ;
	#elif TIMER2_PRESCALER == TIMER2_PRESCALER_128
		TIMER2_CLK = (SYSTEM_CLOCK_SOURCE/128) ;
	#elif TIMER2_PRESCALER == TIMER2_PRESCALER_256
		TIMER2_CLK = (SYSTEM_CLOCK_SOURCE/256) ;
	#elif TIMER2_PRESCALER == TIMER2_PRESCALER_1024
		TIMER2_CLK = (SYSTEM_CLOCK_SOURCE/1024) ;
	#else
		#error (" Configuration error")
	#endif
	
		/* Calculate */
		switch(Copy_timeUnit)
		{
			/*----------------------------------------------------------------------------------*/
			case TIME_S :
					Local_u32Load = Copy_u32Time * TIMER2_CLK ;
					Global_u32Number_Of_Overflow = Local_u32Load / TIMER2_MAXIMUM_VALUE ;
					Global_u8RemainingTime       = Local_u32Load % TIMER2_MAXIMUM_VALUE ;
					Global_u8RemainingTime       = (TIMER2_MAXIMUM_VALUE - Global_u8RemainingTime);
					TIMER2->TCNT2 = Global_u8RemainingTime ;
	 				break;
			/*----------------------------------------------------------------------------------*/
			case TIME_MS :
					Local_u32Load = Copy_u32Time * (TIMER2_CLK / 1000) ;
					Global_u32Number_Of_Overflow = Local_u32Load / TIMER2_MAXIMUM_VALUE ;
					Global_u8RemainingTime       = Local_u32Load % TIMER2_MAXIMUM_VALUE ;
					Global_u8RemainingTime       = (TIMER2_MAXIMUM_VALUE - Global_u8RemainingTime);
					TIMER2->TCNT2 = Global_u8RemainingTime ;
	 				break;
			/*----------------------------------------------------------------------------------*/
			case TIME_US :
					/* Calculate Numbers of Ticks */
					Local_u32Load = Copy_u32Time * (TIMER2_CLK / 1000000) ;
					Global_u32Number_Of_Overflow = Local_u32Load / TIMER2_MAXIMUM_VALUE ;
					Global_u8RemainingTime       = Local_u32Load % TIMER2_MAXIMUM_VALUE ;
					Global_u8RemainingTime       = (TIMER2_MAXIMUM_VALUE - Global_u8RemainingTime);
					TIMER2->TCNT2 = Global_u8RemainingTime ;
	 				break;
			/*----------------------------------------------------------------------------------*/
			default :
					break;
			/*----------------------------------------------------------------------------------*/
		}
	
	
	/* Set call back function */
	TIMER2_CallBack[0] = func ;
	
	/* Start Timer */
	M_TIMER2_voidStart();
	
	/* Enable Interrupt */
	M_TIMER2_voidInterrupt_Enable(TIMER2_OVERFLOW_INTERRUPT);

}
/*******************************************************************************/
void M_TIMER2_voidInterrupt_Enable(TIMER2_INT_t Copy_Interrupt_ID)
{
	if(Copy_Interrupt_ID == TIMER2_OUTPUT_COMPARE_MATCH_INTERRUPT)
	{
		SET_BIT( TIMER2->TIMSK , 7);

	}
	else if(Copy_Interrupt_ID == TIMER2_OVERFLOW_INTERRUPT)
	{
		SET_BIT( TIMER2->TIMSK , 6);
	}
}
/*******************************************************************************/
void M_TIMER2_voidInterrupt_Disable(TIMER2_INT_t Copy_Interrupt_ID)
{
	if(Copy_Interrupt_ID == TIMER2_OUTPUT_COMPARE_MATCH_INTERRUPT)
	{
		CLR_BIT( TIMER2->TIMSK , 7);

	}
	else if(Copy_Interrupt_ID == TIMER2_OVERFLOW_INTERRUPT)
	{
		CLR_BIT( TIMER2->TIMSK , 6);
	}
}
/*******************************************************************************/

void M_TIMER2_voidSetFastPWM(u8 Copy_u8DutyCycle)
{
	#if TIMER2_MODE == TIMER2_FAST_PWM_MODE
		u8 Local_u8DutyCycle = 0;
		M_TIMER2_voidInterrupt_Disable(TIMER2_OUTPUT_COMPARE_MATCH_INTERRUPT);
		#if TIMER2_COMPARE_MATCH_MODE == TIMER2_OC2_CLEAR
			Local_u8DutyCycle = (Copy_u8DutyCycle * TIMER2_MAXIMUM_VALUE)/100 ;
			TIMER2->OCR2 	  = Local_u8DutyCycle ;
			/* Start Timer */
			M_TIMER2_voidStart();
			/* Enable Interrupt */
			M_TIMER2_voidInterrupt_Enable(TIMER2_OUTPUT_COMPARE_MATCH_INTERRUPT);

		#elif TIMER2_COMPARE_MATCH_MODE == TIMER2_OC2_SET
			Local_u8DutyCycle = (Copy_u8DutyCycle * TIMER2_MAXIMUM_VALUE)/100 ;
			TIMER2->OCR2 	  = TIMER2_MAXIMUM_VALUE - Local_u8DutyCycle ;
			/* Start Timer */
			M_TIMER2_voidStart();
			/* Enable Interrupt */
			M_TIMER2_voidInterrupt_Enable(TIMER2_OUTPUT_COMPARE_MATCH_INTERRUPT);
		#endif
	#else
		#warning "[Fast PWM] is Disabled"
	#endif
}

void M_TIMER2_voidSetPhaseCorrectPWM(u8 Copy_u8DutyCycle)
{
	#if TIMER2_MODE == TIMER2_PHASE_CORRECT_PWM_MODE
		u8 Local_u8DutyCycle = 0;
		M_TIMER2_voidInterrupt_Disable(TIMER2_OUTPUT_COMPARE_MATCH_INTERRUPT);
		#if TIMER2_COMPARE_MATCH_MODE == TIMER2_OC2_CLEAR
			Local_u8DutyCycle = (Copy_u8DutyCycle * TIMER2_MAXIMUM_VALUE)/100 ;
			TIMER2->OCR2 	  = Local_u8DutyCycle ;
			/* Start Timer */
			M_TIMER2_voidStart();
			/* Enable Interrupt */
			M_TIMER2_voidInterrupt_Enable(TIMER2_OUTPUT_COMPARE_MATCH_INTERRUPT);

		#elif TIMER2_COMPARE_MATCH_MODE == TIMER2_OC2_SET
			Local_u8DutyCycle = (Copy_u8DutyCycle * TIMER2_MAXIMUM_VALUE)/100 ;
			TIMER2->OCR2 	  = TIMER2_MAXIMUM_VALUE - Local_u8DutyCycle ;
			/* Start Timer */
			M_TIMER2_voidStart();
			/* Enable Interrupt */
			M_TIMER2_voidInterrupt_Enable(TIMER2_OUTPUT_COMPARE_MATCH_INTERRUPT);
		#endif
	#else
		#warning "[Phase Correct PWM] is Disabled"
	#endif

}
/*******************************************************************************/
/* Timer/Counter2 Compare Match  ISR */
TIMER2_CompareMatch_IRQHandler
{
//	TIMER2_CallBack[1]();
}
/*******************************************************************************/
/* Timer/Counter2 Overflow ISR */
TIMER2_Overflow_IRQHandler
{
	if(	TIM2_GLOBAL_FUN == TIMER2_PERIODIC_INTERRUPT_FUNCTION)
	{
		static u32 Timer_Overflow_counter = 0;
		Timer_Overflow_counter++;
		if(Timer_Overflow_counter == Global_u32Number_Of_Overflow+1)
		{
			TIMER2_CallBack[0]();
			Timer_Overflow_counter = 0 ;
			TIMER2->TCNT2 = Global_u8RemainingTime;

		}
	}

	else if (TIM2_GLOBAL_FUN == TIMER2_BUSY_WAIT_FUNCTION)
	{
		static u32 Timer_Overflow_counter = 0;
		Timer_Overflow_counter++;
		if(Timer_Overflow_counter == Global_u32Number_Of_Overflow+1)
		{
			Timer_Overflow_counter = 0 ;
			TIM2_GLOBAL_FUN = TIMER2_NO_OPERATION ;
		}
		else if(Global_u32Number_Of_Overflow == 0)
		{
			TIM2_GLOBAL_FUN = TIMER2_NO_OPERATION ;
		}
	}
}
/*******************************************************************************/






