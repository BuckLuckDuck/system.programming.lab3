#pragma once
#include "Functions_vf.h"
class Sinusoid :
    public Functions_vf
{
public:
    void RunFunction(int cx, int cy, D2D1_POINT_2F* apt) 
    {
        for (int i = 0; i < NUM; i++)
        {
            apt[i].x = i * cx / NUM;
            apt[i].y = (int)(cy / 2 * (1 - sin(PI_SQUARE * i / NUM)));
        }
    }
};

