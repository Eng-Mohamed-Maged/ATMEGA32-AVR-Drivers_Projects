/*******************************************************************************/
/* Author    : Mohamed Maged                                                   */
/* Version   : V01                                                             */
/* Date      : 8 November 2023         	                                       */
/* Logs      : V01 : Initial Creation                                          */
/*******************************************************************************/
/* Library Includes */
#include "../inc/STD_TYPES.h"
#include "../inc/BIT_MATH.h"
/*******************************************************************************/
/* MCAL Includes */
#include "../inc/TIMER0_interface.h"
/*******************************************************************************/
/* MODULE Includes */
#include "../inc/OS_interface.h"
#include "../inc/OS_config.h"
#include "../inc/OS_private.h"
/*******************************************************************************/

/* Array of Tasks  (Array of Structure) */
OS_TASK_t Global_Tasks[OS_NUMBER_OF_TASKS] = {} ;

/*******************************************************************************/
/* - Initialize OS and start the Scheduler                                     */
/*******************************************************************************/
void OS_voidStartScheduler(void)
{
	/* Initialize Timer 0 */
	M_TIMER0_voidInit();
	
	/* Setup the scheduler Tick Time */
	M_TIMER0_voidSetPeriodic(OS_TICK_TIME_UNIT,voidScheduler);
}

/*******************************************************************************/
/* - To Create new task  										               */
/*******************************************************************************/
void OS_voidCreateTask(u16 Copy_u16delay,u16 Copy_u16period,void(*Copy_voidFptr)(void),u8 Copy_u8ID)
{
	/* assign task parameters to the right array index */
	if (Copy_u8ID < OS_NUMBER_OF_TASKS)
	{
		Global_Tasks[Copy_u8ID].FirstDelay       = Copy_u16delay    ;
		Global_Tasks[Copy_u8ID].Priodicity 		 = Copy_u16period   ;
		Global_Tasks[Copy_u8ID].Fptr   		     = Copy_voidFptr    ;
		Global_Tasks[Copy_u8ID].Task_state       = OS_TASK_READY    ;
	}
	else 
	{
		/* Return ERROR */
	}
}


/*******************************************************************************/
/* - To put the task in Suspend state 										   */
/*******************************************************************************/
void OS_voidSuspendTask(u8 Copy_u8ID)
{
	if (Global_Tasks[Copy_u8ID].Fptr != NULL)
	{
		Global_Tasks[Copy_u8ID].Task_state  = OS_TASK_SUSPEND    ;
	}
	else
	{
		/* Return ERROR */
	}
}


/*******************************************************************************/
/* - To put the task in Ready state 										   */
/*******************************************************************************/
void OS_voidResumeTask(u8 Copy_u8ID)
{
	if (Global_Tasks[Copy_u8ID].Fptr != NULL)
	{
		Global_Tasks[Copy_u8ID].Task_state  = OS_TASK_READY    ;
	}
	else
	{
		/* Return ERROR */
	}
}

/*******************************************************************************/
/* - To delete the task in Suspend state 									   */
/*******************************************************************************/
void OS_voidDeleteTask(u8 Copy_u8ID)
{
	if (Global_Tasks[Copy_u8ID].Fptr != NULL)
	{
		Global_Tasks[Copy_u8ID].FirstDelay       = 0    			;
		Global_Tasks[Copy_u8ID].Fptr   		     = NULL    			;
		Global_Tasks[Copy_u8ID].Priodicity 		 = 0   				;

	}
	else 
	{
		/* Return ERROR */
	}
}



/*******************************************************************************/
/****************************** Private Functions ******************************/
static void voidScheduler(void)
{
/***************************  Co-operative scheduling  *************************/
	for (u8 i = 0; i < OS_NUMBER_OF_TASKS ; i++)
	{
		if ( (Global_Tasks[i].Fptr != NULL) && (Global_Tasks[i].Task_state == OS_TASK_READY) )
		{
			/* Time of the task has come */
			if ( Global_Tasks[i].FirstDelay == 0)
			{
					Global_Tasks[i].FirstDelay = Global_Tasks[i].Priodicity - OS_TICK_TIME ;
					Global_Tasks[i].Fptr();
			}
			else
			{
				Global_Tasks[i].FirstDelay -= OS_TICK_TIME ;
			}
		}
		else
		{
			/* Return ERROR */
		}
	}
}
