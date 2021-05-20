#ifndef REGISTERS_H_
#define REGISTERS_H_

//DDR Addresses
#define DDRA (*(volatile u8*)0x3A)
#define DDRB (*(volatile u8*)0x37)
#define DDRC (*(volatile u8*)0x34)
#define DDRD (*(volatile u8*)0x31)

//PORT Addresses
#define PORTA (*(volatile u8*)0x3B)
#define PORTB (*(volatile u8*)0x38)
#define PORTC (*(volatile u8*)0x35)
#define PORTD (*(volatile u8*)0x32)

//PIN Addresses
#define PINA (*(volatile u8*)0x39)
#define PINB (*(volatile u8*)0x36)
#define PINC (*(volatile u8*)0x33)
#define PIND (*(volatile u8*)0x30)

//ADC Registers
#define ADMUX (*(volatile u8*)0x27)
#define ADCSRA (*(volatile u8*)0x26)
#define ADCH (*(volatile u8*)0x25)
#define ADCL (*(volatile u8*)0x24)
#define SFIOR (*(volatile u8*)0x50)
#define ADC (*(volatile u16*)0x24)

//Interrupt Registers
#define MCUCR (*(volatile u8*)0x55)
#define MCUCSR (*(volatile u8*)0x54)
#define SREG (*(volatile u8*)0x5F)
#define GICR (*(volatile u8*)0x5B)
#define GIFR (*(volatile u8*)0x5A)

//Timer Registers
#define TCCR0 (*(volatile u8*)0x53)
#define TCNT0 (*(volatile u8*)0x52)
#define TIMSK (*(volatile u8*)0x59)
#define OCR0 (*(volatile u8*)0x5C)

#define TCCR1A (*(volatile u8*)0x4F)
#define TCCR1B (*(volatile u8*)0x4E)
#define TCNT1H (*(volatile u8*)0x4D)
#define TCNT1L (*(volatile u8*)0x4C)
#define OCR1AH (*(volatile u8*)0x4B)
#define OCR1AL (*(volatile u8*)0x4A)
#define OCR1BH (*(volatile u8*)0x49)
#define OCR1BL (*(volatile u8*)0x48)
#define ICR1H (*(volatile u8*)0x47)
#define ICR1L (*(volatile u16*)0x46)
#define TIFR (*(volatile u8*)0x58)

//UART Registers
#define UDR (*(volatile u8*)0x2C)
#define UCSRA (*(volatile u8*)0x2B)
#define UCSRB (*(volatile u8*)0x2A)
#define UCSRC (*(volatile u8*)0x40)
#define UBRRH (*(volatile u8*)0x40)
#define UBRRL (*(volatile u8*)0x29)

#endif /* REGISTERS_H_ */
