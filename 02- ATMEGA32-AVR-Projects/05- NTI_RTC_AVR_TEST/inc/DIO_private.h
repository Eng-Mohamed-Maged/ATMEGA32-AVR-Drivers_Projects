/****************************************************************************/
/* Author      : Mohamed Maged                                              */
/* Version     : V01                                                        */
/* Date        : 20 October 2023                                            */
/* Description : DIO_private.h                                              */
/****************************************************************************/

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

typedef union
{
	volatile u8 All_Bits;
    struct
    {
		volatile u8 B0 : 1;
		volatile u8 B1 : 1;
		volatile u8 B2 : 1;
		volatile u8 B3 : 1;
		volatile u8 B4 : 1;
		volatile u8 B5 : 1;
		volatile u8 B6 : 1;
		volatile u8 B7 : 1;

    }Bit;
}Reg;


typedef struct
{
	volatile Reg PIND	;
	volatile Reg DDRD	;
	volatile Reg PORTD	;
	volatile Reg PINC	;
	volatile Reg DDRC	;
	volatile Reg PORTC	;
	volatile Reg PINB	;
	volatile Reg DDRB	;
	volatile Reg PORTB	;
	volatile Reg PINA	;
	volatile Reg DDRA	;
	volatile Reg PORTA	;
}DIO_t;




#endif  /* DIO_PRIVATE_H_ */
