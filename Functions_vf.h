#include <Windows.h>
#include <math.h>
#include <d2d1.h>
#include "Constants.h"

class Functions_vf
{
public:
    virtual void RunFunction(int cx, int cy, D2D1_POINT_2F* apt) = 0;
    virtual ~Functions_vf() {}
};
