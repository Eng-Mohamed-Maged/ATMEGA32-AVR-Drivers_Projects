/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 28 October 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*******************************************************************************/
#ifndef TIMER2_INTERFACE_H
#define	TIMER2_INTERFACE_H
/*************************************************************************************************************/
typedef enum{
	TIME_S  ,
	TIME_MS ,
	TIME_US
}TIMER2_TIME_t;


typedef enum{
	TIMER2_OUTPUT_COMPARE_MATCH_INTERRUPT  ,
	TIMER2_OVERFLOW_INTERRUPT 
}TIMER2_INT_t;


typedef enum{
	TIMER2_BUSY_WAIT_FUNCTION  			,
	TIMER2_PERIODIC_INTERRUPT_FUNCTION  ,
	TIMER2_NO_OPERATION
}TIMER2_GLOBAL_t;





void M_TIMER2_voidInit(void);
void M_TIMER2_voidStart(void);
void M_TIMER2_voidStop(void);
void M_TIMER2_voidSetBusyWait(u32 Copy_u32Time, TIMER2_TIME_t Copy_timeUnit);
void M_TIMER2_voidSetPeriodic(u32 Copy_u32Time, TIMER2_TIME_t Copy_timeUnit, void (*func)(void));
void M_TIMER2_voidInterrupt_Enable(TIMER2_INT_t Copy_Interrupt_ID);
void M_TIMER2_voidInterrupt_Disable(TIMER2_INT_t Copy_Interrupt_ID);
void M_TIMER2_voidSetFastPWM(u8 Copy_u8DutyCycle);
void M_TIMER2_voidSetPhaseCorrectPWM(u8 Copy_u8DutyCycle);



#endif
