#pragma once
#include "Functions_vf.h"
class Parabola :
    public Functions_vf
{
public:
    void RunFunction(int cx, int cy, D2D1_POINT_2F* apt) {
        double x, coeff;
        coeff = 2.0 * cy / cx;
        for (int i = 0; i < NUM; i++)
        {
            x = i * cx / NUM;
            apt[i].x = x;
            apt[i].y = (int)(coeff * (-x * x / cx + x));
        }
    }
};

