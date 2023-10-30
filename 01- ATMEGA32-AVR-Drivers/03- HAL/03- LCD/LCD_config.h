/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V02                                                           */
/*   Date      : 30 October 2023                                               */
/*   Logs      : V01 : Initial Creation                                        */
/*               V02 : Fix some Errors in Display                              */
/*******************************************************************************/

#ifndef _LCD_CONFIG_H
#define _LCD_CONFIG_H





#define LCD_RS_PORT_PIN 			PORT_A,PIN_3
#define LCD_RW_PORT_PIN 			PORT_A,PIN_1
#define LCD_EN_PORT_PIN				PORT_A,PIN_2

#define LCD_D0_PORT_PIN				PORT_B,PIN_7
#define LCD_D1_PORT_PIN				PORT_B,PIN_6
#define LCD_D2_PORT_PIN				PORT_B,PIN_5
#define LCD_D3_PORT_PIN				PORT_B,PIN_3

#define LCD_D4_PORT_PIN				PORT_B,PIN_0
#define LCD_D5_PORT_PIN				PORT_B,PIN_1
#define LCD_D6_PORT_PIN				PORT_B,PIN_2
#define LCD_D7_PORT_PIN				PORT_B,PIN_4


/* Options :
                 MODE_4BIT
				 MODE_8BIT
*/

#define LCD_MODE 					MODE_4BIT


/* Options :
                 FONT_5X7
				 FONT_5X10
*/
#define LCD_FONT 					FONT_5X7


/* Options :
                 ONE_LINE
				 TWO_LINE
				 FOUR_LINE
*/
#define LCD_LINE 					FOUR_LINE


#define LCD_CLEAR 					0x01


#define LCD_ROW                     4
#define LCD_COLUMNS                 20

#endif
