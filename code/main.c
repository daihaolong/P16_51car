#include "Dri_Timer2.h"
#include "Int_Buzzer.h"

void main()
{   
    Dri_Timer2_init();
    Int_Buzzer_init();
    Int_Buzzer_Buzz(3000);
    
    while (1) {

    }
}