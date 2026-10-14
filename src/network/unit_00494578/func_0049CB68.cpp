#include "spr.h"
struct Spr { char pad[0x14]; const int enabled; int mode; };
extern "C" void func_0049C788(char *, char *, char *, int, int) throw();
extern "C" int func_0049CB68(int n, char *a, char *b, char *c) {
    Spr *spr = (Spr *)spr_base();
    int en = spr->enabled;
    int remaining = n;
    int k = 2;
    if (en && remaining >= 3) {
        spr->mode = 22;
        do {
            int count = remaining < 65 ? remaining : 64;
            remaining -= 62;
            int index = k;
            k--;
            func_0049C788(a, c, b, count, index);
            a = a ? a + 0x1F0 : a;
            c = c ? c + 0xF8 : c;
            b = b ? b + 0x1F0 : b;
        } while (remaining >= 3);
    }
}
