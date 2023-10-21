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

#include <avr/delay.h>

int main()
{
	SevenSegment_Init();
	u16 SevenSegment_Number = 0;

	while(1)
	{
		for(u16 i = 0 ;i < 150; i++)
		{
			SevenSegment_voidDisplay_ALL(SevenSegment_Number);
		}
		SevenSegment_Number++;
		if(SevenSegment_Number == 9999)
		{
			SevenSegment_Number = 0;
		}
	}
	return 0;
}
