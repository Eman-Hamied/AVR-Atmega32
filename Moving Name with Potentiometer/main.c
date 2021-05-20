#include "std_types.h"
#include "registers.h"
#include "utils.h"
#include "DIO.h"
#include "ADC.h"
#include "LCD.h"
#include <avr/delay.h>

int main(void) {

	//Direction Initialization
	ADC_vidInit();
	LCD_vidInit();

	u16 digital = 0;
	u16 analog = 0;

	while (1) {
		LCD_vidWriteCommand(0b00000001);
		digital = ADC_u16ReadDigital();
		//analog = (digital * 500) / 1023; // We Multiplied by 1000 to convert from volt to mv and divided by 10 to convert to

		analog = (digital * 5) / 1023;
		LCD_vidGoToXY(analog, 0);
		LCD_vidWriteData('E');
		LCD_vidGoToXY(analog+1, 0);
		LCD_vidWriteData('M');
		LCD_vidGoToXY(analog+2, 0);
		LCD_vidWriteData('A');
		LCD_vidGoToXY(analog+3, 0);
		LCD_vidWriteData(' ');
		LCD_vidGoToXY(analog+4, 0);
		LCD_vidWriteData(' ');

	}
	return 0;
}

