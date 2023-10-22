/****************************************************************************/
/* Author      : Mohamed Maged                                              */
/* Version     : V01                                                        */
/* Date        : 20 October 2023                                            */
/* Description : main.c                                                     */
/****************************************************************************/
#include  <stdio.h>
#include  <stdlib.h>

#include "../inc/STD_TYPES.h"
#include "../inc/BIT_MATH.h"

#include "../inc/DIO_interface.h"
#include "../inc/GIE_interface.h"
#include "../inc/EXTI_interface.h"

u8 Toggle_Led;
void MAGED (void);

int main()
{
	/* Enable Global Interrupt */
	MGIE_voidEnable();

	/* Green LED */
	DIO_voidSetPinDirection(PORT_A,PIN_4,OUTPUT);

	/* ANY CHANGE */
	MEXTI_voidSetSignalLatch(MEXTI_INT1,MEXTI_ANY_CHANGE);

	MEXTI_voidSetCallBack(MEXTI_INT1,MAGED);

	/* Enable Interrupt 1 */
	MEXTI_voidEnableEXTI(MEXTI_INT1);

	while(1)
	{

	}
	return 0;
}

void MAGED (void)
{
	Toggle_Led ^= 1;
	DIO_voidSetPinValue(PORT_A,PIN_4,Toggle_Led);
}
