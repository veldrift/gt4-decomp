#include "spr.h"
struct Dev { char pad[0x1f8]; int cur; };
extern "C" void *func_004A5B90(int n) {
    Dev *d = (Dev *)spr_base();
    int *p = (int *)d->cur;
    if (n) {
        p[0] = n | 0x10000000;
        p[2] = 0x11000000;
        p[3] = n | 0x50000000;
        p[1] = 0;
        n *= 0x10;
        d->cur = d->cur + n + 0x10;
    }
    return p + 4;
}
