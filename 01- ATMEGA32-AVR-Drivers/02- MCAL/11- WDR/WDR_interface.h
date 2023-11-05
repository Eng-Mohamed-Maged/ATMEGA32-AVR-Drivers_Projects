/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 5 November 2023                                               */
/*   Logs      : V01 : Initial Creation                                        */
/*******************************************************************************/
#ifndef  WDR_INTERFACE_H
#define  WDR_INTERFACE_H
/*******************************************************************************/
typedef enum
{
	WDR_17MS_AT_3V_OR_16MS_AT_5V   = 8 ,
	WDR_34MS_AT_3V_OR_32MS_AT_5V       ,
	WDR_68MS_AT_3V_OR_65MS_AT_5V       ,
	WDR_140MS_AT_3V_OR_130MS_AT_5V     ,
	WDR_270MS_AT_3V_OR_260MS_AT_5V     ,
	WDR_550MS_AT_3V_OR_520MS_AT_5V     ,
	WDR_1100MS_AT_3V_OR_1000MS_AT_5V   ,
	WDR_2200MS_AT_3V_OR_2100MS_AT_5V           
 
}WDR_SLEEP_TIME_t;



/****************  Functions Decleration  ******************/
void MWDR_voidEnable(WDR_SLEEP_TIME_t Copy_SleepTime);
void MWDR_voidDisable(void);
void MWDR_voidRefresh(void);
/************************************************************/


#endif
