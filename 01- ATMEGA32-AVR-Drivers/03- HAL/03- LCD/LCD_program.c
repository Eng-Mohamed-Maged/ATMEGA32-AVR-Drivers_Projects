/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 23 October 2023                                               */
/*   Logs      : V01 : Initial Creation                                        */
/*******************************************************************************/
#include "../inc/STD_TYPES.h"
#include "../inc/BIT_MATH.h"

#define F_CPU 16000000UL
#include "util/delay.h"

#include "../inc/DIO_interface.h"

#include "../inc/LCD_interface.h"
#include "../inc/LCD_private.h"
#include "../inc/LCD_config.h"

u8 LCD_PORTS_PINS[22]= {
					LCD_RS_PORT_PIN ,        // 0
					LCD_RW_PORT_PIN ,
					LCD_EN_PORT_PIN ,        // 5
					LCD_D0_PORT_PIN ,        // 6
                    LCD_D1_PORT_PIN	,
                    LCD_D2_PORT_PIN	,
                    LCD_D3_PORT_PIN	, 
                    LCD_D4_PORT_PIN	,        // 14
                    LCD_D5_PORT_PIN	,
                    LCD_D6_PORT_PIN	,
                    LCD_D7_PORT_PIN	         // 21
				};
				
 
 
void H_LCD_void_Init(void)
 {
	/* SET Direction as OUTPUT for RS,RW,EN */
	for(u8 i = 0; i< 6 ; i+=2)
	{
		DIO_voidSetPinDirection(LCD_PORTS_PINS[i],LCD_PORTS_PINS[i+1],OUTPUT);
	}	 
	
	#if	 LCD_MODE == MODE_8BIT
		for(u8 i = 6; i<22;i+=2)
		{
			DIO_voidSetPinDirection(LCD_PORTS_PINS[i],LCD_PORTS_PINS[i+1],OUTPUT);
		}
		// LCD Initialization
		_delay_ms(50);
		
		// Function Set
		#if LCD_FONT == FONT_5X7
			H_LCD_void_sendCommand(0b00111000);
		#elif LCD_FONT == FONT_5X10
			H_LCD_void_sendCommand(0b00111100);
		#endif

		// Wait the Instruction
		_delay_ms(2);
		
		// Display ON-OFF Controll => ON
		H_LCD_void_sendCommand(0b00001100);		
		_delay_ms(2);
		
		//Display Clear
		H_LCD_void_sendCommand(LCD_CLEAR);		
		_delay_ms(3);
		
		//Entry Mode Set  >> I/D=1 & S=0
		H_LCD_void_sendCommand(0b00000110);



	#elif LCD_MODE == MODE_4BIT
	 	for(u8 i = 14; i<22;i+=2)
		{
			DIO_voidSetPinDirection(LCD_PORTS_PINS[i],LCD_PORTS_PINS[i+1],OUTPUT);
		}
		
		
		// LCD Initialization
		_delay_ms(50);

		// Function Set
		H_LCD_void_sendCommand(0b00110011);
		H_LCD_void_sendCommand(0b00110010);

		#if LCD_FONT == FONT_5X7
			#if   LCD_LINE == ONE_LINE
				H_LCD_void_sendCommand(0b00100011);
			#elif LCD_LINE == TWO_LINE
				H_LCD_void_sendCommand(0b00101011);
			#elif LCD_LINE == FOUR_LINE
				H_LCD_void_sendCommand(0b00101011);
			#endif
		#elif LCD_FONT == FONT_5X10
			H_LCD_void_sendCommand(0b00100111);
		#endif

		// Display ON-OFF Controll => ON
		H_LCD_void_sendCommand(0b00001100);

		//Display Clear
		H_LCD_void_sendCommand(0b00000001);
		
		_delay_ms(1);
		
		//Entry Mode Set  >> I/D=1 & S=0
		H_LCD_void_sendCommand(0b00000110);


	#endif
	
 }
	 
	 

	 
void H_LCD_void_sendData(u8 copy_u8data )
{
	// Write Data => RS = 1
	DIO_voidSetPinValue(LCD_RS_PORT_PIN,HIGH);


	// Send Data to Latch Function
	H_LCD_void_latchByte(copy_u8data);

}

void H_LCD_void_sendCommand(u8 copy_u8command)
{
	// Write Instruction => RS = 0
	DIO_voidSetPinValue(LCD_RS_PORT_PIN,LOW);
	

	// Send Data to Latch Function
	H_LCD_void_latchByte(copy_u8command);

}


void H_LCD_void_sendString(const s8 *pstr) {
    u8 i = 0;
    u8 line = 0;

    while (pstr[i] != '\0')
    {
        H_LCD_void_sendData(pstr[i]);
        i++;

        if (i % (LCD_COLUMNS) == 0)
        {
            // New line after every `LCD_COLUMNS` characters
        	H_LCD_void_gotoXY(++line,0);
			_delay_ms(1);
        }

    }
}


