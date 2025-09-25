#include "Int_Motor.h"


void main()
{   
    
    Dri_Timer2_init();
    Int_Motor_Init();
    Int_Motor_SetLeftSpeed(10);
    Int_Motor_SetRightSpeed(10);
    Com_Util_Delay1ms(3000);

    Int_Motor_SetLeftSpeed(-10);
    Int_Motor_SetRightSpeed(-10);
    Com_Util_Delay1ms(3000);

    //右转
    Int_Motor_SetLeftSpeed(10);
    Int_Motor_SetRightSpeed(-10);
    Com_Util_Delay1ms(3000);

    //左转
    Int_Motor_SetLeftSpeed(-10);
    Int_Motor_SetRightSpeed(10);

    while (1)
    {
        /* code */
    }
    
    
}