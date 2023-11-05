/****************************************************************************/
/* Author      : Mohamed Maged                                              */
/* Version     : V01                                                        */
/* Date        : 20 October 2023                                            */
/* Description : main.c                                                     */
/****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
/****************************************************************************/
#define F_CPU 16000000UL
#include "util/delay.h"
/****************************************************************************/
#include "../inc/STD_TYPES.h"
#include "../inc/BIT_MATH.h"
/****************************************************************************/
#include "../inc/DIO_interface.h"
#include "../inc/LCD_interface.h"
#include "../inc/I2C_interface.h"
#include "../inc/GIE_interface.h"
#include "../inc/RTC_interface.h"
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
u8 Global_u8Hours;
u8 Global_u8Minutes;
u8 Global_u8Seconds;
u8 Global_u8AM_PM;
/****************************************************************************/
u8 Global_u8Day;
u8 Global_u8Date;
u8 Global_u8Month;
u8 Global_u8Year;
/****************************************************************************/
int main()
{
//	MGIE_voidEnable();

	H_LCD_void_Init();
	H_RTC_voidInit(RTC_CLK_SPEED_100K);

	H_RTC_SetTime(11,59,55,RTC_TIME_PM,RTC_HOUR_12);
//	/* MY  [BIRTHDAY]   */
	H_RTC_SetDate(RTC_FRI,25,12,97);

/****************************************************************************************************/
/*                                          MY ARABIC NAME                                          */
/****************************************************************************************************/

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

	H_LCD_void_sendString(" >>>  ");

/****************************************************************************************************/




	H_LCD_void_gotoXY(1,0);
	H_LCD_void_sendString("TIME: ");
	H_LCD_void_gotoXY(2,0);
	H_LCD_void_sendString("DATE: ");
	H_LCD_void_gotoXY(3,0);
	H_LCD_void_sendString("DAY : ");

	while(1)
	{
		H_RTC_GetTime(&Global_u8Hours ,&Global_u8Minutes,&Global_u8Seconds,&Global_u8AM_PM);
		H_RTC_GetDate(&Global_u8Date  ,&Global_u8Month  ,&Global_u8Year,&Global_u8Day);
		H_LCD_void_gotoXY(1,7);
		H_LCD_void_send2DigitNum(Global_u8Hours);
		H_LCD_void_sendString("::");
		H_LCD_void_send2DigitNum(Global_u8Minutes);
		H_LCD_void_sendString("::");
		H_LCD_void_send2DigitNum(Global_u8Seconds);

		if(Global_u8AM_PM == RTC_TIME_AM)
		{
			H_LCD_void_sendString(" AM");
		}
		else if(Global_u8AM_PM == RTC_TIME_PM)
		{
			H_LCD_void_sendString(" PM");
		}

		H_LCD_void_gotoXY(2,7);
		H_LCD_void_send2DigitNum(Global_u8Date);
		H_LCD_void_sendString("/ ");
		H_LCD_void_send2DigitNum(Global_u8Month);
		H_LCD_void_sendString(" /");
		H_LCD_void_send2DigitNum(Global_u8Year);

		H_LCD_void_gotoXY(3,7);
		switch(Global_u8Day)
		{
			case RTC_SAT : H_LCD_void_sendString("Saturday ")  ;      break;
			case RTC_SUN : H_LCD_void_sendString("Sunday   ")  ;      break;
			case RTC_MON : H_LCD_void_sendString("Monday   ")  ;      break;
			case RTC_TUE : H_LCD_void_sendString("Tuesday  ")  ;      break;
			case RTC_WED : H_LCD_void_sendString("Wednesday")  ;      break;
			case RTC_THU : H_LCD_void_sendString("Thursday ")  ;      break;
			case RTC_FRI : H_LCD_void_sendString("Friday   ")  ;      break;
			default      : break;
		}

	}
	return 0;
}
