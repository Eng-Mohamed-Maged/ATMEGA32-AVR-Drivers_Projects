/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V02                                                           */
/*   Date      : 30 October 2023                                               */
/*   Logs      : V01 : Initial Creation                                        */
/*               V02 : Replacing "asm" instruction                             */
/*******************************************************************************/


#ifndef  GIE_PRIVATE_H
#define  GIE_PRIVATE_H

/************************************************************/
typedef struct{

	volatile u8 SREG      ;

}GIE_t;
/************************************************************/
#define GIE_BASE_ADDRESS 			0x5F
#define GIE ((volatile GIE_t *) GIE_BASE_ADDRESS)
/************************************************************/
#define GIE_BIT                     7
/************************************************************/
#define GIE_ENABLE                  1
#define GIE_DISABLE                 0
/************************************************************/

#endif
