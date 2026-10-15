/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
struct Spr { int p[5]; int enabled; int mode; };
extern "C" void func_0049C2A8(char *, char *, char *, int, int) throw();
extern "C" void func_0049C6C8(int count, char *a, char *b, char *c) {
    Spr *spr = (Spr *)spr_base();
    int k = 2;
    if (spr->enabled != 0 && count != 0) {
        spr->mode = 0x16;
        if (count > 0) do {
            int n = count;
            if (n > 20) n = 20;
            func_0049C2A8(a,c,b,n,k--);
            count -= 20;
            if (a) a += 0x1e0;
            if (c) c += 0x50;
            if (b) b += 0x1e0;
        } while (count > 0);
    }
}
