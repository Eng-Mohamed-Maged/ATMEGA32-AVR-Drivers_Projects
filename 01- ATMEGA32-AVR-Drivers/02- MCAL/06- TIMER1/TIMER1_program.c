/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V02                                                           */
/*   Date      : 2 November 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*               V02 : Fast PWM and Phase Correct PWM are fixed                */
/*******************************************************************************/
/* Library includes */
#include  "../inc/STD_TYPES.h"
#include  "../inc/BIT_MATH.h"
/*******************************************************************************/
/* Module includes */
#include  "../inc/TIMER1_interface.h"
#include  "../inc/TIMER1_private.h"
#include  "../inc/TIMER1_config.h"
/*******************************************************************************/
/* CallBack Function for TIMER1  */
void (*TIMER1_CallBack[4]) () ;
u32 Global_u32Number_Of_Overflow_CaptureUnit = 0;
u32 Global_u32Number_Of_Overflow = 0;
u32 Global_u32ICR_StartTicks = 0;
u16 Global_u16RemainingTime = 0;
TIMER1_GLOBAL_t TIM1_GLOBAL_FUN = TIMER1_NO_OPERATION ;
/*******************************************************************************/
void FAST_PWM_MODE14(void)
{
	  // Clear OC1A and OC1B on Compare Match / Set OC1A and OC1B at Bottom;
	  // Wave Form Generator: Fast PWM 14, Top = ICR1
//	TIMER1->TCCR1A = (1<<7) + (1<<5) + (1<<1);

	/********* Compare Output Mode Channel A  **********/
	TIMER1->TCCR1A &= TIMER1_MODE_MASKING ;
	TIMER1->TCCR1A |= (TIMER1_COMPARE_MATCH_A_MODE << 6)  ;
	TIMER1->TCCR1A |= (TIMER1_COMPARE_MATCH_B_MODE << 4)  ;
	/********* Compare Output Mode Channel B  **********/




	/********** Waveform Generation Mode ***************/
	TIMER1->TCCR1B &= TIMER1_MODE_MASKING ;
	TIMER1->TCCR1A |= ((TIMER1_MODE >> 8) & 0xFF);
	TIMER1->TCCR1B |=  TIMER1_MODE & 0xFF ;



	u16  ICR1_VALUE = 15999;
	u16  OCR1A_VALUE = 7999;
	u16  OCR1B_VALUE = 7999;

	TIMER1->ICR1H = (ICR1_VALUE >> 8) & 0xFF; // High Byte
	TIMER1->ICR1L = ICR1_VALUE & 0xFF;        // Low Byte

	TIMER1->OCR1AH = (OCR1A_VALUE >> 8) & 0xFF; // High Byte
	TIMER1->OCR1AL =  OCR1A_VALUE & 0xFF;        // Low Byte

	TIMER1->OCR1BH = (OCR1B_VALUE >> 8) & 0xFF; // High Byte
	TIMER1->OCR1BL =  OCR1B_VALUE & 0xFF;        // Low Byte

	M_TIMER1_voidStart();

}
/*******************************************************************************/
void M_TIMER1_voidInit(void)
{
	/********* Compare Output Mode Channel A - B  **********/
	TIMER1->TCCR1A &= TIMER1_MODE_MASKING ;
	TIMER1->TCCR1A |= (TIMER1_COMPARE_MATCH_A_MODE << 6)  ;
	TIMER1->TCCR1A |= (TIMER1_COMPARE_MATCH_B_MODE << 4)  ;

	/********** Waveform Generation Mode ***************/
	TIMER1->TCCR1B &= TIMER1_MODE_MASKING ;
	TIMER1->TCCR1A |= ((TIMER1_MODE >> 8) & 0xFF);
	TIMER1->TCCR1B |=  TIMER1_MODE & 0xFF ;

}
/*******************************************************************************/
void M_TIMER1_voidStart(void)
{
	/************ Prescaler Options **********/
	TIMER1->TCCR1B &= TIMER1_PRESCALER_MASKING 			    ;
	TIMER1->TCCR1B |= TIMER1_PRESCALER  					;
}
/*******************************************************************************/
void M_TIMER1_voidStop(void)
{
	/************ Prescaler Options **********/
	TIMER1->TCCR1B &= TIMER1_PRESCALER_MASKING 			    ;
	TIMER1->TCCR1B |= TIMER1_NO_CLK  					    ;
}
/*******************************************************************************/
void M_TIMER1_voidSetBusyWait(u32 Copy_u32Time, TIMER1_TIME_t Copy_timeUnit)
{
	TIM1_GLOBAL_FUN = TIMER1_BUSY_WAIT_FUNCTION;
	M_TIMER1_voidInterrupt_Disable(TIMER1_OVERFLOW_INTERRUPT);

	u32 Local_u32Load = 0;
	u32 TIMER1_CLK = 0 ;
	#if TIMER1_PRESCALER   == TIMER1_NO_CLK
		TIMER1_CLK = 0 ;
	#elif TIMER1_PRESCALER == TIMER1_PRESCALER_1
		TIMER1_CLK = SYSTEM_CLOCK_SOURCE ;
	#elif TIMER1_PRESCALER == TIMER1_PRESCALER_8
		TIMER1_CLK = (SYSTEM_CLOCK_SOURCE/8) ;
	#elif TIMER1_PRESCALER == TIMER1_PRESCALER_64
		TIMER1_CLK = (SYSTEM_CLOCK_SOURCE/64) ;
	#elif TIMER1_PRESCALER == TIMER1_PRESCALER_256
		TIMER1_CLK = (SYSTEM_CLOCK_SOURCE/256) ;
	#elif TIMER1_PRESCALER == TIMER1_PRESCALER_1024
		TIMER1_CLK = (SYSTEM_CLOCK_SOURCE/1024) ;
	#else
		#error (" Configuration error")
	#endif
	
		/* Calculate */
		switch(Copy_timeUnit)
		{
			/*----------------------------------------------------------------------------------*/
			case TIME_S :
					Local_u32Load = Copy_u32Time * TIMER1_CLK ;
					Global_u32Number_Of_Overflow = Local_u32Load / TIMER1_MAXIMUM_VALUE ;
					Global_u16RemainingTime      = Local_u32Load % TIMER1_MAXIMUM_VALUE ;
					Global_u16RemainingTime = (TIMER1_MAXIMUM_VALUE - Global_u16RemainingTime);


					TIMER1->TCNT1H = (Global_u16RemainingTime >> 8) & 0xFF; // High byte
					TIMER1->TCNT1L = Global_u16RemainingTime & 0xFF;

 				break;
			/*----------------------------------------------------------------------------------*/
			case TIME_MS :
					Local_u32Load = Copy_u32Time * (TIMER1_CLK / 1000) ;
					Global_u32Number_Of_Overflow = Local_u32Load / TIMER1_MAXIMUM_VALUE ;
					Global_u16RemainingTime      = Local_u32Load % TIMER1_MAXIMUM_VALUE ;
					Global_u16RemainingTime = (TIMER1_MAXIMUM_VALUE - Global_u16RemainingTime);


					TIMER1->TCNT1H = (Global_u16RemainingTime >> 8) & 0xFF; // High byte
					TIMER1->TCNT1L = Global_u16RemainingTime & 0xFF;
	 				break;
			/*----------------------------------------------------------------------------------*/
			case TIME_US :
					/* Calculate Numbers of Ticks */
					Local_u32Load = Copy_u32Time * (TIMER1_CLK / 1000000) ;
					Global_u32Number_Of_Overflow = Local_u32Load / TIMER1_MAXIMUM_VALUE ;
					Global_u16RemainingTime      = Local_u32Load % TIMER1_MAXIMUM_VALUE ;
					Global_u16RemainingTime = (TIMER1_MAXIMUM_VALUE - Global_u16RemainingTime);


					TIMER1->TCNT1H = (Global_u16RemainingTime >> 8) & 0xFF; // High byte
					TIMER1->TCNT1L = Global_u16RemainingTime & 0xFF;
	 				break;
			/*----------------------------------------------------------------------------------*/
			default :
					break;
			/*----------------------------------------------------------------------------------*/
		}
	
	/* Start Timer */
	M_TIMER1_voidStart();
	
	/* Enable Interrupt */
	M_TIMER1_voidInterrupt_Enable(TIMER1_OVERFLOW_INTERRUPT);

	while(TIM1_GLOBAL_FUN == TIMER1_BUSY_WAIT_FUNCTION);

}
/*******************************************************************************/
void M_TIMER1_voidSetPeriodic(u32 Copy_u32Time, TIMER1_TIME_t Copy_timeUnit, void (*func)(void))
{
	TIM1_GLOBAL_FUN = TIMER1_PERIODIC_INTERRUPT_FUNCTION;
	M_TIMER1_voidInterrupt_Disable(TIMER1_OVERFLOW_INTERRUPT);
	
	u32 Local_u32Load = 0;
	u32 TIMER1_CLK = 0 ;
	#if TIMER1_PRESCALER   == TIMER1_NO_CLK
		TIMER1_CLK = 0 ;
	#elif TIMER1_PRESCALER == TIMER1_PRESCALER_1
		TIMER1_CLK = SYSTEM_CLOCK_SOURCE ;
	#elif TIMER1_PRESCALER == TIMER1_PRESCALER_8
		TIMER1_CLK = (SYSTEM_CLOCK_SOURCE/8) ;
	#elif TIMER1_PRESCALER == TIMER1_PRESCALER_64
		TIMER1_CLK = (SYSTEM_CLOCK_SOURCE/64) ;
	#elif TIMER1_PRESCALER == TIMER1_PRESCALER_256
		TIMER1_CLK = (SYSTEM_CLOCK_SOURCE/256) ;
	#elif TIMER1_PRESCALER == TIMER1_PRESCALER_1024
		TIMER1_CLK = (SYSTEM_CLOCK_SOURCE/1024) ;
	#else
		#error (" Configuration error")
	#endif
	
		/* Calculate */
		switch(Copy_timeUnit)
		{
			/*----------------------------------------------------------------------------------*/
			case TIME_S :
					Local_u32Load = Copy_u32Time * TIMER1_CLK ;
					Global_u32Number_Of_Overflow = Local_u32Load / TIMER1_MAXIMUM_VALUE ;
					Global_u16RemainingTime      = Local_u32Load % TIMER1_MAXIMUM_VALUE ;
					Global_u16RemainingTime = (TIMER1_MAXIMUM_VALUE - Global_u16RemainingTime);


					TIMER1->TCNT1H = (Global_u16RemainingTime >> 8) & 0xFF; // High byte
					TIMER1->TCNT1L = Global_u16RemainingTime & 0xFF;

 				break;
			/*----------------------------------------------------------------------------------*/
			case TIME_MS :
					Local_u32Load = Copy_u32Time * (TIMER1_CLK / 1000) ;
					Global_u32Number_Of_Overflow = Local_u32Load / TIMER1_MAXIMUM_VALUE ;
					Global_u16RemainingTime      = Local_u32Load % TIMER1_MAXIMUM_VALUE ;
					Global_u16RemainingTime = (TIMER1_MAXIMUM_VALUE - Global_u16RemainingTime);


					TIMER1->TCNT1H = (Global_u16RemainingTime >> 8) & 0xFF; // High byte
					TIMER1->TCNT1L = Global_u16RemainingTime & 0xFF;
	 				break;
			/*----------------------------------------------------------------------------------*/
			case TIME_US :
					/* Calculate Numbers of Ticks */
					Local_u32Load = Copy_u32Time * (TIMER1_CLK / 1000000) ;
					Global_u32Number_Of_Overflow = Local_u32Load / TIMER1_MAXIMUM_VALUE ;
					Global_u16RemainingTime      = Local_u32Load % TIMER1_MAXIMUM_VALUE ;
					Global_u16RemainingTime = (TIMER1_MAXIMUM_VALUE - Global_u16RemainingTime);


					TIMER1->TCNT1H = (Global_u16RemainingTime >> 8) & 0xFF; // High byte
					TIMER1->TCNT1L = Global_u16RemainingTime & 0xFF;
	 				break;
			/*----------------------------------------------------------------------------------*/
			default :
					break;
			/*----------------------------------------------------------------------------------*/
		}
	
	
	/* Set call back function */
	TIMER1_CallBack[0] = func ;
	
	/* Start Timer */
	M_TIMER1_voidStart();
	
	/* Enable Interrupt */
	M_TIMER1_voidInterrupt_Enable(TIMER1_OVERFLOW_INTERRUPT);

}
/*******************************************************************************/
void M_TIMER1_voidInterrupt_Enable(TIMER1_INT_t Copy_Interrupt_ID)
{
	if(Copy_Interrupt_ID == TIMER1_OUTPUT_COMPARE_MATCH_A_INTERRUPT)
	{
		SET_BIT( TIMER1->TIMSK , 4);
	}
	else if(Copy_Interrupt_ID == TIMER1_OUTPUT_COMPARE_MATCH_B_INTERRUPT)
	{
		SET_BIT( TIMER1->TIMSK , 3);
	}
	else if(Copy_Interrupt_ID == TIMER1_EVENT_INTERRUPT)
	{
		SET_BIT( TIMER1->TIMSK , 5);
	}
	else if(Copy_Interrupt_ID == TIMER1_OVERFLOW_INTERRUPT)
	{
		SET_BIT( TIMER1->TIMSK , 2);
	}
}
/*******************************************************************************/
void M_TIMER1_voidInterrupt_Disable(TIMER1_INT_t Copy_Interrupt_ID)
{
	if(Copy_Interrupt_ID == TIMER1_OUTPUT_COMPARE_MATCH_A_INTERRUPT)
	{
		CLR_BIT( TIMER1->TIMSK , 4);
	}
	else if(Copy_Interrupt_ID == TIMER1_OUTPUT_COMPARE_MATCH_B_INTERRUPT)
	{
		CLR_BIT( TIMER1->TIMSK , 3);
	}
	else if(Copy_Interrupt_ID == TIMER1_EVENT_INTERRUPT)
	{
		CLR_BIT( TIMER1->TIMSK , 5);
	}
	else if(Copy_Interrupt_ID == TIMER1_OVERFLOW_INTERRUPT)
	{
		CLR_BIT( TIMER1->TIMSK , 2);
	}
}
/*******************************************************************************/

