#include <Windows.h>
#include <math.h>
#include <d2d1.h>
#include "constants.h"
#include "Sinusoid.h"
#include "Square_root.h"
#include "Parabola.h"
#include "Hyperbola.h"
#include "Function_temp.h"

void Upd_Stage(HMENU menu, UINT_PTR curr, UINT_PTR* prev, Function_temp* handler) {
    EnableMenuItem(menu, curr, MF_GRAYED);
    EnableMenuItem(menu, *prev, MF_ENABLED);
    *prev = curr;
    Functions_vf* func = new Sinusoid;
    switch (curr) {
    case OPT_SINUSOID:
        func = new Sinusoid;
        break;
    case OPT_SQUARE_ROOT:
        func = new Square_root;
        break;
    case OPT_PARABOLA:
        func = new Parabola;
        break;
    case OPT_HYPERBOLA:
        func = new Hyperbola;
        break;
    }
    handler->SetFunc(func);
}