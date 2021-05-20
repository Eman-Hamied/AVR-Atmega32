/*
 * UART.h
 *
 *  Created on: Nov 4, 2019
 *      Author: Eman Abd El-Hamied
 */

#ifndef UART_H_
#define UART_H_


void UART_vidInit(void);
void UART_vidTransmit(u8 Data);
u8 UART_u8Receive(void);
void UART_voidSendString(u8 *string);
void UART_voidSendAsciiNumber(u32 x);
#endif /* UART_H_ */
