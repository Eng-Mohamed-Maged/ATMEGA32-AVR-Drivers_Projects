/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 30 October 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*******************************************************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H
/*******************************************************************************/
/*
	NOT USED In DRIVER |
*/

#define     SPI_SCK_PORT_PIN                   PORT_B,PIN_7
#define     SPI_MISO_PORT_PIN                  PORT_B,PIN_6
#define     SPI_MOSI_PORT_PIN                  PORT_B,PIN_5
#define     SPI_SS_PORT_PIN                    PORT_B,PIN_4


/*******************************************************************************/
/*
	Determine the SYSTEM clock in [HZ] to make the calculations be correct 
*/
#define     SYSTEM_CLOCK_SOURCE                 16000000
/*******************************************************************************/





#endif
