#include "Int_OLED.h"

void main()
{   
    Int_OLED_Init();
    Int_OLED_Clear();
    Int_OLED_ShowStr(0,0,"HELLO WORLD!");
    while (1) {

    }
}