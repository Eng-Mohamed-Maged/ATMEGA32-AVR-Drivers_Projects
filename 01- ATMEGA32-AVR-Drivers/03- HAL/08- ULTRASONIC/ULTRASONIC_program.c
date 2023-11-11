/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V02                                                           */
/*   Date      : 11 November 2023                                              */
/*   Logs      : V01 : Initial creation                                        */
/*               V02 : Fixed Error in calculations                             */
/*******************************************************************************/
/* Library includes */
#include  "../inc/STD_TYPES.h"
#include  "../inc/BIT_MATH.h"
/*******************************************************************************/
#include  "../inc/TIMER1_interface.h"
/*******************************************************************************/
/* Module includes */
#include  "../inc/ULTRASONIC_interface.h"
#include  "../inc/ULTRASONIC_private.h"
#include  "../inc/ULTRASONIC_config.h"
/*******************************************************************************/
void H_ULTRASONIC_voidInit(void)
{
 	M_TIMER1_voidInit();
}
/*******************************************************************************/
void H_ULTRASONIC_voidGetDistanceInCentimeters(f32 *Copy_ptrGetDistance_CM)
{
	f32 Local_u32GetTimeOn_us;
	M_TIMER1_voidICU_GetTimeOn_us(&Local_u32GetTimeOn_us);
	*Copy_ptrGetDistance_CM = ((ULTRASONIC_SOUND_SPEED_CM_S * (Local_u32GetTimeOn_us/2)))/1000000 ;
}

/*******************************************************************************/
