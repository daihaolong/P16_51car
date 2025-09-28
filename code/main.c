#include "Int_UART.h"


void main()
{   
    char c;
    Int_UART_init();
    


    while (1)
    {
        if (Int_UART_ReciveByte(&c))
        {
            /* code */
            switch (c)
            {
            case 'a':
                /* code */
                Int_UART_SendBytes("left");
                break;
            case 's':
                /* code */
                Int_UART_SendBytes("down");
                break;
            case 'd':
                /* code */
                Int_UART_SendBytes("right");
                break;
            case 'w':
                /* code */
                Int_UART_SendBytes("up");
                break;
            default:
                break;
            }
            
            
        }
        
    }
    
    
}