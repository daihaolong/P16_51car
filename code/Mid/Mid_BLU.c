#include "Mid_BLU.h"

void Mid_BLU_SendByte(char byte)
{
    Int_UART_SendByte(byte);

}

void Mid_BLU_SendBytes(char *byte)
{
    Int_UART_SendBytes(byte);
}



bit Mid_BLU_ReciveBytes(char *byte)
{
    if (Int_UART_ReciveBytes(byte))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}
