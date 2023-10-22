/****************************************************************************/
/* Author      : Mohamed Maged                                              */
/* Version     : V01                                                        */
/* Date        : 20 October 2023                                            */
/* Description : DIO_program.c                                              */
/****************************************************************************/
#include "../inc/STD_TYPES.h"
#include "../inc/BIT_MATH.h"

#include "../inc/DIO_config.h"
#include "../inc/DIO_interface.h"
#include "../inc/DIO_private.h"

void DIO_voidSetPinDirection(PORT_t Copy_PortId,PIN_t Copy_PinId,DIRECTION_t Copy_Direction)
{
	switch(Copy_PortId)
	{
		case PORT_A:
			switch(Copy_PinId)
			{
				case PIN_0 :
						DIO->DDRA.Bit.B0 = Copy_Direction;
						break;
				case PIN_1 :
						DIO->DDRA.Bit.B1 = Copy_Direction;
						break;
				case PIN_2 :
						DIO->DDRA.Bit.B2 = Copy_Direction;
						break;
				case PIN_3 :
						DIO->DDRA.Bit.B3 = Copy_Direction;
						break;
				case PIN_4 :
						DIO->DDRA.Bit.B4 = Copy_Direction;
						break;
				case PIN_5 :
						DIO->DDRA.Bit.B5 = Copy_Direction;
						break;
				case PIN_6 :
						DIO->DDRA.Bit.B6 = Copy_Direction;
						break;
				case PIN_7 :
						DIO->DDRA.Bit.B7 = Copy_Direction;
						break;
				default: break;
			}
			break;

		case PORT_B:
			switch(Copy_PinId)
			{
				case PIN_0 :
						DIO->DDRB.Bit.B0 = Copy_Direction;
						break;
				case PIN_1 :
						DIO->DDRB.Bit.B1 = Copy_Direction;
						break;
				case PIN_2 :
						DIO->DDRB.Bit.B2 = Copy_Direction;
						break;
				case PIN_3 :
						DIO->DDRB.Bit.B3 = Copy_Direction;
						break;
				case PIN_4 :
						DIO->DDRB.Bit.B4 = Copy_Direction;
						break;
				case PIN_5 :
						DIO->DDRB.Bit.B5 = Copy_Direction;
						break;
				case PIN_6 :
						DIO->DDRB.Bit.B6 = Copy_Direction;
						break;
				case PIN_7 :
						DIO->DDRB.Bit.B7 = Copy_Direction;
						break;
				default: break;
			}
			break;


		case PORT_C:
			switch(Copy_PinId)
			{
				case PIN_0 :
						DIO->DDRC.Bit.B0 = Copy_Direction;
						break;
				case PIN_1 :
						DIO->DDRC.Bit.B1 = Copy_Direction;
						break;
				case PIN_2 :
						DIO->DDRC.Bit.B2 = Copy_Direction;
						break;
				case PIN_3 :
						DIO->DDRC.Bit.B3 = Copy_Direction;
						break;
				case PIN_4 :
						DIO->DDRC.Bit.B4 = Copy_Direction;
						break;
				case PIN_5 :
						DIO->DDRC.Bit.B5 = Copy_Direction;
						break;
				case PIN_6 :
						DIO->DDRC.Bit.B6 = Copy_Direction;
						break;
				case PIN_7 :
						DIO->DDRC.Bit.B7 = Copy_Direction;
						break;
				default: break;
			}
			break;

		case PORT_D:
			switch(Copy_PinId)
			{
				case PIN_0 :
						DIO->DDRD.Bit.B0 = Copy_Direction;
						break;
				case PIN_1 :
						DIO->DDRD.Bit.B1 = Copy_Direction;
						break;
				case PIN_2 :
						DIO->DDRD.Bit.B2 = Copy_Direction;
						break;
				case PIN_3 :
						DIO->DDRD.Bit.B3 = Copy_Direction;
						break;
				case PIN_4 :
						DIO->DDRD.Bit.B4 = Copy_Direction;
						break;
				case PIN_5 :
						DIO->DDRD.Bit.B5 = Copy_Direction;
						break;
				case PIN_6 :
						DIO->DDRD.Bit.B6 = Copy_Direction;
						break;
				case PIN_7 :
						DIO->DDRD.Bit.B7 = Copy_Direction;
						break;
				default: break;
			}
			break;
	}
}




