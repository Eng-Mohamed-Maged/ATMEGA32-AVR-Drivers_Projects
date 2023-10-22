/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 22 October 2023                                               */
/*   Logs      : V01 : Initial Creation                                        */
/*******************************************************************************/

#ifndef  GIE_PRIVATE_H
#define  GIE_PRIVATE_H


typedef struct{

	volatile u8 SREG      ;

}GIE_t;

#define GIE_BASE_ADDRESS 			0x5F
#define GIE ((volatile GIE_t *) GIE_BASE_ADDRESS)

 
#endif
