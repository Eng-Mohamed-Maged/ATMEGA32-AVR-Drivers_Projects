/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V02                                                           */
/*   Date      : 30 October 2023                                               */
/*   Logs      : V01 : Initial Creation                                        */
/*               V02 : Fix some Errors in Display                              */
/*******************************************************************************/
#ifndef _LCD_INTERFACE_H
#define _LCD_INTERFACE_H


void H_LCD_void_Init(void);
void H_LCD_void_sendData(u8 copy_u8data );
void H_LCD_void_sendCommand(u8 copy_u8command);
void H_LCD_void_sendString(const s8 * pstr);
void H_LCD_void_sendIntNum(s32 copy_s32Num);
void H_LCD_void_send2DigitNum(s32 copy_s32Num);
void H_LCD_void_gotoXY(u8 copy_u8Row,u8 copy_u8Col);
void H_LCD_void_creatCustomChar(const u8 * ArrPattern,u8 copy_u8charCode);
void H_LCD_void_displayCustomChar(u8 copy_u8charCode);
void H_LCD_void_ShiftString(const s8 *pstr,u8 copy_u8lineNumber);
void H_LCD_void_clearLine(u8 copy_u8lineNumber);
void H_LCD_void_sendFloat(f32 number, u8 decimalPlaces);

#endif
