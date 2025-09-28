#include "Int_UART.h"
#include "Dri_Timer2.h"

void main()
{   
    char bytes[16];
    Dri_Timer2_init();
    Int_UART_init();
    
    while (1)
    {
        if (Int_UART_ReciveBytes(bytes))
        {
            /* code */
            Int_UART_SendBytes(bytes);

            
        }
        

    }
       
    
    
}