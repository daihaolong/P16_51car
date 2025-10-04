#include "App_Patrol.h"


void main()
{   
    Dri_Timer2_init();
    Int_Motor_Init();
    while (1)
    {
        
        App_Patrol_Control();
        
    }
       
    
    
}