void M_TIMER1_voidSetFastPWM(u8 Copy_u8DutyCycle,TIMER1_OC1_CHANNEL_t Copy_OC1Channel)
{
	#if ((TIMER1_MODE == TIMER1_FAST_PWM_8Bit)||(TIMER1_MODE == TIMER1_FAST_PWM_9Bit)||(TIMER1_MODE == TIMER1_FAST_PWM_10Bit)||(TIMER1_MODE == TIMER1_FAST_PWM_ICR1)||(TIMER1_MODE == TIMER1_FAST_PWM_OCR1A))
		u16 Local_u16DutyCycle = 0;
		#if TIMER1_MODE == TIMER1_FAST_PWM_8Bit
		u16 TIM_MAXIMUM_VALUE = 0xFF ;
		#elif TIMER1_MODE == TIMER1_FAST_PWM_9Bit
		u16 TIM_MAXIMUM_VALUE = 0x1FF ;
		#elif TIMER1_MODE == TIMER1_FAST_PWM_10Bit
		u16 TIM_MAXIMUM_VALUE = 0x3FF ;
		#elif TIMER1_MODE == TIMER1_FAST_PWM_OCR1A     // TODO:
		u16 TIM_MAXIMUM_VALUE = 0xFFFF ;
		#elif TIMER1_MODE == TIMER1_FAST_PWM_ICR1
		/*      For Only Frequncy [1KHz]        */     // TODO: Function for any frequncies
		u16 TIM_MAXIMUM_VALUE = 15999 ;
		TIMER1->ICR1H = (TIM_MAXIMUM_VALUE >> 8) & 0xFF; // High Byte
		TIMER1->ICR1L = TIM_MAXIMUM_VALUE & 0xFF;        // Low Byte
		#endif

		if (Copy_OC1Channel == TIMER1_OC1_CHANNEL_A)
		{
				#if TIMER1_COMPARE_MATCH_A_MODE == TIMER1_OC1_CHANNEL_A_CLEAR
					Local_u16DutyCycle = (u16)((u32)Copy_u8DutyCycle * TIM_MAXIMUM_VALUE / 100);
					TIMER1->OCR1AH = (Local_u16DutyCycle >> 8) & 0xFF; // High Byte
					TIMER1->OCR1AL = Local_u16DutyCycle & 0xFF;        // Low Byte
					/* Start Timer */
					M_TIMER1_voidStart();


				#elif TIMER1_COMPARE_MATCH_A_MODE == TIMER1_OC1_CHANNEL_A_SET
					Local_u16DutyCycle = (u16)((u32)Copy_u8DutyCycle * TIM_MAXIMUM_VALUE / 100);
					Local_u16DutyCycle = TIM_MAXIMUM_VALUE - Local_u16DutyCycle ;
					TIMER1->OCR1AH = (Local_u16DutyCycle >> 8) & 0xFF; // High Byte
					TIMER1->OCR1AL = Local_u16DutyCycle & 0xFF;        // Low Byte

					/* Start Timer */
					M_TIMER1_voidStart();
			#endif
		}
		else if (Copy_OC1Channel == TIMER1_OC1_CHANNEL_B)
		{
				#if TIMER1_COMPARE_MATCH_B_MODE == TIMER1_OC1_CHANNEL_B_CLEAR
					Local_u16DutyCycle = (u16)((u32)Copy_u8DutyCycle * TIM_MAXIMUM_VALUE / 100);
					TIMER1->OCR1BH = (Local_u16DutyCycle >> 8) & 0xFF; // High Byte
					TIMER1->OCR1BL = Local_u16DutyCycle & 0xFF;        // Low Byte
					/* Start Timer */
					M_TIMER1_voidStart();


				#elif TIMER1_COMPARE_MATCH_B_MODE == TIMER1_OC1_CHANNEL_B_SET
					Local_u16DutyCycle = (u16)((u32)Copy_u8DutyCycle * TIM_MAXIMUM_VALUE / 100);
					Local_u16DutyCycle = TIM_MAXIMUM_VALUE - Local_u16DutyCycle ;
					TIMER1->OCR1BH = (Local_u16DutyCycle >> 8) & 0xFF; // High Byte
					TIMER1->OCR1BL = Local_u16DutyCycle & 0xFF;        // Low Byte


					/* Start Timer */
					M_TIMER1_voidStart();

				#endif
		}

	#else
		#warning "[Fast PWM] is Disabled"
	#endif
}

