#include "Int_LightSensor.h"


/**
 * @brief 获取偏差值
 * 1. MM 和 LM    -1
 * 2. LM          -2
 * 3. LL 和 LM    -3
 * 4. LL          -4
 * 
 * 正数是偏左
 * 负数是偏右
 * 绝对值是偏差幅度
 * 
 * 
 * @return char 返回扫描到黑线的编号平均值
 */

int Int_Sensor_GetError(void)
{
    u8 count = 0;
    int error = 0;
    if (PATROL_LL)
    {
        /* code */
        error -= 4;
        count++;

    }
    if (PATROL_LM)
    {
        /* code */
        error -= 2;
        count++;
    }
    if (PATROL_MM)
    {
        /* code */
        error += 0;
        count++;
    }
    
    if (PATROL_RR)
    {
        /* code */
        error += 4;
        count++;
    }
    if (PATROL_RM)
    {
        /* code */
        error += 2;
        count++;
    }

    if (count)
    {
        /* code */
        
        return error / count;
    }
    else
    {
        return 0;
    }
    
    
    
    
}
