#include "std_types.h"
#include "registers.h"
#include "utils.h"
#include "DIO.h"
#include "UART.h"
#include <avr/delay.h>

int main(void) {
	u8 password[3], ID, i, j;
	u8 PW = 123;
	u16 temp;
	UART_vidInit();
	//Buzzer
	DIO_vidSetPinDirection(1, 0, 1);
	DIO_vidWritePinValue(1, 0, 0);
	while (1) {
		UART_voidSendString("Welcome");
		_delay_ms(3000);
		UART_voidSendString(",Enter Your ID  ");
		ID = UART_u8Receive();
		while (ID < 48) {
			ID = UART_u8Receive();
		}

		UART_voidSendString("Welcome");
		UART_vidTransmit(ID);
		UART_vidTransmit('\n');
		UART_voidSendString(",Enter Your Password  ");
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				password[j] = UART_u8Receive();
				while (password[j] < 48) {
					password[j] = UART_u8Receive();
				}
				UART_vidTransmit(password[j]);
			}
			UART_vidTransmit('\n');
			temp = (((password[0] - 48) * 100) + ((password[1]-48)*10)+ (password[2]-48));
			if (temp == PW) {
				UART_voidSendString("Welcome ");
				UART_voidSendAsciiNumber(ID - 48);
				UART_vidTransmit('\n');
				break;
			} else if (temp != PW && i!=2) {
				UART_vidTransmit('\n');
				UART_voidSendString("   Try Again");
			} else if (temp != PW) {
				//Cuzzer
				DIO_vidWritePinValue(1, 0, 1);
				_delay_ms(3000);
				DIO_vidWritePinValue(1, 0, 0);
				UART_vidTransmit('\n');
			}
		}
	}
	return 0;
}