void M_TIMER1_voidSetPhaseCorrectPWM(u8 Copy_u8DutyCycle,TIMER1_OC1_CHANNEL_t Copy_OC1Channel)
{
	#if ((TIMER1_MODE == TIMER1_PHASE_CORRECT_PWM_8Bit)||(TIMER1_MODE == TIMER1_PHASE_CORRECT_PWM_9Bit)||(TIMER1_MODE == TIMER1_PHASE_CORRECT_PWM_10Bit)||(TIMER1_MODE == TIMER1_PHASE_CORRECT_PWM_ICR1)||(TIMER1_MODE == TIMER1_PHASE_CORRECT_PWM_OCR1A))
		u16 Local_u16DutyCycle = 0;
		#if TIMER1_MODE == TIMER1_PHASE_CORRECT_PWM_8Bit
		u16 TIM_MAXIMUM_VALUE = 0xFF ;
		#elif TIMER1_MODE == TIMER1_PHASE_CORRECT_PWM_9Bit
		u16 TIM_MAXIMUM_VALUE = 0x1FF ;
		#elif TIMER1_MODE == TIMER1_PHASE_CORRECT_PWM_10Bit
		u16 TIM_MAXIMUM_VALUE = 0x3FF ;
		#elif TIMER1_MODE == TIMER1_PHASE_CORRECT_PWM_OCR1A     // TODO:
		u16 TIM_MAXIMUM_VALUE = 0xFFFF ;
		#elif TIMER1_MODE == TIMER1_PHASE_CORRECT_PWM_ICR1
		/*      For Only Frequncy [1KHz]        */     // TODO: Function for any frequncies
		u16 TIM_MAXIMUM_VALUE = 15999 ;
		TIMER1->ICR1H = (TIM_MAXIMUM_VALUE >> 8) & 0xFF; // High Byte
		TIMER1->ICR1L = TIM_MAXIMUM_VALUE & 0xFF;        // Low Byte
		#endif

		if (Copy_OC1Channel == TIMER1_OC1_CHANNEL_A)
		{
				#if TIMER1_COMPARE_MATCH_A_MODE == TIMER1_OC1_CHANNEL_A_CLEAR
					Local_u16DutyCycle = (u16)((u32)Copy_u8DutyCycle * TIM_MAXIMUM_VALUE / 100);
					TIMER1->OCR1AH = (Local_u16DutyCycle >> 8) & 0xFF; // High Byte
					TIMER1->OCR1AL = Local_u16DutyCycle & 0xFF;        // Low Byte
					/* Start Timer */
					M_TIMER1_voidStart();


				#elif TIMER1_COMPARE_MATCH_A_MODE == TIMER1_OC1_CHANNEL_A_SET
					Local_u16DutyCycle = (u16)((u32)Copy_u8DutyCycle * TIM_MAXIMUM_VALUE / 100);
					Local_u16DutyCycle = TIM_MAXIMUM_VALUE - Local_u16DutyCycle ;
					TIMER1->OCR1AH = (Local_u16DutyCycle >> 8) & 0xFF; // High Byte
					TIMER1->OCR1AL = Local_u16DutyCycle & 0xFF;        // Low Byte
					/* Start Timer */
					M_TIMER1_voidStart();

				#endif
		}
		else if (Copy_OC1Channel == TIMER1_OC1_CHANNEL_B)
		{
				#if TIMER1_COMPARE_MATCH_B_MODE == TIMER1_OC1_CHANNEL_B_CLEAR
					Local_u16DutyCycle = (u16)((u32)Copy_u8DutyCycle * TIM_MAXIMUM_VALUE / 100);
					TIMER1->OCR1BH = (Local_u16DutyCycle >> 8) & 0xFF; // High Byte
					TIMER1->OCR1BL = Local_u16DutyCycle & 0xFF;        // Low Byte
					/* Start Timer */
					M_TIMER1_voidStart();


				#elif TIMER1_COMPARE_MATCH_B_MODE == TIMER1_OC1_CHANNEL_B_SET
					Local_u16DutyCycle = (u16)((u32)Copy_u8DutyCycle * TIM_MAXIMUM_VALUE / 100);
					Local_u16DutyCycle = TIM_MAXIMUM_VALUE - Local_u16DutyCycle ;
					TIMER1->OCR1BH = (Local_u16DutyCycle >> 8) & 0xFF; // High Byte
					TIMER1->OCR1BL = Local_u16DutyCycle & 0xFF;        // Low Byte
					/* Start Timer */
					M_TIMER1_voidStart();

				#endif
		}
	#else
		#warning "[Phase Correct PWM] is Disabled"
	#endif
}

