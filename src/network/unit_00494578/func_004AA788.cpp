#include "spr.h"
struct E { int a, b, value, d, key; };
struct S { char pad0[0xc38]; E entries[32]; char padEB8[6]; signed char index; char padEBF[5]; int other; };
extern "C" void func_004AAD78(S *, int);
extern "C" int func_004AAF38(S *, int);
extern "C" int func_004AA788(int key) {
    S *s = (S *)spr_base();
    if (key != 0 && key != s->other) {
        int i = s->index;
        if (i >= 0) {
            if (s->entries[i].key == key) return s->entries[i].value;
        }
        i = func_004AAF38(s, key);
        if (i >= 0) {
            int prev = s->index;
            if (prev >= 0) { func_004AAD78(s, prev); s->index = -1; }
            s->index = i;
            return s->entries[i].value;
        }
    }
    s->other = key;
    return -1;
}
