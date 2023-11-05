/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 22 October 2023                                               */
/*   Logs      : V01 : Initial Creation                                        */
/*******************************************************************************/

#include  "../inc/STD_TYPES.h"
#include  "../inc/BIT_MATH.h"

#include "../inc/GIE_interface.h"
#include "../inc/GIE_private.h"
#include "../inc/GIE_config.h"



void MGIE_voidEnable(void)
{
	GIE->SREG  |= (GIE_ENABLE  << GIE_BIT) ;
}





void MGIE_voidDisable(void)
{	
	GIE->SREG  |= (GIE_DISABLE  << GIE_BIT) ;
}

