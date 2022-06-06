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

class Hyperbola :
    public Functions_vf
{
public:
    void RunFunction(int cx, int cy, D2D1_POINT_2F* apt) {
        double x, y, coeff;
        coeff = cx * cy / 64.0;
        for (int i = 0; i < NUMBB; i++)
        {
            x = i * (double)cx / NUMBB;
            if (i < NUMBB / 2 || i > NUMBB / 2) {
                y = (int)(-coeff / (x - cx / 2) + cy / 2);
            }
            else {
                y = cy / 2;
            }
            if (i < NUMBB / 2) {
                apt[i].x = x;
                apt[i].y = y;
            }
            else if (i > NUMBB / 2) {
                apt[i].x = x;
                apt[i].y = y;
            }
        }
    }
};

class Parabola :
    public Functions_vf
{
public:
    void RunFunction(int cx, int cy, D2D1_POINT_2F* apt) {
        double x, coeff;
        coeff = 2.0 * cy / cx;
        for (int i = 0; i < NUMBB; i++)
        {
            x = i * cx / NUMBB;
            apt[i].x = x;
            apt[i].y = (int)(coeff * (-x * x / cx + x));
        }
    }
};

class Sinusoid :
    public Functions_vf
{
public:
    void RunFunction(int cx, int cy, D2D1_POINT_2F* apt)
    {
        for (int i = 0; i < NUMBB; i++)
        {
            apt[i].x = i * cx / NUMBB;
            apt[i].y = (int)(cy / 2 * (1 - sin(PI_SQUARE * i / NUMBB)));
        }
    }
};

class Square_root :
    public Functions_vf
{
public:
    void RunFunction(int cx, int cy, D2D1_POINT_2F* apt) {
        for (int i = 0; i < NUMBB; i++)
        {
            apt[i].x = cx / 2 + i * cx / (2 * NUMBB);
            apt[i].y = (int)(cy / 2 - sqrt(i) * cy / (2 * sqrt(NUMBB)));
        }
    }
};

