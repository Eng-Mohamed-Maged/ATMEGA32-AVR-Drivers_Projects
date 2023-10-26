/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V02                                                           */
/*   Date      : 26 October 2023                                               */
/*   Logs      : V01 : Initial Creation                                        */
/*               V02 : Adding Trigger Mode and Get ADC_Data Function           */
/*******************************************************************************/

#ifndef  ADC_PRIVATE_H
#define  ADC_PRIVATE_H



typedef struct{

	volatile u8  ADCL		  ;
	volatile u8  ADCH		  ;
	volatile u8  ADCSRA 	  ;
	volatile u8  ADMUX        ;
	volatile u8  RESERVED[41] ;
	volatile u8  SFIOR        ;


}ADC_t;


#define ADC_BASE_ADDRESS 			0x24
#define ADC ((volatile ADC_t *) ADC_BASE_ADDRESS)


/*************************************************************/
#define ADC_IRQHandler            \
	void __vector_16(void) __attribute__ ((signal)); \
	void __vector_16(void)
/*************************************************************/

#define   ADLAR_BIT        5
#define   ADATE_BIT        5
#define   ADEN_BIT         7
#define   ADIE_BIT         3
#define   ADSC_BIT         6

#define  NULL          ((void*)0)


#endif
