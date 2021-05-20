#include "std_types.h"
#include "registers.h"
#include "utils.h"
#include "DIO.h"
#include "UART.h"

void UART_vidInit(void) {
	u8 ucsrc_vlaue = 0;

	//Transmission / Receiver Enable
	set_bit(UCSRB, 3);
	set_bit(UCSRB, 4);

	//Access UCSRC
	set_bit(ucsrc_vlaue, 7);

	//Character Size 8 bits
	set_bit(ucsrc_vlaue, 2);
	set_bit(ucsrc_vlaue, 1);

	//Set the value to the register
	UCSRC = ucsrc_vlaue;

	//Set 9600 bPs
	UBRRL = 51;
}

void UART_vidTransmit(u8 Data) {

	//Polling with blocking
	while ((get_bit(UCSRA, 5)) == 0)
		;

	//transmit data
	UDR = Data;
}

u8 UART_u8Receive(void) {
	//Polling with blocking
	while ((get_bit(UCSRA,7)) == 0)
		;

	//get the data
	return UDR;
}

void UART_voidSendString(u8 *string) {
	while (*string != '\0') {
		UART_vidTransmit(*string);
		string++;
	}
}

void UART_voidSendAsciiNumber(u32 x) {
	u32 y = 1;
	if (x == 0) {
		UART_vidTransmit('0'); //If zero Print zero
	}
	while (x != 0) {
		y = (y * 10) + (x % 10);
		x = (x / 10);
	}
	while (y != 1) {
		UART_vidTransmit((y % 10) + '0'); //Will diisplay number backwards
		y = y / 10;
	}
}
