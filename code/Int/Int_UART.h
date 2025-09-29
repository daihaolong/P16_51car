#ifndef __INT_UART_H__
#define __INT_UART_H__
#include "Com_Util.h"
#include "Dri_Timer2.h"
void Int_UART_init();

void Int_UART_SendByte(char byte);
void Int_UART_SendBytes(char *byte);


bit Int_UART_ReciveBytes(char *byte);


#endif /* __INT_UART_H__ */