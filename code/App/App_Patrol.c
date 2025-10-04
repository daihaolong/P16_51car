#include "App_Patrol.h"

#define KP 1000
#define KI 1
#define KD 1

static int s_sum_error = 0;
static int s_last_error = 0;

static int App_Patrol_GetPID(){
    
    int result = 0 ;
    int error = Int_Sensor_GetError();
    int diff_error = 0;

    s_sum_error += error;
    if (s_sum_error > 2000)
    {
        /* code */
        s_sum_error  = 2000;
    }
    else if (s_sum_error < -2000)
    {
        s_sum_error  = -2000;
    }

    diff_error = error - s_last_error;
    s_last_error = error;

    result = (error * KP + s_sum_error * KI + diff_error * KD) / 50;

    if (result > 80)
    {
        /* code */
        result = 80;
    }
    else if(result < -80){
        result = -80;
    }

    return result;
    
}


void App_Patrol_Control()
{
    int pid = App_Patrol_GetPID();
    Int_Motor_SetLeftSpeed(40+pid);
    Int_Motor_SetRightSpeed(40-pid);

}