#include "spr.h"
extern "C" int func_0049BE10(void *, int, int, int, int, int, int) throw();
extern unsigned char D_00624C70;
int func_0049C0D8(int a,int b,int c,int d,int e,int f) {
    void *p = (void *)spr_base();
    if (D_00624C70) return func_0049BE10(p,a,b,c,d,e,f);
}
