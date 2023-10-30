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
#include  "../inc/USART_interface.h"
#include  "../inc/USART_private.h"
#include  "../inc/USART_config.h"
/*******************************************************************************/
void (*USART_CallBack)(u8) = NULL;
/*******************************************************************************/
void M_USART_voidInit(void)
{
	u8 Local_RegTemp  = 0;
  /*******************************************************************************/
	   Local_RegTemp |= (USART_TRANSMISSION_SPEED << USART_U2X_BIT) ;
	   Local_RegTemp |= (USART_ENABLE << USART_TXC_BIT) ;
	   USART->UCSRA   = Local_RegTemp;
  /*******************************************************************************/
	   Local_RegTemp  = 0;
	   USART->UBRRH_UCSRC = (u8)(USART_BAUD_PRESCALE>>8);
	   USART->UBRRL       = (u8)(USART_BAUD_PRESCALE);
  /*******************************************************************************/
	   Local_RegTemp  = 0;
	   Local_RegTemp |= (USART_ENABLE  << USART_RXCIE_BIT) ;
	   Local_RegTemp |= (USART_ENABLE  << USART_TXCIE_BIT) ;
	   Local_RegTemp |= (USART_ENABLE  << USART_UDRIE_BIT) ;
	   Local_RegTemp |= (USART_ENABLE  << USART_RXEN_BIT ) ;
	   Local_RegTemp |= (USART_ENABLE  << USART_TXEN_BIT ) ;
	   Local_RegTemp |= (USART_DISABLE << USART_UCSZ2_BIT) ;
	   USART->UCSRB   = Local_RegTemp;
  /*******************************************************************************/
	   Local_RegTemp  = 0;
	   Local_RegTemp |= (USART_ENABLE       << USART_URSEL_BIT) ;
	   Local_RegTemp |= (USART_MODE_SELECT  << USART_UMSEL_BIT) ;
	   Local_RegTemp |= (USART_PARITY_MODE  << USART_UPM0_BIT ) ;
	   Local_RegTemp |= (USART_STOP_BITS    << USART_USBS_BIT ) ;
	   Local_RegTemp |= (USART_DATA_BITS    << USART_UCSZ0_BIT) ;
	   Local_RegTemp |= (USART_CLK_POLARITY << USART_UCPOL_BIT) ;
	   USART->UBRRH_UCSRC   = Local_RegTemp;
  /*******************************************************************************/
}
/*********************************************************************************/
/*********************************************************************************/
void M_USART_voidTransmitByte(u8 Copy_u8TXByte)
{
	while(GET_BIT(USART->UCSRA,USART_UDRE_BIT) == 0);
			USART->UDR = Copy_u8TXByte ;
}
/*********************************************************************************/
/*********************************************************************************/
void M_USART_voidTransmitString(u8 * Copy_ptrTXString)
{
	u8 Local_u8Counter = 0;
	while(Copy_ptrTXString[Local_u8Counter] != '\0')
	{
		M_USART_voidTransmitByte(Copy_ptrTXString[Local_u8Counter]);
		Local_u8Counter++;
	}
}
/*********************************************************************************/
/*********************************************************************************/
void M_USART_voidReceiveByteSynchBlocking(u8 * Copy_u8RXByte)
{
	while(GET_BIT(USART->UCSRA,USART_RXC_BIT) == 0);
		*Copy_u8RXByte = USART->UDR ;

}
/*********************************************************************************/
/*********************************************************************************/
void M_USART_voidReceiveByteASynchCallBack(void (*PFun)(u8 Copy_u8RXByte))
{
	USART_CallBack = PFun;
}
/*********************************************************************************/
/*********************************************************************************/










/****************************************************************************/
/****************************************************************************/
/****************************************************************************/
/* USART, Rx Complete ISR */
USART_RX_COMPLETE_IRQHandler
{
	USART_CallBack(USART->UDR);
}
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/
/* USART Data Register Empty ISR */
USART_DATA_REGISTER_EMPTY_IRQHandler
{



}
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/
/* USART, Tx Complete ISR */
USART_TX_COMPLETE_IRQHandler
{

}


/****************************************************************************/
/****************************************************************************/
/****************************************************************************/








/*******************************************************************************/






