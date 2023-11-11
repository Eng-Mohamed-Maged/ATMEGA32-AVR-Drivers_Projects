/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V04                                                           */
/*   Date      : 11 November 2023                                              */
/*   Logs      : V01 : Initial creation                                        */
/*               V02 : Fast PWM and Phase Correct PWM are fixed                */
/*               V03 : Adding ICU Feature to Calculate :                       */
/*                     [Duty Cycle] in % - [Time ON/OFF] in US                 */
/*               V04 : Adding New function to get Time On for single Pulse     */
/*******************************************************************************/
#ifndef TIMER1_INTERFACE_H
#define	TIMER1_INTERFACE_H
/*************************************************************************************************************/
typedef enum{
	TIME_S  ,
	TIME_MS ,
	TIME_US
}TIMER1_TIME_t;
/*************************************************************************************************************/
typedef enum{
	TIMER1_OUTPUT_COMPARE_MATCH_A_INTERRUPT  ,
	TIMER1_OUTPUT_COMPARE_MATCH_B_INTERRUPT  ,
	TIMER1_EVENT_INTERRUPT                   ,
	TIMER1_OVERFLOW_INTERRUPT                
}TIMER1_INT_t;
/*************************************************************************************************************/
typedef enum{
	TIMER1_BUSY_WAIT_FUNCTION  			,
	TIMER1_PERIODIC_INTERRUPT_FUNCTION  ,
	TIMER1_INPUT_CAPTURE_UNIT_FUNCTION  ,
	TIMER1_NO_OPERATION
}TIMER1_GLOBAL_t;
/*************************************************************************************************************/
typedef enum{
	TIMER1_FALLING_EDGE  			,
	TIMER1_RAISING_EDGE
}TIMER1_EVENT_t;
/*************************************************************************************************************/
typedef enum{
	TIMER1_OC1_CHANNEL_A 			,
	TIMER1_OC1_CHANNEL_B
}TIMER1_OC1_CHANNEL_t;
/*************************************************************************************************************/
void M_TIMER1_voidInit(void);
void M_TIMER1_voidStart(void);
void M_TIMER1_voidStop(void);
void M_TIMER1_voidSetBusyWait(u32 Copy_u32Time, TIMER1_TIME_t Copy_timeUnit);
void M_TIMER1_voidSetPeriodic(u32 Copy_u32Time, TIMER1_TIME_t Copy_timeUnit, void (*func)(void));
void M_TIMER1_voidInterrupt_Enable(TIMER1_INT_t Copy_Interrupt_ID);
void M_TIMER1_voidInterrupt_Disable(TIMER1_INT_t Copy_Interrupt_ID);
void M_TIMER1_voidSetFastPWM(u8 Copy_u8DutyCycle,TIMER1_OC1_CHANNEL_t Copy_OC1Channel);
void M_TIMER1_voidSetPhaseCorrectPWM(u8 Copy_u8DutyCycle,TIMER1_OC1_CHANNEL_t Copy_OC1Channel);
void M_TIMER1_voidICU_SetEventTrigger(TIMER1_EVENT_t Copy_CaptureEvent);
void M_TIMER1_voidICU_GetDutyCycle(u8 * Copy_ptrGetDutyCycle,u32 * Copy_ptrTimeOn_US,u32 * Copy_ptrTimeOff_US);
void M_TIMER1_voidICU_GetTimeOn_us(u32 * Copy_ptrTimeOn_US);
/*************************************************************************************************************/


#endif
