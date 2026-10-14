#include "spr.h"
struct V4 { float x, y, z, w; };
struct Sp { char pad[0xBA0]; V4 v[3]; };
extern "C" int func_0049F318(unsigned int sel, V4 *src) {
    register Sp *sp = (Sp *)spr_base();
    switch (sel) {
    case 0:
        sp->v[0].x = src->x;
        sp->v[0].y = src->y;
        sp->v[0].z = src->z;
        sp->v[0].w = src->w;
        break;
    case 2:
        sp->v[1].x = src->x;
        sp->v[1].y = src->y;
        sp->v[1].z = src->z;
        sp->v[1].w = src->w;
        break;
    case 3:
        sp->v[2].x = src->x;
        sp->v[2].y = src->y;
        sp->v[2].z = src->z;
        sp->v[2].w = src->w;
        break;
    }
}
