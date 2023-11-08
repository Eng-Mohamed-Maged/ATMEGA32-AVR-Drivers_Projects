/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 22 October 2023                                               */
/*   Logs      : V01 : Initial Creation                                        */
/*******************************************************************************/
#ifndef  EXTI_INTERFACE_H
#define  EXTI_INTERFACE_H

/* Enum for External Interrupt Modes */
typedef enum
{
	MEXTI_LOW_LEVEL    = 0 ,
	MEXTI_ANY_CHANGE       ,
	MEXTI_FALLING_EDGE     ,
	MEXTI_RISING_EDGE 
}MEXTI_MODE_t;
	
/* Enum for External Interrupt IDs*/
typedef enum
{
	MEXTI_INT0    =  0   ,
	MEXTI_INT1           ,
	MEXTI_INT2           ,
}MEXTI_IDs_t;




/****************  Functions Decleration  ******************/


void MEXTI_voidSetSignalLatch(MEXTI_IDs_t Copy_EXTI_ID , MEXTI_MODE_t Copy_EXTIMode);

void MEXTI_voidEnableEXTI(MEXTI_IDs_t Copy_EXTI_ID);

void MEXTI_voidDisableEXTI(MEXTI_IDs_t Copy_EXTI_ID);


/************  CallBack Functions Declerations  *************/

void MEXTI_voidSetCallBack(MEXTI_IDs_t Copy_EXTI_ID ,void (*ptr)(void)) ;






#endif
