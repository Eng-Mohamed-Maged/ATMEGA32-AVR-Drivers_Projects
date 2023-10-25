/****************************************************************************/
/* Author      : Mohamed Maged                                              */
/* Version     : V01                                                        */
/* Date        : 20 October 2023                                            */
/* Description : main.c                                                     */
/****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define F_CPU 16000000UL
#include "util/delay.h"

#include "../inc/STD_TYPES.h"
#include "../inc/BIT_MATH.h"

#include "../inc/DIO_interface.h"
#include "../inc/LCD_interface.h"
#include "../inc/ADC_interface.h"
/****************************************************************************/
u8 Arabic_Name[][8] =
{
 {0b00000000,0b00000000,0b00000000,0b000011100,0b00000100,0b00011111,0b00000000,0b00000000},
 {0b00000000,0b00000000,0b00000000,0b00001100,0b00000010,0b00011111,0b00000000,0b00000100},
 {0b00001000,0b00001000,0b00001000,0b00001000,0b00001000,0b00001111,0b00000000,0b00000000},
 {0b00000000,0b00000000,0b00000000,0b00000111,0b00000101,0b00011111,0b00000000,0b00000000},
 {0b00000000,0b00000000,0b00000000,0b000011100,0b00000100,0b00011111,0b00000000,0b00000000},
 {0b00000000,0b00000000,0b00000000,0b00001110,0b00001010,0b00011111,0b00000000,0b00000000},
 {0b00000000,0b00000000,0b00000000,0b000001100,0b00000010,0b00011111,0b00000000,0b00000000},
 {0b00000000,0b00000000,0b00000000,0b00000111,0b00000101,0b00011111,0b00000000,0b00000000}
};
/****************************************************************************/
int main()
{
	f32 ADC_Volatge;
	u16 ADC_DATA;
	/****************************************************************************/
	DIO_voidSetPinDirection(PORT_A,PIN_5,OUTPUT);
	H_LCD_void_Init();
	MADC_Init(ADC_AVCC		                 ,
			  ADC_RIGHT_ADJUST                ,
			  ADC_AUTO_TRIGGER_OFF           ,
			  ADC_PRESCALER_DIVID_128);

	/****************************************************************************/
	// Create the custom Arabic Name at position k in CGRAM
	for(u8 k = 0; k<8 ;k++)
	{
	     H_LCD_void_creatCustomChar(Arabic_Name[k], k);
	}
	/****************************************************************************/

	H_LCD_void_sendString("  <<< ");

	for(u8 k = 0; k<8 ;k++)
	{
		if(k == 4)
		{
			H_LCD_void_sendData(' ');
		}
	    // Display the custom character
		H_LCD_void_displayCustomChar(k);
	}

	H_LCD_void_sendString(" >>>");

	/****************************************************************************/
	H_LCD_void_gotoXY(1,0);
	H_LCD_void_sendString("Testing ADC [ LDR ]");
	H_LCD_void_gotoXY(2,0);
	H_LCD_void_sendString("VREF = 2V");
	H_LCD_void_gotoXY(3,0);
	H_LCD_void_sendString("DIG:");
	H_LCD_void_gotoXY(3,9);
	H_LCD_void_sendString("Analog:");
	while(1)
	{
		MADC_getDigitalValueSynchNonBlocking(ADC_CHANNEL_4,&ADC_DATA);
		ADC_Volatge = ((f32)ADC_DATA / 1023.0) * 2.0 ;
		H_LCD_void_gotoXY(3,4);
		H_LCD_void_sendIntNum(ADC_DATA);
		H_LCD_void_gotoXY(3,16);
		H_LCD_void_sendFloat(ADC_Volatge,2);

		if(ADC_DATA > 600)
		{
			DIO_voidSetPinValue(PORT_A,PIN_5,HIGH);
			H_LCD_void_gotoXY(2,12);
			H_LCD_void_sendString("LED ON ");
		}
		else if(ADC_DATA < 600)
		{
			DIO_voidSetPinValue(PORT_A,PIN_5,LOW);
			H_LCD_void_gotoXY(2,12);
			H_LCD_void_sendString("LED OFF");

		}

		_delay_ms(800);
		H_LCD_void_gotoXY(3,4);
		H_LCD_void_sendString("    ");
		H_LCD_void_gotoXY(3,16);
		H_LCD_void_sendString("    ");

	}
	return 0;
}
