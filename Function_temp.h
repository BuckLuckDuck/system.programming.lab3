#pragma once
#include "Functions_vf.h"
class Function_temp
{
public:
    Function_temp(Functions_vf* func) : p(func) { }
    ~Function_temp() { delete p; }
    void SetFunc(Functions_vf* func) { p = func; }
    void RunFunction(int cx, int cy, D2D1_POINT_2F* apt) {
        return p->RunFunction(cx, cy, apt);
    }
private:
    Functions_vf* p;
};

