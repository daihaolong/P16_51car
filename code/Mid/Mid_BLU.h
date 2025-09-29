#ifndef __MID_BLU_H__
#define __MID_BLU_H__
#include "Int_UART.h"

void Mid_BLU_SendByte(char byte);
void Mid_BLU_SendBytes(char *byte);

bit Mid_BLU_ReciveBytes(char *byte);


#endif /* __MID_BLU_H__ */