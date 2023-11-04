/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V02                                                           */
/*   Date      : 4 November 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*               V02 : Adding New Features                                     */
/*******************************************************************************/
#ifndef	RTC_PRIVATE_H
#define RTC_PRIVATE_H
/****************************************************************************/

typedef struct
{
	volatile u8 SECONDS ;
	volatile u8 MINUTES ;
	volatile u8 HOURS   ;
	volatile u8 DAY     ;
	volatile u8 DATE    ;
	volatile u8 MONTH   ;
	volatile u8 YEAR    ;
	volatile u8 CONTROL ;
	volatile u8 RAM[56] ;
}RTC_t;

/****************************************************************************/
#define  RTC_SECONDS              0x0
#define  RTC_MINUTES              0x1
#define  RTC_HOURS                0x2
#define  RTC_DAY                  0x3
#define  RTC_DATE                 0x4
#define  RTC_MONTH                0x5
#define  RTC_YEAR                 0x6
#define  RTC_CONTROL              0x7
#define  RTC_RAM                  0x8


/****************************************************************************/
#define  RTC_WRITE_ADDRESS        0b11010000      
#define  RTC_READ_ADDRESS         0b11010001      
/****************************************************************************/
#define  RTC_BIT0                 0
#define  RTC_BIT1                 1
#define  RTC_BIT2                 2
#define  RTC_BIT3                 3
#define  RTC_BIT4                 4
#define  RTC_BIT5                 5
#define  RTC_BIT6                 6
#define  RTC_BIT7                 7
/*******************************************************************************/
#define  RTC_HIGH                 1
#define  RTC_LOW                  0
#define  RTC_ERROR                5
/*******************************************************************************/
/*                            Private Function                                 */
/*******************************************************************************/
u8 RTC_voidConvertDecimalToBCD(u8 Copy_u8Decimal);
u8 RTC_u8ConvertBCDToDecimal(u8 Copy_u8BCD);
/*******************************************************************************/
I2C_STATUS_t H_RTC_WriteByte(u16 Copy_u16Address, u8 Copy_u8SendData);
I2C_STATUS_t H_RTC_ReadByte(u16 Copy_u16Address, u8 * Copy_u8RecievedData);
/*******************************************************************************/





#endif
