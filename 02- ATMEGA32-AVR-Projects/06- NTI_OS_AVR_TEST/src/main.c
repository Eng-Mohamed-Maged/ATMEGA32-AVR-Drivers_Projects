/****************************************************************************/
/* Author      : Mohamed Maged                                              */
/* Version     : V01                                                        */
/* Date        : 20 October 2023                                            */
/* Description : main.c                                                     */
/****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
/****************************************************************************/
#include "../inc/STD_TYPES.h"
#include "../inc/BIT_MATH.h"
/****************************************************************************/
#include "../inc/DIO_interface.h"
#include "../inc/TIMER0_interface.h"
#include "../inc/GIE_interface.h"
#include "../inc/OS_interface.h"
#include "../inc/EXTI_interface.h"
/****************************************************************************/
void Task_1_RED(void);
void Task_2_GREEN(void);
void Task_3_BLUE(void);
void Task_4_YELLOW(void);
/****************************************************************************/
void EXTI_INT1_PUSH_BUTTON(void)
{
	static u8 Local_u8PB_State = 0 ;
	Local_u8PB_State ^= 1 ;
	if(Local_u8PB_State == 0)
	{
		/*Suspend Task-1 , ID = 0 */
		OS_voidSuspendTask(0);
	}
	else if(Local_u8PB_State == 1)
	{
		/*Resume Task-1 , ID = 0 */
		OS_voidResumeTask(0);
	}
}
/****************************************************************************/
int main()
{

	/* Initialize Timer 0 */
	M_TIMER0_voidInit();

	/* INT1 => PORT_D,PIN_3 INPUT PULLUP */
	DIO_voidSetPinDirection(PORT_D,PIN_3,INPUT);
	DIO_voidSetPinValue(PORT_D,PIN_3,HIGH);

	/* Red LED */
	DIO_voidSetPinDirection(PORT_B,PIN_7,OUTPUT);
	/* Green LED */
	DIO_voidSetPinDirection(PORT_A,PIN_4,OUTPUT);
	/* Blue LED */
	DIO_voidSetPinDirection(PORT_A,PIN_5,OUTPUT);
	/* Yellow LED */
	DIO_voidSetPinDirection(PORT_A,PIN_6,OUTPUT);


	/* CallBack for INT1  */
	MEXTI_voidSetCallBack(MEXTI_INT1,EXTI_INT1_PUSH_BUTTON);


	MEXTI_voidSetSignalLatch(MEXTI_INT1,MEXTI_RISING_EDGE);

	/* Enable INT1  */
	MEXTI_voidEnableEXTI(MEXTI_INT1);

	/* Create Task */
	// TaskID = 0 , TaskFirstDelay = 0 , TaskPeriodicity = 1000 , TaskHandler = Task_1 //
	OS_voidCreateTask(0,1000,Task_1_RED,0);

	// TaskID = 1 , TaskFirstDelay = 1 , TaskPeriodicity = 2000 , TaskHandler = Task_2 //
	OS_voidCreateTask(1000,2000,Task_2_GREEN,1);

	// TaskID = 2 , TaskFirstDelay = 2 , TaskPeriodicity = 4000 , TaskHandler = Task_3 //
	OS_voidCreateTask(2000,3000,Task_3_BLUE,2);

	// TaskID = 3 , TaskFirstDelay = 2 , TaskPeriodicity = 4000 , TaskHandler = Task_3 //
	OS_voidCreateTask(3000,4000,Task_4_YELLOW,3);

	/* Start the Scheduler  */
	OS_voidStartScheduler();


	/* ENABLE GLOBAL INTERRUPT */
	MGIE_voidEnable();

	while(1)
	{



	}
	return 0;
}
/****************************************************************************/
void Task_1_RED(void)
{
	static u8 Local_u8Toggle1 = 0 ;
	Local_u8Toggle1 ^= 1 ;
	DIO_voidSetPinValue(PORT_B,PIN_7,Local_u8Toggle1);
}
/****************************************************************************/
void Task_2_GREEN(void)
{
	static u8 Local_u8Toggle2 = 0 ;
	Local_u8Toggle2 ^= 1 ;
	DIO_voidSetPinValue(PORT_A,PIN_4,Local_u8Toggle2);
}
/****************************************************************************/
void Task_3_BLUE(void)
{
	static u8 Local_u8Toggle3 = 0 ;
	Local_u8Toggle3 ^= 1 ;
	DIO_voidSetPinValue(PORT_A,PIN_5,Local_u8Toggle3);
}
/****************************************************************************/
void Task_4_YELLOW(void)
{
	static u8 Local_u8Toggle4 = 0 ;
	Local_u8Toggle4 ^= 1 ;
	DIO_voidSetPinValue(PORT_A,PIN_6,Local_u8Toggle4);
}
/****************************************************************************/

