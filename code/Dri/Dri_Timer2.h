#ifndef __DRI_TIMER2_H__
#define __DRI_TIMER2_H__


typedef void (* Timer2Callback)(void);

/*

*/
void Dri_Timer2_init();

/**
 * @brief 注册回调函数
 * 
 * 
 */
bit Dri_Timer2_Register(Timer2Callback callback);


/**
 * @brief 取消注册回调函数
 * 
 */
bit Dri_Timer2_Deregister(Timer2Callback callback);

#endif /* __DRI_TIMER2_H__ */