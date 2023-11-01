/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 31 October 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*******************************************************************************/
/* Library includes */
#include  "../inc/STD_TYPES.h"
#include  "../inc/BIT_MATH.h"
/*******************************************************************************/
/* Module includes */
#include  "../inc/I2C_interface.h"
#include  "../inc/I2C_private.h"
#include  "../inc/I2C_config.h"
/*******************************************************************************/
//void (*I2C_CallBack)(u8) = NULL;
/*******************************************************************************/
void M_I2C_voidInit(I2C_MODE_t              Copy_I2C_MODE       ,
					I2C_INTERRUPT_t         Copy_I2C_INTERRUPT  ,
					I2C_PRESCALER_t         Copy_I2C_PRESCALER  ,
					I2C_CLK_t               Copy_I2C_CLOCK      ,
					I2C_GENRATION_CALL_t    Copy_I2C_GCALL 
					)
{
	u8 Local_RegTemp  = 0;
	/*******************************************************************************/
	Local_RegTemp |= (Copy_I2C_INTERRUPT            << I2C_TWIE_BIT ) ;
	Local_RegTemp |= (Copy_I2C_MODE                 << I2C_TWEN_BIT ) ;
	I2C->TWCR      =  Local_RegTemp;
	/*******************************************************************************/
	Local_RegTemp  = 0;
	Local_RegTemp |= (Copy_I2C_PRESCALER            << I2C_TWPS0_BIT) ;
	I2C->TWSR      =  Local_RegTemp;
	/*******************************************************************************/
	I2C->TWBR      =  Copy_I2C_CLOCK;
    /*******************************************************************************/
	Local_RegTemp  = 0;
	Local_RegTemp |= (Copy_I2C_GCALL                << I2C_TWGCE_BIT) ;
	I2C->TWSR      =  Local_RegTemp;

}				

/*********************************************************************************/
/*********************************************************************************/
void M_I2C_voidSendByte(u8 Copy_u8TXByte)
{
	I2C->TWDR = Copy_u8TXByte;
	// Enable TWI and clear interrupt flag
	I2C->TWCR = (1<<I2C_TWEN_BIT)|(1<<I2C_TWINT_BIT);
	/* Wait until TWI finish sending address+ write bit */
	while (!(I2C->TWCR & (1<<I2C_TWINT_BIT)));
}
/*********************************************************************************/
/*********************************************************************************/
void M_I2C_voidSendStart_Condition(void)
{
	/* Enable TWI, generate start condition and clear interrupt flag */
	I2C->TWCR = (1<<I2C_TWSTA_BIT)|(1<<I2C_TWEN_BIT)|(1<<I2C_TWINT_BIT);
	
	/* Wait until TWI finish sending start condition */
	while (!(I2C->TWCR & (1<<I2C_TWINT_BIT)));
}
/*********************************************************************************/
/*********************************************************************************/
void M_I2C_voidSendStop_Condition(void)
{
	/* Enable TWI, generate start condition and clear interrupt flag */
	I2C->TWCR = (1<<I2C_TWSTO_BIT)|(1<<I2C_TWEN_BIT)|(1<<I2C_TWINT_BIT);
	
}
/*********************************************************************************/
/*********************************************************************************/
void M_I2C_voidReceiveByte_ACK(u8 * Copy_Byte_ACK)
{
	/* Enable TWI, generate an Acknoledge and clear interrupt flag */
	I2C->TWCR=(1<<I2C_TWEA_BIT)|(1<<I2C_TWINT_BIT)|(1<<I2C_TWEN_BIT);
	/* Wait until TWI finish sending Data */
	while (!(I2C->TWCR & (1<<I2C_TWINT_BIT)));
	/* Return recieved Data */
	*Copy_Byte_ACK = I2C->TWDR ;
	
}
/*********************************************************************************/
/*********************************************************************************/
void M_I2C_voidReceiveByte_NOACK(u8 * Copy_Byte_NOACK)
{
	/* Enable TWI and clear interrupt flag */
	I2C->TWCR=(1<<I2C_TWINT_BIT)|(1<<I2C_TWEN_BIT);
	/* Wait until TWI finish sending Data */
	while (!(I2C->TWCR & (1<<I2C_TWINT_BIT)));
	/* Return recieved Data */
	*Copy_Byte_NOACK = I2C->TWDR;
	
	
}
/*********************************************************************************/
/*********************************************************************************/
void M_I2C_voidGetStatus(u8 * Copy_Status)
{
	// Read status and Mask the prescaler bits
	*Copy_Status = (I2C->TWSR & I2C_STATUS_MASK);
}
/*********************************************************************************/
/*********************************************************************************/
