void M_TIMER1_voidICU_SetEventTrigger(TIMER1_EVENT_t Copy_CaptureEvent)
{
	if(Copy_CaptureEvent == TIMER1_FALLING_EDGE)
	{
		CLR_BIT(TIMER1->TCCR1B , TIMER1_ICES1_BIT);
	}
	else if(Copy_CaptureEvent == TIMER1_RAISING_EDGE)
	{
		SET_BIT(TIMER1->TCCR1B , TIMER1_ICES1_BIT);
	}
}


void M_TIMER1_voidICU_GetDutyCycle(u8 * Copy_ptrGetDutyCycle)
{

	TIM1_GLOBAL_FUN = TIMER1_INPUT_CAPTURE_UNIT_FUNCTION;
	#if TIMER1_ICU_NOISE_CANCELER == TIMER1_ICU_NOISE_CANCELER_ENABLE
		SET_BIT(TIMER1->TCCR1B , 7);
	#elif TIMER1_ICU_NOISE_CANCELER == TIMER1_ICU_NOISE_CANCELER_DISABLE
		CLR_BIT(TIMER1->TCCR1B , 7);
	#endif

	M_TIMER1_voidInterrupt_Enable(TIMER1_OVERFLOW_INTERRUPT);
	M_TIMER1_voidInterrupt_Enable(TIMER1_EVENT_INTERRUPT);
	/* Enable Rising Edge Trigger */
	M_TIMER1_voidICU_SetEventTrigger(TIMER1_RAISING_EDGE);

    // Start Timer1
    M_TIMER1_voidStart();

	// Wait for the first edge to capture [First Reading]
	while (GET_BIT(TIMER1->TIFR, 5) == 0);
	Global_u32Number_Of_Overflow_CaptureUnit = 0;

	// Capture the initial count [First Reading]
    u16 Local_u16StartCaptureValue = ((TIMER1->ICR1H << 8) | (TIMER1->ICR1L));
    u16 Local_u16SecondCaptureValue   = 0;
    /* Clear the TCNT1 to calculate number of overflows */
    TIMER1->TCNT1H = 0; // Clear the counter
    TIMER1->TCNT1L = 0;

    // Wait for the next edge to capture  [Second Reading]
	while (GET_BIT(TIMER1->TIFR, 5) == 0);

	// Capture the final count [Second Reading]
    Local_u16SecondCaptureValue = ((TIMER1->ICR1H << 8) | (TIMER1->ICR1L));

    /* Calculate Number of overflows between [First Reading] and [Second Reading] */
    u16 Local_NumberOVF = Global_u32Number_Of_Overflow_CaptureUnit;
    u32 Local_u32Period = 0;

    /* IF there is no Overflow */
    if(Local_NumberOVF == 0)
    {
    	// Calculate the duty cycle based on the captured values  ([Second Reading] - [First Reading])
    	 Local_u32Period  = Local_u16SecondCaptureValue - Local_u16StartCaptureValue;
    }
    else
    {
    	// Calculate the duty cycle based on the captured values
    	 Local_u32Period  = (Local_NumberOVF * TIMER1_MAXIMUM_VALUE) + Local_u16SecondCaptureValue;
    }
	/* Enable Falling Edge Trigger */
	M_TIMER1_voidICU_SetEventTrigger(TIMER1_FALLING_EDGE);
    /* Clear the TCNT1 to calculate number of overflows */
    TIMER1->TCNT1H = 0; // Clear the counter
    TIMER1->TCNT1L = 0;
    Global_u32Number_Of_Overflow_CaptureUnit = 0;
    // Wait for the next edge to capture  [End Reading]
	while (GET_BIT(TIMER1->TIFR, 5) == 0);
	Local_NumberOVF = Global_u32Number_Of_Overflow_CaptureUnit;

	// Capture the Final count [End Reading]
    u16 Local_u16EndCaptureValue = ((TIMER1->ICR1H << 8) | (TIMER1->ICR1L));

    u32 Local_u32Time_ON = 0;
    /* IF there is no Overflow */
    if(Local_NumberOVF == 0)
    {
       Local_u32Time_ON = Local_u16EndCaptureValue - Local_u16SecondCaptureValue;
    }
    else
    {
        Local_u32Time_ON = (Local_NumberOVF * TIMER1_MAXIMUM_VALUE) + Local_u16SecondCaptureValue;
    }

    // Calculate duty cycle as a percentage
    u8 Local_u8DutyCycle = ((u8)((Local_u32Time_ON/ Local_u32Period))) * 100 ;

    *Copy_ptrGetDutyCycle = Local_u8DutyCycle;

    // Clear the input capture flag
    SET_BIT(TIMER1->TIFR, 5);

	M_TIMER1_voidInterrupt_Disable(TIMER1_OVERFLOW_INTERRUPT);
	M_TIMER1_voidInterrupt_Disable(TIMER1_EVENT_INTERRUPT);

	M_TIMER1_voidStop();
	TIM1_GLOBAL_FUN = TIMER1_NO_OPERATION;

}


