#pragma once
#include "Functions_vf.h"
class Square_root :
    public Functions_vf
{
public:
    void RunFunction(int cx, int cy, D2D1_POINT_2F* apt) {
        for (int i = 0; i < NUM; i++)
        {
            apt[i].x = cx / 2 + i * cx / (2 * NUM);
            apt[i].y = (int)(cy / 2 - sqrt(i) * cy / (2 * sqrt(NUM)));
        }
    }
};

