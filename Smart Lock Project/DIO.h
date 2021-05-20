#ifndef DIO_H_
#define DIO_H_

void DIO_vidSetPinDirection(u8 port , u8 pin, u8 dir);
void DIO_vidWritePinValue(u8 port, u8 pin, u8 value);
u8 DIO_u8ReadPinValue(u8 port, u8 pin);
void DIO_vidWritePort(u8 port, u8 value);
void DIO_vidSetPortDirection(u8 port, u8 dir);

#endif /* DIO_H_ */
