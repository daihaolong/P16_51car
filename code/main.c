#include "Int_OLED.h"
#include "Int_Radar.h"
#include "STDIO.H"


void main()
{   u16 dis;
    char buffer[17];
    Dri_Timer2_init(); 
    Int_OLED_Init();
    Int_OLED_Clear();
    Int_Radar_init();
    while (1) {
             dis = Int_Radar_Getdistance();
             Com_Util_Delay1ms(500);
             sprintf(buffer, "dis %4d mm", dis);
             Int_OLED_ShowStr(0,0,buffer);    
            }
}