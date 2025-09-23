#include "Int_Buzzer.h"
#include "Dri_Timer2.h"
static u16 buzz_count=0;

void Int_Buzzer_CallBack(){

    if (buzz_count)
    {
        /* code */
        buzz_count--;
        BUZZER_EN = ~ BUZZER_EN;
    }
    else{
        BUZZER_EN = 0;
    }
    

}

void Int_Buzzer_init()
{
    buzz_count = 0;
    Dri_Timer2_Register(Int_Buzzer_CallBack);
}



void Int_Buzzer_Buzz(u16 ms)
{
    buzz_count = ms;
    

}
