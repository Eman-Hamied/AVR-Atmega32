#include "std_types.h"
#include "registers.h"
#include "utils.h"
#include "DIO.h"

//Function to set pin direction
void DIO_vidSetPinDirection(u8 port, u8 pin, u8 dir) {
	switch (port) {
	case 0:
		if (dir == 0) {
			clr_bit(DDRA, pin);
		} else if (dir == 1) {
			set_bit(DDRA, pin);
		}
		break;
	case 1:
		if (dir == 0) {
			clr_bit(DDRB, pin);
		} else if (dir == 1) {
			set_bit(DDRB, pin);
		}
		break;
	case 2:
		if (dir == 0) {
			clr_bit(DDRC, pin);
		} else if (dir == 1) {
			set_bit(DDRC, pin);
		}
		break;
	case 3:
		if (dir == 0) {
			clr_bit(DDRD, pin);
		} else if (dir == 1) {
			set_bit(DDRD, pin);
		}
		break;
	}
}

//Function to set pin value
void DIO_vidWritePinValue(u8 port, u8 pin, u8 value) {
	switch (port) {
	case 0:
		if (value == 0) {
			clr_bit(PORTA, pin);
		} else if (value == 1) {
			set_bit(PORTA, pin);
		}
		break;
	case 1:
		if (value == 0) {
			clr_bit(PORTB, pin);
		} else if (value == 1) {
			set_bit(PORTB, pin);
		}
		break;
	case 2:
		if (value == 0) {
			clr_bit(PORTC, pin);
		} else if (value == 1) {
			set_bit(PORTC, pin);
		}
		break;
	case 3:
		if (value == 0) {
			clr_bit(PORTD, pin);
		} else if (value == 1) {
			set_bit(PORTD, pin);
		}
		break;
	}
}

//Function to read pin value
u8 DIO_u8ReadPinValue(u8 port, u8 pin) {
	switch (port) {
	case 0:
		return get_bit(PINA, pin);
		break;
	case 1:
		return get_bit(PINB, pin);
		break;
	case 2:
		return get_bit(PINC, pin);
		break;
	case 3:
		return get_bit(PIND, pin);
		break;
	default:
		return 0;
		break;
	}
}
void DIO_vidSetPortDirection(u8 port, u8 dir) {
	switch (port) {
	case 0:
		set_byte(DDRA, dir);
		break;
	case 1:
		set_byte(DDRB, dir);
		break;
	case 2:
		set_byte(DDRC, dir);
		break;
	case 3:
		set_byte(DDRD, dir);
		break;
	}
}

void DIO_vidWritePort(u8 port, u8 value) {
	switch (port) {
	case 0:
		set_byte(PORTA, value);
		break;
	case 1:
		set_byte(PORTB, value);
		break;
	case 2:
		set_byte(PORTC, value);
		break;
	case 3:
		set_byte(PORTD, value);
		break;
	}
}

u8 DIO_u8ReadPort(u8 port) {

	switch (port) {
	case 0:
		return PINA;
		break;
	case 1:
		return PINB;
		break;
	case 2:
		return PINC;
		break;
	case 3:
		return PIND;
		break;
	default:
		return 0;
		break;
	}
}
