#include "Dri_Timer2.h"
#include "Com_Util.h"
static u16 s_counter=0;
void LED_Blink(){
    
    s_counter++;
    if (s_counter>=500)
    {
        /* code */
        s_counter = 0;
        LED1_BF = ~LED1_BF;

    }


}

void main()
{
    Dri_Timer2_init();
    Dri_Timer2_Register(LED_Blink);
    Com_Util_Delay1ms(3000);
    Dri_Timer2_Deregister(LED_Blink);
    while (1) {

    }
}