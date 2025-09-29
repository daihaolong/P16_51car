#include "App_auto_avoid.h"
#include "Com_Util.h"
#include "Int_OLED.h"
#include "Int_Radar.h"
#include <STDIO.H>
void main()
{   
    
    App_auto_avoid_init();
    while (1)
    {
        App_auto_avoid();
    }
       
    
    
}