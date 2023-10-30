/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 30 October 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*******************************************************************************/
#ifndef USART_INTERFACE_H
#define	USART_INTERFACE_H
/*************************************************************************************************************/



void M_USART_voidInit(void);
void M_USART_voidTransmitByte(u8 Copy_u8TXByte);
void M_USART_voidTransmitString(u8 * Copy_ptrTXString);
void M_USART_voidReceiveByteSynchBlocking(u8 * Copy_u8RXByte);
void M_USART_voidReceiveByteASynchCallBack(void (*PFun)(u8 Copy_u8RXByte));





/*************************************************************************************************************/
#endif
