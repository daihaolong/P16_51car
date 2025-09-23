#include "Dri_Timer2.h"
#include "Com_Util.h"
#define MAX_CALL_COUNT 4

static u8 s_call_count = 0;
static Timer2Callback s_timer_call[MAX_CALL_COUNT];

void Dri_Timer2_init()
{
    
    //1 配置定时器工作模式
    //1.1 控制寄存器
    RCLK = 0;
    TCLK = 0;
    C_T2 = 0;
    
    //1.2 模式寄存器
    T2MOD = 0X00;


    //2 设置初始值 重装载值 = 65536 - (定时时长 × 晶振频率 / 12)
    // 65536 - ((0.001S)*11.0592*1000000Hz / 12) = 56320
    // 65536 - 921.6 = 64615
    TL2 = 64615;
    TH2 = 64615>>8;

    RCAP2L = 64615;
    RCAP2H = 64615>>8;
    

    //3 使能总中断
    EA = 1;
    
    //4 使能定时器2
    ET2 = 1;
    // 5 启动定时器
    TR2 = 1;

}


bit Dri_Timer2_Register(Timer2Callback callback)
{   u8 i;
    if (s_call_count > MAX_CALL_COUNT)
    {
        /* code */
        return 0;
    }
    for ( i = 0; i < MAX_CALL_COUNT; i++)
    {
        /* code */
        if (s_timer_call[i] == callback)
        {
            /* code */
            return 1;
        }
        
    }

    s_timer_call[s_call_count++] = callback;
    
    return 1;
    
}

bit Dri_Timer2_Deregister(Timer2Callback callback)
{   u8 i;

    for ( i = 0; i < MAX_CALL_COUNT; i++)
    {
        /* code */
        if (s_timer_call[i] == callback)
        {
            /* code */
            s_timer_call[i] = NULL;
            return 1;
        }
    }
    
    return 0;
}


void Timer2Handle() interrupt 5 {
    u8 i;
    TF2 = 0;

         for ( i = 0; i < MAX_CALL_COUNT; i++)
         {
            /* code */
            if (s_timer_call[i] != NULL)
            {
                /* code */
                s_timer_call[i]();
            }
            
         }
            

}