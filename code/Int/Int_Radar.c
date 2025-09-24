#include "Int_Radar.h"
#include "Com_Util.h"

static u8 s_radar_allow_count=0;
static bit s_echo_is_complete=0;
void Int_Radar_CallBack(){
     
    if (s_radar_allow_count<100)
    {
        /* code */
        s_radar_allow_count++;
    }
    
}


void Int_Radar_init(){
     //1 设置模式
     //1.1配置 TCON 控制寄存器
     ECHO = 0;     //高电平启动定时器，低电平停止定时器
     TRIG = 0;
     TR0 = 1;
     IT0 = 1; //下降沿触发


     //1.2配置 TMOD 模式寄存器  16位计数
      
     TMOD = TMOD & 0XF0;
     TMOD = TMOD | 0x09;

     //2 初始值
     TL0 = 0;
     TH0 = 0;
     //3使能中断
    EA = 1;
    EX0 = 1;

    PX0 = 1; //设置中断优先级
    Dri_Timer2_Register(Int_Radar_CallBack);

}

u16 Int_Radar_Getdistance(){
    u16 tim0;
    u16 s_distance=0;
    //1 能够重新发送测距信息
    if (s_radar_allow_count == 100)
    {
        /* code */
        TRIG = 1;
        Com_Util_Delay10us();
        TRIG = 0;
        s_radar_allow_count = 0;
        
    }
    //2 正在测距中,不会有任何反应


    //3 测距完成, echo出现下降沿的时候，测距就完成了，此时有一个标记就是，出发了外部中断0 
    if (s_echo_is_complete){
        tim0= (TH0 << 8) + TL0;
        

        // 1个机器周期 = 1/(11.0592MHz/12) = 1/921600 s
        // distance =  1/921600 * 170m/s 
        // distance = 1/921600 * 170000mm/s = 0.1844 mm/s   因为51单片机计算浮点数不准， 直接把 0.1844近似于 2/11 = 0.1818
        // 因此最终距离公式，   distance = tim0 * 2 / 11

        // distance = tim0*340/2
        s_distance = tim0 * 2 / 11;

        s_echo_is_complete = 0;
        TH0 = 0;
        TL0 = 0;
        return s_distance;
        
        
    }


}


void Int_Radar_measure_complete() interrupt 0 {

    s_echo_is_complete = 1;

}

