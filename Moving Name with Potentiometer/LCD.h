/*
 * LCD.h
 *
 *  Created on: Sep 9, 2019
 *      Author: Eman Abd El-Hamied
 */

#ifndef LCD_H_
#define LCD_H_

#define Data_Port 1
#define Ctrl_Port 3
#define RS_Pin 0
#define RW_Pin 1
#define E_Pin 2

void LCD_vidWriteCommand(u8 command);
void LCD_vidWriteData(u8 data);
void LCD_vidInit(void);
void LCD_vidWriteSpecialCharacter(u8 *pattern, u8 blockNo, u8 xpos, u8 ypos);
void LCD_vidGoToXY(u8 xpos, u8 ypos);
void LCD_vidWriteString(u8 *string);
void LCD_vidDisplayInt(s32 x);


#endif /* LCD_H_ */
