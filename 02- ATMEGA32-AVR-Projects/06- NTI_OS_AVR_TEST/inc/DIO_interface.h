/****************************************************************************/
/* Author      : Mohamed Maged                                              */
/* Version     : V01                                                        */
/* Date        : 20 October 2023                                            */
/* Description : DIO_interface.h                                            */
/****************************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
/****************************************************************************/
#define DIO       ((volatile DIO_t *)DIO_BASE_ADDRESS)
typedef enum
{
	PORT_A  ,
	PORT_B  ,
	PORT_C  ,
	PORT_D
}PORT_t;

typedef enum
{
	PIN_0  ,
	PIN_1  ,
	PIN_2  ,
	PIN_3  ,
	PIN_4  ,
	PIN_5  ,
	PIN_6  ,
	PIN_7
}PIN_t;

typedef enum
{
	INPUT  ,
	OUTPUT
}DIRECTION_t;


typedef enum
{
	LOW   ,
	HIGH
}VALUE_t;
/****************************************************************************/
void DIO_voidSetPinDirection(PORT_t Copy_PortId,PIN_t Copy_PinId,DIRECTION_t Copy_Direction);
void DIO_voidSetPinValue(PORT_t Copy_PortId,PIN_t Copy_PinId,VALUE_t Copy_Value);
u8 DIO_voidGetPinValue(PORT_t Copy_PortId,PIN_t Copy_PinId);
void DIO_voidSetPortirection(PORT_t Copy_PortId,DIRECTION_t Copy_Direction);
void DIO_voidSetPortValue(PORT_t Copy_PortId,VALUE_t Copy_Value);
u8 DIO_voidGetPortValue(PORT_t Copy_PortId);
/****************************************************************************/

#endif /* DIO_INTERFACE_H_ */
