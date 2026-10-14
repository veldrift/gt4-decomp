#include "spr.h"
struct Entry { int value; int pad[4]; };
struct S { char pad[0xc40]; Entry entries[32]; char pad2[4]; void *last; };
extern "C" int func_004AAE50(S *, int, void *);
int func_004AA650(int a, void *b) {
    S *p = (S *)spr_base();
    int i = func_004AAE50(p, a, b);
    if (i >= 0) return p->entries[i].value;
    p->last = b;
    return -1;
}
