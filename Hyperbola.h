#pragma once
#include "Functions_vf.h"
class Hyperbola :
    public Functions_vf
{
public:
    void RunFunction(int cx, int cy, D2D1_POINT_2F* apt) {
        double x, y, coeff;
        coeff = cx * cy / 64.0;
        for (int i = 0; i < NUM; i++)
        {
            x = i * (double)cx / NUM;
            if (i < NUM / 2 || i > NUM / 2) {
                y = (int)(-coeff / (x - cx / 2) + cy / 2);
            }
            else {
                y = cy / 2;
            }
            if (i < NUM / 2) {
                apt[i].x = x;
                apt[i].y = y;
            }
            else if (i > NUM / 2) {
                apt[i].x = x;
                apt[i].y = y;
            }
        }
    }
};

