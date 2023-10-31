/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 30 October 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*******************************************************************************/
/* Library includes */
#include  "../inc/STD_TYPES.h"
#include  "../inc/BIT_MATH.h"
/*******************************************************************************/
/* Module includes */
#include  "../inc/SPI_interface.h"
#include  "../inc/SPI_private.h"
#include  "../inc/SPI_config.h"
/*******************************************************************************/
#define F_CPU 16000000UL
#include "util/delay.h"
void (*SPI_CallBack)(u8) = NULL;
/*******************************************************************************/

void M_SPI_voidInit( 
					 SPI_MODE_t                    Copy_SPI_Mode                   ,
					 SPI_INTERRUPT_t               Copy_SPI_Interrupt              ,
					 SPI_MASTER_SLAVE_SELECT_t     Copy_SPI_Select_Master_Slave    ,
					 SPI_CLK_t     				   Copy_SPI_CLK   				   ,
					 SPI_DATA_ORDER_t              Copy_SPI_Data_Order             ,
					 SPI_CLK_POLARITY_t            Copy_SPI_CPOL              	   ,
					 SPI_CLK_PHASE_t               Copy_SPI_CPHHASE                ,
					 SPI_SPEED_t                   Copy_SPI_Speed              
					 )
{
	
	u8 Local_RegTemp  = 0;
	/*******************************************************************************/
	Local_RegTemp |= (Copy_SPI_Interrupt            << SPI_SPIE_BIT) ;
	Local_RegTemp |= (Copy_SPI_Mode                 << SPI_SPE_BIT ) ;
	Local_RegTemp |= (Copy_SPI_Data_Order           << SPI_DORD_BIT) ;
	Local_RegTemp |= (Copy_SPI_Select_Master_Slave  << SPI_MSTR_BIT) ;
	Local_RegTemp |= (Copy_SPI_CPOL                 << SPI_CPOL_BIT) ;
	Local_RegTemp |= (Copy_SPI_CPHHASE              << SPI_CPHA_BIT) ;
	Local_RegTemp |= ((Copy_SPI_CLK & 0x03)         << SPI_SPR0_BIT) ;
	SPI->SPCR      =  Local_RegTemp;
	/*******************************************************************************/
	Local_RegTemp  = 0;
	Local_RegTemp |= (Copy_SPI_Speed                << SPI_SPI2X_BIT) ;
	SPI->SPSR      =  Local_RegTemp;
	/*******************************************************************************/
	
}

/*********************************************************************************/
/*********************************************************************************/
void M_SPI_voidTransmitByte(u8 Copy_u8TXByte)
{
  	u8 Local_Dummy;
	SPI->SPDR  = Copy_u8TXByte ;
	while(GET_BIT(SPI->SPSR,SPI_SPIF_BIT) == 0);
	/* This dummy read to acknowledge the completed transmission */
  		Local_Dummy = SPI->SPDR ;
}
/*********************************************************************************/
/*********************************************************************************/
void M_SPI_voidTransmitString(u8 * Copy_ptrTXString)
{
	u8 Local_u8Counter = 0;
	while(Copy_ptrTXString[Local_u8Counter] != '\0')
	{
		M_SPI_voidTransmitByte(Copy_ptrTXString[Local_u8Counter]);
		Local_u8Counter++;
	}
}
/*********************************************************************************/
/*********************************************************************************/
void M_SPI_voidReceiveByteSynchBlocking(u8 * Copy_u8RXByte)
{
	while(GET_BIT(SPI->SPSR,SPI_SPIF_BIT) == 0);
		*Copy_u8RXByte = SPI->SPDR  ;

}
/*********************************************************************************/
/*********************************************************************************/
void M_SPI_voidReceiveByteASynchCallBack(void (*PFun)(u8 Copy_u8RXByte))
{
	SPI_CallBack = PFun;
}
/*********************************************************************************/
/*********************************************************************************/
/*********************************************************************************/
/*********************************************************************************/
/*********************************************************************************/
/* Serial Transfer Complete ISR */
SPI_TRANSFER_COMPLETE_IRQHandler
{
	SPI_CallBack(SPI->SPDR);
}
/*********************************************************************************/
/*********************************************************************************/
/*********************************************************************************/
/*********************************************************************************/
