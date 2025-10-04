#ifndef __INT_LIGHTSENSOR_H__
#define __INT_LIGHTSENSOR_H__

#include "Com_Util.h"


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
int Int_Sensor_GetError(void);



#endif /* __INT_LIGHTSENSOR_H__ */