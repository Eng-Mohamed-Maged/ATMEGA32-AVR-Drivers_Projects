/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 5 November 2023                                               */
/*   Logs      : V01 : Initial Creation                                        */
/*******************************************************************************/
#include  "../inc/STD_TYPES.h"
#include  "../inc/BIT_MATH.h"
/*******************************************************************************/
#include "../inc/WDR_interface.h"
#include "../inc/WDR_private.h"
#include "../inc/WDR_config.h"
/*******************************************************************************/
void MWDR_voidEnable(WDR_SLEEP_TIME_t Copy_SleepTime)
{
	
	WDR->WDTCR &= WDR_PRESCALER_ENABLE_MASKING ;
	WDR->WDTCR |= Copy_SleepTime               ;
}
/*******************************************************************************/
void MWDR_voidDisable(void)
{
	/* Write logical one to WDTOE and WDE */
	WDR->WDTCR |= (WDR_ENABLE<<WDR_WDTOE_BIT) | (WDR_ENABLE<<WDR_WDE_BIT);
	
	/* Turn off WDT */
	WDR->WDTCR  =  WDR_DISABLE ;
}
/*******************************************************************************/
void MWDR_voidRefresh(void)
{
	/* Reset Watch Dog */
	asm("WDR");
}
/*******************************************************************************/