void DIO_voidSetPinValue(PORT_t Copy_PortId,PIN_t Copy_PinId,VALUE_t Copy_Value)
{
	switch(Copy_PortId)
	{
		case PORT_A:
			switch(Copy_PinId)
			{
				case PIN_0 :
						DIO->PORTA.Bit.B0 = Copy_Value;
						break;
				case PIN_1 :
						DIO->PORTA.Bit.B1 = Copy_Value;
						break;
				case PIN_2 :
						DIO->PORTA.Bit.B2 = Copy_Value;
						break;
				case PIN_3 :
						DIO->PORTA.Bit.B3 = Copy_Value;
						break;
				case PIN_4 :
						DIO->PORTA.Bit.B4 = Copy_Value;
						break;
				case PIN_5 :
						DIO->PORTA.Bit.B5 = Copy_Value;
						break;
				case PIN_6 :
						DIO->PORTA.Bit.B6 = Copy_Value;
						break;
				case PIN_7 :
						DIO->PORTA.Bit.B7 = Copy_Value;
						break;
				default: break;
			}
			break;

		case PORT_B:
			switch(Copy_PinId)
			{
				case PIN_0 :
						DIO->PORTB.Bit.B0 = Copy_Value;
						break;
				case PIN_1 :
						DIO->PORTB.Bit.B1 = Copy_Value;
						break;
				case PIN_2 :
						DIO->PORTB.Bit.B2 = Copy_Value;
						break;
				case PIN_3 :
						DIO->PORTB.Bit.B3 = Copy_Value;
						break;
				case PIN_4 :
						DIO->PORTB.Bit.B4 = Copy_Value;
						break;
				case PIN_5 :
						DIO->PORTB.Bit.B5 = Copy_Value;
						break;
				case PIN_6 :
						DIO->PORTB.Bit.B6 = Copy_Value;
						break;
				case PIN_7 :
						DIO->PORTB.Bit.B7 = Copy_Value;
						break;
				default: break;
			}
			break;


		case PORT_C:
			switch(Copy_PinId)
			{
				case PIN_0 :
						DIO->PORTC.Bit.B0 = Copy_Value;
						break;
				case PIN_1 :
						DIO->PORTC.Bit.B1 = Copy_Value;
						break;
				case PIN_2 :
						DIO->PORTC.Bit.B2 = Copy_Value;
						break;
				case PIN_3 :
						DIO->PORTC.Bit.B3 = Copy_Value;
						break;
				case PIN_4 :
						DIO->PORTC.Bit.B4 = Copy_Value;
						break;
				case PIN_5 :
						DIO->PORTC.Bit.B5 = Copy_Value;
						break;
				case PIN_6 :
						DIO->PORTC.Bit.B6 = Copy_Value;
						break;
				case PIN_7 :
						DIO->PORTC.Bit.B7 = Copy_Value;
						break;
				default: break;
			}
			break;

		case PORT_D:
			switch(Copy_PinId)
			{
				case PIN_0 :
						DIO->PORTD.Bit.B0 = Copy_Value;
						break;
				case PIN_1 :
						DIO->PORTD.Bit.B1 = Copy_Value;
						break;
				case PIN_2 :
						DIO->PORTD.Bit.B2 = Copy_Value;
						break;
				case PIN_3 :
						DIO->PORTD.Bit.B3 = Copy_Value;
						break;
				case PIN_4 :
						DIO->PORTD.Bit.B4 = Copy_Value;
						break;
				case PIN_5 :
						DIO->PORTD.Bit.B5 = Copy_Value;
						break;
				case PIN_6 :
						DIO->PORTD.Bit.B6 = Copy_Value;
						break;
				case PIN_7 :
						DIO->PORTD.Bit.B7 = Copy_Value;
						break;
				default: break;
			}
			break;
	}
}

