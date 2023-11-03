/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 31 October 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*******************************************************************************/
#ifndef EEPROM_INTERFACE_H
#define	EEPROM_INTERFACE_H
/*************************************************************************************************************/
/****************************************************************************/
/***************************      EEPROM_MODE_t        *************************/
/****************************************************************************/
/****************************************************************************/
typedef enum
{
	EEPROM_CLK_SPEED_100K  = I2C_CLK_SPEED_100K    ,
	EEPROM_CLK_SPEED_400K  = I2C_CLK_SPEED_400K
}EEPROM_CLK_t;


void H_EEPROM_voidInit(EEPROM_CLK_t Copy_EEPROM_CLK);
I2C_STATUS_t H_EEPROM_WriteByte(u16 Copy_u16Address, u8 Copy_u8SendData);
I2C_STATUS_t H_EEPROM_ReadByte(u16 Copy_u16Address, u8 * Copy_u8RecievedData);
I2C_STATUS_t H_EEPROM_EraseByte(u16 Copy_u16Address);


/*************************************************************************************************************/
#endif
