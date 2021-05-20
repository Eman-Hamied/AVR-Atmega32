#include "std_types.h"
#include "registers.h"
#include "utils.h"
#include "LCD.h"
#include "DIO.h"
#include <avr/delay.h>

void LCD_vidWriteCommand(u8 command) {
	//Set RS Command
	DIO_vidWritePinValue(Ctrl_Port, RS_Pin, 0);

	//Set RW Wrtite
	DIO_vidWritePinValue(Ctrl_Port, RW_Pin, 0);

	//Send the command
	DIO_vidWritePort(Data_Port, command);

	//Enable to read the command
	DIO_vidWritePinValue(Ctrl_Port, E_Pin, 1);

	_delay_ms(2);

	DIO_vidWritePinValue(Ctrl_Port, E_Pin, 0); //disable
}

void LCD_vidWriteData(u8 data) {
	//Set RS Data
	DIO_vidWritePinValue(Ctrl_Port, RS_Pin, 1);

	//Set RW Wrtite
	DIO_vidWritePinValue(Ctrl_Port, RW_Pin, 0);

	//Send the Data
	DIO_vidWritePort(Data_Port, data);

	//Enable to read the Data
	DIO_vidWritePinValue(Ctrl_Port, E_Pin, 1);

	_delay_ms(2);

	DIO_vidWritePinValue(Ctrl_Port, E_Pin, 0); //disable
}

void LCD_vidInit(void) {
	//Set Direction
	DIO_vidSetPortDirection(Data_Port, 0xff);
	DIO_vidSetPinDirection(Ctrl_Port, RS_Pin, 1);
	DIO_vidSetPinDirection(Ctrl_Port, RW_Pin, 1);
	DIO_vidSetPinDirection(Ctrl_Port, E_Pin, 1);
	//wait for more than 30 ms
	_delay_ms(40);
	LCD_vidWriteCommand(0b00111000);

	//wait for more than 39 microsecond
	_delay_ms(1);

	//On/OFF Display Control
	LCD_vidWriteCommand(0b00001100);

	//wait for more than 39 microsecond
	_delay_ms(1);

	//Display Clear
	LCD_vidWriteCommand(0b00000001);

	//wait for more than 1.5 ms
	_delay_ms(2);

}

void LCD_vidWriteString(u8 *string) {
	while (*string != '\0') {
		LCD_vidWriteData(*string);
		string++;
	}
}

void LCD_vidGoToXY(u8 xpos, u8 ypos) {
	u8 address = 0;
	if (ypos == 0) {
		address = xpos;
	} else if (ypos == 1) {
		address = xpos + 0x40;
	}
	address |= (1 << 7);
	LCD_vidWriteCommand(address);
}

void LCD_vidWriteSpecialCharacter(u8 *pattern, u8 blockNo, u8 xpos, u8 ypos) {
	u8 cgramAddress, i;

	//Set CG RAM Addreess
	cgramAddress = blockNo * 8;
	cgramAddress |= (1 << 6);
	LCD_vidWriteCommand(cgramAddress);

	//Load Data in CGRam
	for (i = 0; i < 8; i++) {
		LCD_vidWriteData(pattern[i]);
	}

	//Set DDRAM Address
	LCD_vidGoToXY(xpos, ypos);

	//Display the position
	LCD_vidWriteData(blockNo);
}

//void LCD_vidWriteInt(u8 number) {
//	u8 arr[2], i, c;
//	for (i = 0; i < 2; i++) {
//		arr[i] = number % 10;
//		number = number / 10;
//	}
//	c = arr[1] + '0';
//	LCD_vidWriteData(c);
//	c = arr[0] + '0';
//	LCD_vidWriteData(c);
//
//}

void LCD_vidDisplayInt(s32 x) {
	u32 y = 1;
	if (x == 0) {
		LCD_vidWriteData('0');
	}
	if (x < 0) {
		LCD_vidWriteData('-');
		x = x * -1;
	}
	while (x != 0) {
		y = (y * 10) + (x % 10);
		x = (x / 10);
	}
	while (y != 1) {
		LCD_vidWriteData((y % 10) + '0');
		y = y / 10;
	}
}
