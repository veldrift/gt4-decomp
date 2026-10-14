/* compiler: ee-gcc2.96-nogcse */
#include "spr.h"
struct S { char pad[0x20]; int handle, width, height; };
struct Dev { char pad[0x1f8]; int cursor; };
extern "C" void func_00497200(int,int,int) throw();
extern "C" void func_004973B8(S *,int) throw();
extern "C" void func_0049FE28();
extern "C" void func_004976D0(S *p, int idx) {
    Dev *d = (Dev *)spr_base();
    if (idx < 2) return;
    if (idx >= 0x12) return func_004973B8(p,idx);
    func_00497200(p->handle,p->width,p->height);
    func_0049FE28();
    int *q = (int *)d->cursor;
    q[0] = 0x50000000;
    q[1] = *(int *)((char *)p + idx * 4 + 0x34);
    q[2] = 0;
    q[3] = 0;
    d->cursor = (int)(q + 4);
}
