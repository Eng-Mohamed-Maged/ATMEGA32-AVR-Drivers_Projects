/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 31 October 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
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
#include  "../inc/EEPROM_interface.h"
#include  "../inc/EEPROM_private.h"
#include  "../inc/EEPROM_config.h"
/*******************************************************************************/

void H_EEPROM_voidInit(EEPROM_CLK_t Copy_EEPROM_CLK)
{
	M_I2C_voidInit(I2C_ENABLE                ,
			       I2C_INTERRUPT_ENABLE      ,
				   I2C_NO_PRESCALER          ,
				   Copy_EEPROM_CLK           ,
				   I2C_GENERAL_CALL_DISABLE );
}




I2C_STATUS_t H_EEPROM_WriteByte(u16 Copy_u16Address, u8 Copy_u8SendData)
{
	I2C_STATUS_t ERROR_STATE = I2C_ERROR;
	// step 1 :	send Start
	M_I2C_voidSendStart_Condition();
	
	// step 2 : check status if not Start Success return false
    M_I2C_voidGetStatus(&ERROR_STATE);
	if (ERROR_STATE != I2C_MT_MR_START_CONDITION)
	{
		return I2C_ERROR;
	}
	
	// step 3 : send address 1010 + E A9 A8 + W
	M_I2C_voidSendByte(0b10100000);
	// step 4 : check status TWI_MT_SLA_W_ACK 
    M_I2C_voidGetStatus(&ERROR_STATE);
	if (ERROR_STATE != I2C_MT_SLA_W_ACK)
	{
		return I2C_ERROR;
	}

	// step 5 : send rest of Byte address as data A7 .....A0
	M_I2C_voidSendByte((u8)Copy_u16Address);
	
	
	// step 6 : check status TWI_MT_DATA_ACK
    M_I2C_voidGetStatus(&ERROR_STATE);
	if (ERROR_STATE != I2C_MT_DATA_ACK)
	{
		return I2C_ERROR;
	}
	// step 7 : send Byte to be written
	M_I2C_voidSendByte(Copy_u8SendData);

	// step 8 : check status TWI_MT_DATA_ACK
    M_I2C_voidGetStatus(&ERROR_STATE);
	if (ERROR_STATE != I2C_MT_DATA_ACK)
	{
		return I2C_ERROR;
	}
	// step 9 : send stop
	M_I2C_voidSendStop_Condition();

	/* Delay for next Byte */
	_delay_ms(10);

	return ERROR_STATE;
}


I2C_STATUS_t H_EEPROM_EraseByte(u16 Copy_u16Address)
{
	return H_EEPROM_WriteByte(Copy_u16Address, 0xFF);
}



I2C_STATUS_t H_EEPROM_ReadByte(u16 Copy_u16Address, u8 * Copy_u8RecievedData)
{
	I2C_STATUS_t ERROR_STATE = I2C_ERROR;

//	step 1 : send Start
	M_I2C_voidSendStart_Condition();

//	step 2 : check status if not Start Success return false
    M_I2C_voidGetStatus(&ERROR_STATE);
	if (ERROR_STATE != I2C_MT_MR_START_CONDITION)
	{
		return I2C_ERROR;
	}
//  step 3 : send address 1010 + E A9 A8 + W
	M_I2C_voidSendByte(0b10100000);

	
//  step 4 : check status TWI_MT_SLA_W_ACK 
    M_I2C_voidGetStatus(&ERROR_STATE);
	if (ERROR_STATE != I2C_MT_SLA_W_ACK)
	{
		return I2C_ERROR;
	}
//  step 5 : send rest of Byte address as data A7 .....A0
	M_I2C_voidSendByte((u8)Copy_u16Address);
	
//  step 6 : check status TWI_MT_DATA_ACK
    M_I2C_voidGetStatus(&ERROR_STATE);
	if (ERROR_STATE != I2C_MT_DATA_ACK)
	{
		return I2C_ERROR;
	}
	
//  step 7 : send Repeated Start
	M_I2C_voidSendStart_Condition();
	
//  step 8 : check status
    M_I2C_voidGetStatus(&ERROR_STATE);
	if (ERROR_STATE != I2C_MT_MR_REPEATED_START_CONDITION)
	{
		return I2C_ERROR;
	}
//  step 9 : send address [1010 + 100 + R] NOT [1010 + 000 + R]
	M_I2C_voidSendByte(0b10100001);

//  step 10 : check status TWI_MR_SLA_R_ACK
    M_I2C_voidGetStatus(&ERROR_STATE);
	if (ERROR_STATE != I2C_MR_SLA_R_ACK)
	{
		return I2C_ERROR;
	}
	

//  step 11 : read data
	u8 Local_u8Recieved = 0;
	M_I2C_voidReceiveByte_ACK(&Local_u8Recieved);
	*Copy_u8RecievedData = Local_u8Recieved;
	
//  step 12 : check status TWI_MR_DATA_ACK
    M_I2C_voidGetStatus(&ERROR_STATE);
	if (ERROR_STATE != I2C_MR_DATA_ACK)
	{
		return I2C_ERROR;
	}
	
//  step 13 : send Stop
	M_I2C_voidSendStop_Condition();

	/* Delay for next Byte */
	_delay_ms(10);

	return ERROR_STATE;

}











