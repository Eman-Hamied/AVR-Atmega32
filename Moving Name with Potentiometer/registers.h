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





#endif /* REGISTERS_H_ */
