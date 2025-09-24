#ifndef __INT_RADAR_H__
#define __INT_RADAR_H__
#include "Com_Util.h"
#include "Dri_Timer2.h"
typedef void(*CallBack)(void);

void Int_Radar_init();
u16 Int_Radar_Getdistance();

#endif /* __INT_RADAR_H__ */