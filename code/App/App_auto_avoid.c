#include "App_auto_avoid.h"
#include "Int_Motor.h"
#include "Int_Radar.h"
#include "Int_OLED.h"
#include <STDIO.H>
void App_auto_avoid_init(){

    Dri_Timer2_init();
    Int_Radar_init();
    Int_Motor_Init();
    

}

void App_auto_avoid()
{
    
    

    if (Int_Radar_Getdistance()<300)
    {
        /* code */
        Int_Motor_SetLeftSpeed(40);
        Int_Motor_SetRightSpeed(-40);

    }
    else
    {
        /* code */
        Int_Motor_SetLeftSpeed(40);
        Int_Motor_SetRightSpeed(40);
    }
    
    

    
}