u8 DIO_voidGetPinValue(PORT_t Copy_PortId,PIN_t Copy_PinId)
{
	u8 Local_u8Pin;
	switch(Copy_PortId)
	{
		case PORT_A:
			switch(Copy_PinId)
			{
				case PIN_0 :
						Local_u8Pin = DIO->PINA.Bit.B0;
						break;
				case PIN_1 :
						Local_u8Pin = DIO->PINA.Bit.B1;
						break;
				case PIN_2 :
						Local_u8Pin = DIO->PINA.Bit.B2;
						break;
				case PIN_3 :
						Local_u8Pin = DIO->PINA.Bit.B3;
						break;
				case PIN_4 :
						Local_u8Pin = DIO->PINA.Bit.B4;
						break;
				case PIN_5 :
						Local_u8Pin = DIO->PINA.Bit.B5;
						break;
				case PIN_6 :
						Local_u8Pin = DIO->PINA.Bit.B6;
						break;
				case PIN_7 :
						Local_u8Pin = DIO->PINA.Bit.B7;
						break;
				default: break;
			}
			break;

		case PORT_B:
			switch(Copy_PinId)
			{
				case PIN_0 :
						Local_u8Pin = DIO->PINB.Bit.B0;
						break;
				case PIN_1 :
						Local_u8Pin = DIO->PINB.Bit.B1;
						break;
				case PIN_2 :
						Local_u8Pin = DIO->PINB.Bit.B2;
						break;
				case PIN_3 :
						Local_u8Pin = DIO->PINB.Bit.B3;
						break;
				case PIN_4 :
						Local_u8Pin = DIO->PINB.Bit.B4;
						break;
				case PIN_5 :
						Local_u8Pin = DIO->PINB.Bit.B5;
						break;
				case PIN_6 :
						Local_u8Pin = DIO->PINB.Bit.B6;
						break;
				case PIN_7 :
						Local_u8Pin = DIO->PINB.Bit.B7;
						break;
				default: break;
			}
			break;


		case PORT_C:
			switch(Copy_PinId)
			{
				case PIN_0 :
						Local_u8Pin = DIO->PINC.Bit.B0;
						break;
				case PIN_1 :
						Local_u8Pin = DIO->PINC.Bit.B1;
						break;
				case PIN_2 :
						Local_u8Pin = DIO->PINC.Bit.B2;
						break;
				case PIN_3 :
						Local_u8Pin = DIO->PINC.Bit.B3;
						break;
				case PIN_4 :
						Local_u8Pin = DIO->PINC.Bit.B4;
						break;
				case PIN_5 :
						Local_u8Pin = DIO->PINC.Bit.B5;
						break;
				case PIN_6 :
						Local_u8Pin = DIO->PINC.Bit.B6;
						break;
				case PIN_7 :
						Local_u8Pin = DIO->PINC.Bit.B7;
						break;
				default: break;
			}
			break;

		case PORT_D:
			switch(Copy_PinId)
			{
				case PIN_0 :
						Local_u8Pin = DIO->PIND.Bit.B0;
						break;
				case PIN_1 :
						Local_u8Pin = DIO->PIND.Bit.B1;
						break;
				case PIN_2 :
						Local_u8Pin = DIO->PIND.Bit.B2;
						break;
				case PIN_3 :
						Local_u8Pin = DIO->PIND.Bit.B3;
						break;
				case PIN_4 :
						Local_u8Pin = DIO->PIND.Bit.B4;
						break;
				case PIN_5 :
						Local_u8Pin = DIO->PIND.Bit.B5;
						break;
				case PIN_6 :
						Local_u8Pin = DIO->PIND.Bit.B6;
						break;
				case PIN_7 :
						Local_u8Pin = DIO->PIND.Bit.B7;
						break;
				default: break;
			}
			break;
	}
	return Local_u8Pin;
}

void DIO_voidSetPortirection(PORT_t Copy_PortId,DIRECTION_t Copy_Direction)
{
	switch(Copy_PortId)
		{
			case PORT_A:
				if(Copy_Direction == INPUT)
				{
					DIO->DDRA.All_Bits = 0;
				}
				else if(Copy_Direction == OUTPUT)
				{
					DIO->DDRA.All_Bits = 0xFF;

				}
				break;

			case PORT_B:
				if(Copy_Direction == INPUT)
				{
					DIO->DDRB.All_Bits = 0;
				}
				else if(Copy_Direction == OUTPUT)
				{
					DIO->DDRB.All_Bits = 0xFF;

				}
				break;


			case PORT_C:
				if(Copy_Direction == INPUT)
				{
					DIO->DDRC.All_Bits = 0;
				}
				else if(Copy_Direction == OUTPUT)
				{
					DIO->DDRC.All_Bits = 0xFF;

				}
				break;

			case PORT_D:
				if(Copy_Direction == INPUT)
				{
					DIO->DDRD.All_Bits = 0;
				}
				else if(Copy_Direction == OUTPUT)
				{
					DIO->DDRD.All_Bits = 0xFF;

				}
				break;
		}
}
void DIO_voidSetPortValue(PORT_t Copy_PortId,VALUE_t Copy_Value)
{
	switch(Copy_PortId)
		{
			case PORT_A:
				if(Copy_Value == HIGH)
				{
					DIO->PORTA.All_Bits = 0xFF;
				}
				else if(Copy_Value == LOW)
				{
					DIO->PORTA.All_Bits = 0;

				}
				break;

			case PORT_B:
				if(Copy_Value == HIGH)
				{
					DIO->PORTB.All_Bits = 0xFF;
				}
				else if(Copy_Value == LOW)
				{
					DIO->PORTB.All_Bits = 0;

				}
				break;


			case PORT_C:
				if(Copy_Value == HIGH)
				{
					DIO->PORTC.All_Bits = 0xFF;
				}
				else if(Copy_Value == LOW)
				{
					DIO->PORTC.All_Bits = 0;

				}
				break;

			case PORT_D:
				if(Copy_Value == HIGH)
				{
					DIO->PORTD.All_Bits = 0xFF;
				}
				else if(Copy_Value == LOW)
				{
					DIO->PORTD.All_Bits = 0;

				}
				break;
		}
}
u8 DIO_voidGetPortValue(PORT_t Copy_PortId)
{
	u8 Local_u8Pin;
	switch(Copy_PortId)
	{
		case PORT_A:
			Local_u8Pin = DIO->PINA.All_Bits;
		break;
		case PORT_B:
			Local_u8Pin = DIO->PINB.All_Bits;
		break;
		case PORT_C:
			Local_u8Pin = DIO->PINC.All_Bits;

		break;
		case PORT_D:
			Local_u8Pin = DIO->PIND.All_Bits;
		break;
		default: break;
	}
	return Local_u8Pin;
}
