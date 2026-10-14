#include "spr.h"
struct Spr { char pad[0xC34]; void *p; char pad2[0x408]; char data[1]; };
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void *func_004A7B60(const void *src, int n) {
    Spr *p = (Spr *)spr_base();
    void *dest = (void *)p->data;
    p->p = dest;
    return func_005A4724(dest, src, n << 6);
}