void H_LCD_void_ShiftString(const s8 *pstr, u8 copy_u8lineNumber)
{
	static u8 i = 0 ;
	static u8 j = 0 ;

    if (copy_u8lineNumber < LCD_ROW)
    {
         u8 strLen = 0;
         // Calculate the string length manually
         while (pstr[strLen] != '\0')
         {
             strLen++;
         }

        if (i >= (LCD_COLUMNS-strLen-j))
        {
            i = 0;  // Start from the beginning when reaching the end
            H_LCD_void_clearLine(copy_u8lineNumber);
        }
        H_LCD_void_gotoXY(copy_u8lineNumber,i++);
        for(j = 0 ; j < i ;j++)
        {
        	H_LCD_void_sendData(' ');
        }
        H_LCD_void_sendString(pstr);
    }
}




void H_LCD_void_clearLine(u8 copy_u8lineNumber)
{
    if (copy_u8lineNumber < LCD_ROW)
    {
        H_LCD_void_gotoXY(copy_u8lineNumber, 0);  // Move to the beginning of the line
        for (u8 i = 0; i < LCD_COLUMNS; i++)
        {
            H_LCD_void_sendData(' ');  // Send space character to clear the line
        }
        H_LCD_void_gotoXY(copy_u8lineNumber, 0);  // Move to the beginning of the line
    }
}



void H_LCD_void_gotoXY(u8 copy_u8Row, u8 copy_u8Col)
{
	// Row offsets for a 4x20 LCD
    u8 row_offsets[] = {0x00, 0x40, 0x14, 0x54};
    H_LCD_void_sendCommand(0x80 | (row_offsets[copy_u8Row] + copy_u8Col));
}


void H_LCD_void_sendIntNum(s32 copy_s32Num)
{
		// Buffer to store the digits as characters
	    s8 buffer[12];  // Assuming a 32-bit number, which can have up to 11 digits

	    // Check for negative numbers
	    if (copy_s32Num < 0)
	    {
	        H_LCD_void_sendData('-');  // Display a minus sign for negative numbers
	        copy_s32Num = -copy_s32Num;  // Make the number positive for processing
	    }

	    // Handle the case of a number being zero
	    if (copy_s32Num == 0) {
	        H_LCD_void_sendData('0');
	        return;
	    }

	    // Convert the number to a string in reverse order
	    u8 index = 0;
	    while (copy_s32Num > 0)
	    {
	        buffer[index++] = '0' + (copy_s32Num % 10);  // Convert the digit to a character
	        copy_s32Num /= 10;  // Remove the last digit
	    }

	    // Send the string to the LCD in reverse order
	    for (s8 i = index - 1; i >= 0; i--)
	    {
	        H_LCD_void_sendData(buffer[i]);
	    }
	}



void H_LCD_void_creatCustomChar(const u8 *ArrPattern, u8 copy_u8charCode)
{
    // Set CGRAM address to write the custom character (0 to 7)
    H_LCD_void_sendCommand(0x40 | (copy_u8charCode << 3));

    // Send the custom character pattern data
    for (u8 i = 0; i < 8; i++)
    {
        H_LCD_void_sendData(ArrPattern[i]);
    }
    // Return to the DDRAM address
    H_LCD_void_sendCommand(0x80);
}

void H_LCD_void_displayCustomChar(u8 copy_u8charCode)
{
    // Send the custom character using its character code (0 to 7)
    H_LCD_void_sendData(copy_u8charCode);
}




/*******************************************************************************/
/*************************    Private Function      ****************************/
/*******************************************************************************/

static void H_LCD_void_latchByte(u8 copy_u8Byte)
{	 
	DIO_voidSetPinValue(LCD_EN_PORT_PIN,LOW);


	#if	 LCD_MODE == MODE_8BIT
		for(u8 i = 6; i<22;i+=2)
		{
			DIO_voidSetPinValue(LCD_PORTS_PINS[i],LCD_PORTS_PINS[i+1],GET_BIT(copy_u8Byte,((i-6)/2)));
		}

		// Falling Edge
		// Set Enable
		DIO_voidSetPinValue(LCD_EN_PORT_PIN,HIGH);
		_delay_ms(1);
		// Reset Enable
		DIO_voidSetPinValue(LCD_EN_PORT_PIN,LOW);
		_delay_ms(5);

	#elif LCD_MODE == MODE_4BIT

		for(u8 i = 20; i>12;i-=2)
		{
			DIO_voidSetPinValue(LCD_PORTS_PINS[i],LCD_PORTS_PINS[i+1],GET_BIT(copy_u8Byte,((i-6)/2)));
		}

		// Falling Edge
		// Set Enable
		DIO_voidSetPinValue(LCD_EN_PORT_PIN,HIGH);
		_delay_ms(1);
		// Reset Enable
		DIO_voidSetPinValue(LCD_EN_PORT_PIN,LOW);
		_delay_ms(5);


		for(u8 i = 20; i>12;i-=2)
		{
			DIO_voidSetPinValue(LCD_PORTS_PINS[i],LCD_PORTS_PINS[i+1],GET_BIT(copy_u8Byte,((i-14)/2)));
		}

		// Falling Edge
		// Set Enable
		DIO_voidSetPinValue(LCD_EN_PORT_PIN,HIGH);
		_delay_ms(1);
		// Reset Enable
		DIO_voidSetPinValue(LCD_EN_PORT_PIN,LOW);
		_delay_ms(5);

	#endif

}	
