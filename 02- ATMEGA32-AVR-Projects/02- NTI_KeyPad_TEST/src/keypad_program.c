/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 21 October 2023                                               */
/*   Logs      : V01 : Initial Creation                                        */
/*******************************************************************************/
#include "../inc/STD_TYPES.h"
#include "../inc/BIT_MATH.h"

#include "../inc/DIO_interface.h"

#include "../inc/keypad_interface.h"
#include "../inc/keypad_private.h"
#include "../inc/keypad_config.h"

u8 Col_Arr[8]= {
					KeyPad_PIN_C1,
					KeyPad_PIN_C2,
					KeyPad_PIN_C3,
					KeyPad_PIN_C4
				};
				
u8 Row_Arr[8]= {	KeyPad_PIN_R1,
					KeyPad_PIN_R2,
					KeyPad_PIN_R3,
					KeyPad_PIN_R4
				};
				
				
void KeyPad_Init(void)
{
		/* SET Rows as Input */
		DIO_voidSetPinDirection(KeyPad_PIN_R4,INPUT);
		DIO_voidSetPinDirection(KeyPad_PIN_R3,INPUT);
		DIO_voidSetPinDirection(KeyPad_PIN_R2,INPUT);
		DIO_voidSetPinDirection(KeyPad_PIN_R1,INPUT);

		DIO_voidSetPinValue(KeyPad_PIN_R4,HIGH);
		DIO_voidSetPinValue(KeyPad_PIN_R3,HIGH);
		DIO_voidSetPinValue(KeyPad_PIN_R2,HIGH);
		DIO_voidSetPinValue(KeyPad_PIN_R1,HIGH);

		/* Set Cols as Output */
		DIO_voidSetPinDirection(KeyPad_PIN_C1,OUTPUT);
		DIO_voidSetPinDirection(KeyPad_PIN_C2,OUTPUT);
		DIO_voidSetPinDirection(KeyPad_PIN_C3,OUTPUT);
		DIO_voidSetPinDirection(KeyPad_PIN_C4,OUTPUT);

		/* Set Col = 1 */
		DIO_voidSetPinValue(KeyPad_PIN_C1,HIGH);
		DIO_voidSetPinValue(KeyPad_PIN_C2,HIGH);
		DIO_voidSetPinValue(KeyPad_PIN_C3,HIGH);
		DIO_voidSetPinValue(KeyPad_PIN_C4,HIGH);
		
}



u8 KeyPad_u8GetKey(void)
{
	volatile static u8 Localu8PressedKey = 0;
	u8 Col,Row;
	for(Col=0;Col<8;Col+=2)
	{
		/* Activate Col */
		DIO_voidSetPinValue(Col_Arr[Col],Col_Arr[Col+1],LOW);
		for(Row=0 ; Row<8 ; Row+=2)
		{
			if(DIO_voidGetPinValue(Row_Arr[Row],Row_Arr[Row+1]) == 0)
			{
				/* Key is pressed */
				Localu8PressedKey = (Row*4 + Col)/2;
				while(DIO_voidGetPinValue(Row_Arr[Row],Row_Arr[Row+1]) == 0);
				return Localu8PressedKey ;// or break;
			}
			else
			{
				/* Switch is not pressed */
			}
		}
		DIO_voidSetPinValue(Col_Arr[Col],Col_Arr[Col+1],HIGH);
	}
	return Localu8PressedKey;
}
