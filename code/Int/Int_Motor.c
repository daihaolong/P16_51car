#include "Int_Motor.h"
#include "MATH.H"
static char s_motor_count=0;
static char s_motor_left_speed = 0;
static char s_motor_right_speed = 0;
static bit s_motor_leaf_navigator = 1;
static bit s_motor_right_navigator = 1;

// 考虑如何输出正确占空比的PWM方波对应填写的速度控制电机，电机的承受的频率不到几十HZ
// 1ms 执行一次这个函数,就是让这个函数输出PWM方波的  
// 40ms 一个周期  25Hz , 占空比 xms/40 
// 设置正确的占空比


void Int_Motor_Timer2_callback(){

if (s_motor_count < s_motor_left_speed)
{
    /* code */
    MOTOR_A1 = s_motor_leaf_navigator;
    MOTOR_A2 = ~s_motor_leaf_navigator;
}
else{
    MOTOR_A1 = 0;
    MOTOR_A2 = 0;
}

if (s_motor_count < s_motor_right_speed)
{
    /* code */
    MOTOR_B1 = ~s_motor_right_navigator;
    MOTOR_B2 = s_motor_right_navigator;
}
else{
    MOTOR_B1 = 0;
    MOTOR_B2 = 0;
}


// s_motor_count的值表示处于一个周期的哪一个毫秒
s_motor_count++;
if (s_motor_count==40)
{
    /* code */
    s_motor_count = 0;
}


}




void Int_Motor_Init()
{   
    MOTOR_EN = 1;
    MOTOR_FAULT = 1;

    MOTOR_A1 = 0;
    MOTOR_A2 = 0;
    MOTOR_B1 = 0;
    MOTOR_B2 = 0;
    

    //使用定时器2处理稳定的周期40ms
    Dri_Timer2_Register(Int_Motor_Timer2_callback);
    
}




void Int_Motor_SetLeftSpeed(char speed)
{
    if (speed>40)
    {
        /* code */
        speed = 40;
    }
    if (speed < -40)
    {
        /* code */
        speed = -40;
    }
    
    
    s_motor_leaf_navigator = (speed>0);
    s_motor_left_speed = abs(speed);


}

void Int_Motor_SetRightSpeed(char speed)
{

    if (speed>40)
    {
        /* code */
        speed = 40;
    }
    if (speed < -40)
    {
        /* code */
        speed = -40;
    }
    s_motor_right_navigator = (speed > 0);
    s_motor_right_speed = abs(speed);
}
