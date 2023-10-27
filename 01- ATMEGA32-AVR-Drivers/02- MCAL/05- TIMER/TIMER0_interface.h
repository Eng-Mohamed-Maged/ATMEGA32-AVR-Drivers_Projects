/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 26 October 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*******************************************************************************/
#ifndef TIMER0_INTERFACE_H
#define	TIMER0_INTERFACE_H
/*************************************************************************************************************/
typedef enum{
	TIME_S  ,
	TIME_MS ,
	TIME_US
}TIMER0_TIME_t;


typedef enum{
	TIMER0_OUTPUT_COMPARE_MATCH_INTERRUPT  ,
	TIMER0_OVERFLOW_INTERRUPT 
}TIMER0_INT_t;


typedef enum{
	TIMER0_BUSY_WAIT_FUNCTION  			,
	TIMER0_PERIODIC_INTERRUPT_FUNCTION  ,
	TIMER0_NO_OPERATION
}TIMER0_GLOBAL_t;





void M_TIMER0_voidInit(void);
void M_TIMER0_voidStart(void);
void M_TIMER0_voidStop(void);
void M_TIMER0_voidSetBusyWait(u32 Copy_u32Time, TIMER0_TIME_t Copy_timeUnit);
void M_TIMER0_voidSetPeriodic(u32 Copy_u32Time, TIMER0_TIME_t Copy_timeUnit, void (*func)(void));
void M_TIMER0_voidInterrupt_Enable(TIMER0_INT_t Copy_Interrupt_ID);
void M_TIMER0_voidInterrupt_Disable(TIMER0_INT_t Copy_Interrupt_ID);
void M_TIMER0_voidSetFastPWM(u8 Copy_u8DutyCycle);
void M_TIMER0_voidSetPhaseCorrectPWM(u8 Copy_u8DutyCycle);



#endif
