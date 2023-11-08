/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 22 October 2023                                               */
/*   Logs      : V01 : Initial Creation                                        */
/*******************************************************************************/

#ifndef  EXTI_PRIVATE_H
#define  EXTI_PRIVATE_H



typedef struct{

	volatile u8 MCUCSR      ;
	volatile u8 MCUCR       ;
	volatile u8 RESERVED[4] ;
	volatile u8 GIFR        ;
	volatile u8 GICR        ;


}EXTI_t;

#define EXTI_BASE_ADDRESS 			0x54
#define EXTI ((volatile EXTI_t *) EXTI_BASE_ADDRESS)


/*************************************************************/
#define EXTI0_IRQHandler            \
	void __vector_1(void) __attribute__ ((signal)); \
	void __vector_1(void)
/*************************************************************/
#define EXTI1_IRQHandler            \
	void __vector_2(void) __attribute__ ((signal)); \
	void __vector_2(void)
/*************************************************************/
#define EXTI2_IRQHandler            \
	void __vector_3(void) __attribute__ ((signal)); \
	void __vector_3(void)
/*************************************************************/

#endif
