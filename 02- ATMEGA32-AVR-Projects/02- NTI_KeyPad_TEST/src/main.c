/****************************************************************************/
/* Author      : Mohamed Maged                                              */
/* Version     : V01                                                        */
/* Date        : 20 October 2023                                            */
/* Description : main.c                                                     */
/****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "../inc/STD_TYPES.h"
#include "../inc/BIT_MATH.h"

#include "../inc/DIO_interface.h"
#include "../inc/SevenSegment_interface.h"
#include "../inc/keypad_interface.h"

#include  <avr/delay.h>

int main()
{
	SevenSegment_Init();
	KeyPad_Init();

	u16 SevenSegment_Number = 0;
	while(1)
	{
		SevenSegment_Number = KeyPad_u8GetKey();
		for(u16 i = 0 ;i < 150; i++)
		{
//			SevenSegment_voidDisplay_ALL(SevenSegment_Number);
			SevenSegment_voidDisplay(SevenSegment_Number,0);
		}
	}
	return 0;
}
