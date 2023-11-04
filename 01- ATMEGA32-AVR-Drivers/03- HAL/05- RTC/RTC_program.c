/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V02                                                           */
/*   Date      : 4 November 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*               V02 : Adding New Features                                     */
/*******************************************************************************/
#define F_CPU 16000000UL
#include "util/delay.h"
/*******************************************************************************/
/* Library includes */
#include  "../inc/STD_TYPES.h"
#include  "../inc/BIT_MATH.h"
/*******************************************************************************/
#include  "../inc/I2C_interface.h"
/*******************************************************************************/

/* Module includes */
#include  "../inc/RTC_interface.h"
#include  "../inc/RTC_private.h"
#include  "../inc/RTC_config.h"
/*******************************************************************************/

void H_RTC_voidInit(RTC_CLK_t Copy_RTC_CLK)
{
	M_I2C_voidInit(I2C_ENABLE                ,
			       I2C_INTERRUPT_ENABLE      ,
				   I2C_NO_PRESCALER          ,
				   Copy_RTC_CLK              ,
				   I2C_GENERAL_CALL_DISABLE );
}
/*******************************************************************************/
void H_RTC_SetTime(u8 Copy_Hours     				,
				   u8 Copy_Minutes   				,
				   u8 Copy_Seconds   				,
				   RTC_TIME_MODE_t Copy_Time_Mode   ,
				   RTC_HOUR_MODE_t Copy_Hour_Mode   )
{
	u8 Local_u8HoursByte = 0;
	if(Copy_Hour_Mode == RTC_HOUR_12)
	{
		Local_u8HoursByte = ((RTC_voidConvertDecimalToBCD(Copy_Hours))|(RTC_HOUR_12 << RTC_BIT6)|((Copy_Time_Mode << RTC_BIT5)));
	}
	else if (Copy_Hour_Mode == RTC_HOUR_24)
	{
		Local_u8HoursByte = ((RTC_voidConvertDecimalToBCD(Copy_Hours))|(RTC_HOUR_24 << RTC_BIT6));
	}

	// Send Start Condition
	M_I2C_voidSendStart_Condition();

	// Address of RTC for Writing
	M_I2C_voidSendByte(RTC_WRITE_ADDRESS);

	/* Address for Seconds BYTE MEMORY */
	M_I2C_voidSendByte(RTC_SECONDS);

 	/* SET SECONDS */
	M_I2C_voidSendByte(RTC_voidConvertDecimalToBCD(Copy_Seconds));

	/* SET Minuts */
	M_I2C_voidSendByte(RTC_voidConvertDecimalToBCD(Copy_Minutes));

	/* SET Hours */
	M_I2C_voidSendByte(Local_u8HoursByte);

	// Send Stop Condition
	M_I2C_voidSendStop_Condition();

}
/*******************************************************************************/
void H_RTC_SetDate(RTC_DAY_MODE_t  Copy_DAY     	,
				   u8 Copy_Date   				    ,
				   u8 Copy_Month   				    ,
				   u8 Copy_Year  				    )
{
	// Send Start Condition
	M_I2C_voidSendStart_Condition();

	// Address of RTC for Writing
	M_I2C_voidSendByte(RTC_WRITE_ADDRESS);

	/* Address for DAY BYTE MEMORY */
	M_I2C_voidSendByte(RTC_DAY);

	/* SET DAY */
	M_I2C_voidSendByte(Copy_DAY);

	/* SET DATE */
	M_I2C_voidSendByte(RTC_voidConvertDecimalToBCD(Copy_Date));

	/* SET Month */
	M_I2C_voidSendByte(RTC_voidConvertDecimalToBCD(Copy_Month));

	/* SET Years */
	M_I2C_voidSendByte(RTC_voidConvertDecimalToBCD(Copy_Year));

	// Send Stop Condition
	M_I2C_voidSendStop_Condition();
}
/*******************************************************************************/
void H_RTC_GetTime(u8 * Copy_Hours ,u8 * Copy_Minutes,u8 * Copy_Seconds ,u8 * Copy_AM_PM)
{
	u8 Local_u8Hours = 0;
	u8 Local_u8Min   = 0;
	u8 Local_u8Sec   = 0;

	// Send Start Condition
	M_I2C_voidSendStart_Condition();

	// Address of RTC for Writing
	M_I2C_voidSendByte(RTC_WRITE_ADDRESS);

	/* Address for Seconds BYTE MEMORY */
	M_I2C_voidSendByte(RTC_SECONDS);

	// Send Repeated Start
	M_I2C_voidSendStart_Condition();

	// Address of RTC for reading
	M_I2C_voidSendByte(RTC_READ_ADDRESS);

	// Read Seconds
	M_I2C_voidReceiveByte_ACK(&Local_u8Sec);

	// Read Minutes
	M_I2C_voidReceiveByte_ACK(&Local_u8Min);

	// Read Hours [NOACK]
	M_I2C_voidReceiveByte_NOACK(&Local_u8Hours);

	if(GET_BIT(Local_u8Hours,RTC_BIT6) == RTC_HOUR_12)
	{
		*Copy_AM_PM = GET_BIT(Local_u8Hours,RTC_BIT5);
	}
	else
	{
		*Copy_AM_PM = RTC_ERROR ;
	}
	*Copy_Hours   = RTC_u8ConvertBCDToDecimal(Local_u8Hours & 0x1F) ;
	*Copy_Minutes = RTC_u8ConvertBCDToDecimal(Local_u8Min)   ;
	*Copy_Seconds = RTC_u8ConvertBCDToDecimal(Local_u8Sec)   ;

	// Send Stop Condition
	M_I2C_voidSendStop_Condition();
}
/****************************************************************************/
void H_RTC_GetDate(u8 * Copy_Date  ,u8 * Copy_Month  ,u8 * Copy_Year,u8 * Copy_Day)
{
	u8 Local_u8Day    = 0;
	u8 Local_u8Date   = 0;
	u8 Local_u8Month  = 0;
	u8 Local_u8Year   = 0;

	// Send Start Condition
	M_I2C_voidSendStart_Condition();

	// Address of RTC for Writing
	M_I2C_voidSendByte(RTC_WRITE_ADDRESS);

	/* Address for Day BYTE MEMORY */
	M_I2C_voidSendByte(RTC_DAY);

	// Send Repeated Start
	M_I2C_voidSendStart_Condition();

	// Address of RTC for reading
	M_I2C_voidSendByte(RTC_READ_ADDRESS);

	// Read Day
	M_I2C_voidReceiveByte_ACK(&Local_u8Day);

	// Read Date
	M_I2C_voidReceiveByte_ACK(&Local_u8Date);

	// Read Month
	M_I2C_voidReceiveByte_ACK(&Local_u8Month);

	// Read Hours [NOACK]
	M_I2C_voidReceiveByte_NOACK(&Local_u8Year);


	*Copy_Date   = RTC_u8ConvertBCDToDecimal(Local_u8Date)  ;
	*Copy_Month  = RTC_u8ConvertBCDToDecimal(Local_u8Month) ;
	*Copy_Year   = RTC_u8ConvertBCDToDecimal(Local_u8Year)  ;
	*Copy_Day    = RTC_u8ConvertBCDToDecimal(Local_u8Day)   ;
	// Send Stop Condition
	M_I2C_voidSendStop_Condition();
}
/*******************************************************************************/
/*                            Private Function                                 */
/*******************************************************************************/

u8 RTC_voidConvertDecimalToBCD(u8 Copy_u8Decimal)
{
	// Store the tens digit in the high nibble
	u8 highNibble = (Copy_u8Decimal / 10);
	// Store the ones digit in the low nibble
    u8 lowNibble = (Copy_u8Decimal % 10);
		
	return ((highNibble<<4) | lowNibble);

}
/*******************************************************************************/
u8 RTC_u8ConvertBCDToDecimal(u8 Copy_u8BCD)
{
    // Extract the high nibble (tens digit) and the low nibble (ones digit)
    u8 tensDigit = (Copy_u8BCD >> 4) & 0x0F;
    u8 onesDigit = Copy_u8BCD & 0x0F;

    // Convert BCD to decimal
    u8 decimalValue = (tensDigit * 10) + onesDigit;

    return decimalValue;
}
/*******************************************************************************/
