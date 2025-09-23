#ifndef __COM_UTIL_H__
#define __COM_UTIL_H__
#include "STC89C5xRC.H"
#include "Com_GPIO.h"
#include <INTRINS.H>
#include <stddef.h>  
typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;

void Com_Util_Delay1ms(u16 count);
void Com_Util_Delay480us(void);
void Com_Util_Delay60us(void);
void Com_Util_Delay420us(void);
void Com_Util_Delay10us(void);
void Com_Util_Delay50us(void);
#endif // !1