/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/* Timer/Counter1 Capture Event */
TIMER1_Capture_Event_IRQHandler
{
//	TIMER1_CallBack[3]();
	static u32 Timer_Capture_Event_Overflow_counter = 0;
	Timer_Capture_Event_Overflow_counter++;

}

/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/* Timer/Counter1 Compare Match A */
TIMER1_COMPARE_MATCH_A_IRQHandler
{
//	TIMER1_CallBack[1]();
}
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/* Timer/Counter1 Compare Match B */
TIMER1_COMPARE_MATCH_B_IRQHandler
{
//	TIMER1_CallBack[2]();
}

/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/* Timer/Counter1 Overflow ISR */
TIMER1_OVERFLOW_IRQHandler
{
	/*******************************************************************************/
	if(	TIM1_GLOBAL_FUN == TIMER1_PERIODIC_INTERRUPT_FUNCTION)
	{
		static u32 Timer_Overflow_counter = 0;
		Timer_Overflow_counter++;
		if(Timer_Overflow_counter == Global_u32Number_Of_Overflow+1)
		{

			TIMER1_CallBack[0]();
			Timer_Overflow_counter = 0 ;
			TIMER1->TCNT1H = (Global_u16RemainingTime >> 8) & 0xFF; // High byte
			TIMER1->TCNT1L = Global_u16RemainingTime & 0xFF;
		}
	}
	/*******************************************************************************/
	else if (TIM1_GLOBAL_FUN == TIMER1_BUSY_WAIT_FUNCTION)
	{
		static u32 Timer_Overflow_counter = 0;
		Timer_Overflow_counter++;
		if(Timer_Overflow_counter == Global_u32Number_Of_Overflow+1)
		{

			Timer_Overflow_counter = 0 ;
			TIM1_GLOBAL_FUN = TIMER1_NO_OPERATION ;

		}
		else if(Global_u32Number_Of_Overflow == 0)
		{
			TIM1_GLOBAL_FUN = TIMER1_NO_OPERATION ;
		}
	}
	/*******************************************************************************/
	else if (TIM1_GLOBAL_FUN == TIMER1_INPUT_CAPTURE_UNIT_FUNCTION)
	{
		Global_u32Number_Of_Overflow_CaptureUnit++;
	}
}
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/


