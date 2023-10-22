/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 22 October 2023                                               */
/*   Logs      : V01 : Initial Creation                                        */
/*******************************************************************************/

#include  "../inc/STD_TYPES.h"
#include  "../inc/BIT_MATH.h"

#include "../inc/EXTI_interface.h"
#include "../inc/EXTI_private.h"
#include "../inc/EXTI_config.h"

void (* EXTI_CallBack[3])(void) ={'\0'} ;

void MEXTI_voidSetSignalLatch(MEXTI_IDs_t Copy_EXTI_ID , MEXTI_MODE_t Copy_EXTIMode)
{
	switch(Copy_EXTI_ID)
	{
		case MEXTI_INT0:
			switch (Copy_EXTIMode)
			{
				case MEXTI_LOW_LEVEL  :
					CLR_BIT( EXTI->MCUCR , 0);
					CLR_BIT( EXTI->MCUCR , 1);
					break;
				case MEXTI_ANY_CHANGE :
					SET_BIT( EXTI->MCUCR , 0);
					CLR_BIT( EXTI->MCUCR , 1);
					break;
				case MEXTI_FALLING_EDGE    :
					CLR_BIT( EXTI->MCUCR , 0);
					SET_BIT( EXTI->MCUCR , 1);
					break;
				case MEXTI_RISING_EDGE    :
					SET_BIT( EXTI->MCUCR , 0);
					SET_BIT( EXTI->MCUCR , 1);
					break;
				default: break;
			}
			break;
		case MEXTI_INT1:
			switch (Copy_EXTIMode)
			{
				case MEXTI_LOW_LEVEL  :
					CLR_BIT( EXTI->MCUCR , 2);
					CLR_BIT( EXTI->MCUCR , 3);
					break;
				case MEXTI_ANY_CHANGE :
					SET_BIT( EXTI->MCUCR , 2);
					CLR_BIT( EXTI->MCUCR , 3);
					break;
				case MEXTI_FALLING_EDGE    :
					CLR_BIT( EXTI->MCUCR , 2);
					SET_BIT( EXTI->MCUCR , 3);
					break;
				case MEXTI_RISING_EDGE    :
					SET_BIT( EXTI->MCUCR , 2);
					SET_BIT( EXTI->MCUCR , 3);
					break;
				default: break;

			}
			break;
		case MEXTI_INT2:
			switch (Copy_EXTIMode)
			{
				case MEXTI_FALLING_EDGE    :
					CLR_BIT( EXTI->MCUCSR , 6);
					break;
				case MEXTI_RISING_EDGE    :
					SET_BIT( EXTI->MCUCSR , 6);
					break;
				default: break;
			}
			break;
		default: break;

	}

}




void MEXTI_voidEnableEXTI(MEXTI_IDs_t Copy_EXTI_ID)
{
	switch(Copy_EXTI_ID)
	{
		case MEXTI_INT0 :
					SET_BIT( EXTI->GICR , 6);
					break;
					
		case MEXTI_INT1 :
					SET_BIT( EXTI->GICR , 7);
					break;	
					
		case MEXTI_INT2 :
					SET_BIT( EXTI->GICR , 5);
					break;
					
		default: break;
	}
}





void MEXTI_voidDisableEXTI(MEXTI_IDs_t Copy_EXTI_ID)
{	
	switch(Copy_EXTI_ID)
	{
		case MEXTI_INT0 :
					CLR_BIT( EXTI->GICR , 6);
					break;
					
		case MEXTI_INT1 :
					CLR_BIT( EXTI->GICR , 7);
					break;	
					
		case MEXTI_INT2 :
					CLR_BIT( EXTI->GICR , 5);
					break;
					
		default: break;
	}

}



void MEXTI_voidSetCallBack(MEXTI_IDs_t Copy_EXTI_ID ,void (*ptr)(void))
{
	EXTI_CallBack[Copy_EXTI_ID] = ptr;

}


/*************************  INT 0 ***************************/
EXTI0_IRQHandler
{
	EXTI_CallBack[0]();

}

/*************************  INT 1 ***************************/
EXTI1_IRQHandler
{
	EXTI_CallBack[1]();
}
/*************************  INT 2 ***************************/
EXTI2_IRQHandler
{
	EXTI_CallBack[2]();

}

