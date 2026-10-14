#include "spr.h"
struct Spr {
    char pad[0x24C];
    unsigned short base;
    unsigned char pitch, psm;
    int width, height;
    unsigned short x0, y0, x1, y1;
};
static inline void set_right(Spr *p, int x1, int psm) {
    p->psm = psm;
    p->x1 = x1;
}
extern "C" void func_004A2410(unsigned int base, int psm, int width, int height) {
    int x = (0x800 - (width >> 1)) << 4;
    int y = (0x800 - (height >> 1)) << 4;
    Spr *p = (Spr *)spr_base();
    p->width = width;
    p->height = height;
    p->x0 = x;
    p->y0 = y;
    int ye = y + (height << 4);
    p->x1 = x + (width << 4);
    p->y1 = ye;
    p->base = base >> 6;
    p->pitch = width >> 6;
    p->psm = psm;
}
