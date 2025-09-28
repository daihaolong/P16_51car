#include "Int_UART.h"

static bit s_is_sending = 0;
static char s_recive_buffer = 0;

void Int_UART_init(){

    //设置工作模式
    SM0 = 0;
    SM1 = 1;
    PCON = PCON & 0x7f;
    SM2 = 0;
    REN = 1;
    TMOD = TMOD & 0X0F;
    TMOD = TMOD | 0X2F;
    TH1 = 253;
    TL1 = 253;
    TR1 = 1;
    EA = 1;
    ES = 1;


}

void Int_UART_SendByte(char byte){
 
    while (s_is_sending);
    SBUF = byte;
    s_is_sending = 1;
}



void Int_UART_SendBytes(char *byte){

     while (*byte != '\0')
     {
        /* code */
        Int_UART_SendByte(*byte);
        byte++;
     }
     

}


bit Int_UART_ReciveByte(char *c){  
    
    if (s_recive_buffer)
    {
       *c = s_recive_buffer;
       s_recive_buffer = 0;
       return 1;
    }
    else{return 0;}
    
    

}
void Int_UART_ReciveBytes(char *byte){
    

}



void Int_UART_interruptHandler() interrupt 4{
//另外RI和TI标志位，只能由软件复位，也就是需要在中断服务程序中将其设置为0

    if (TI)
    {
        /* code */

       s_is_sending = 0;
       TI = 0 ;

    }

    if (RI)
    {
        /* code */
        s_recive_buffer = SBUF;
        RI = 0;
        
        
    }
    

}