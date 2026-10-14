#include "spr.h"
struct Rec { unsigned addr; unsigned data; unsigned short a,b; };
struct Obj { char pad[0x16]; unsigned short count; char pad18[4]; Rec *records; };
struct Spr { char pad[0x1fc]; int cursor; char pad200[8]; unsigned tag; char pad20c[0x1030-0x20c]; int total; };
extern "C" int func_004A4CA8(char *, void *, int, int, unsigned short, unsigned short);
static inline char *allocate(Spr *spr, int amount) {
 int value = spr->cursor - amount - 16;
 spr->cursor = value;
 return (char *)value;
}
extern "C" void func_00499508(Obj *obj) {
    Spr *spr = (Spr *)spr_base();
    int n = obj->count;
    char *out = allocate(spr, n << 7);
    *(unsigned *)spr->tag = (unsigned)out & 0x0fffffff;
    for (int i = 0; i < n; i++) {
        Rec *rec = &obj->records[i];
        int size = func_004A4CA8(out+16, &rec->data, 0, 0, rec->a, rec->b);
        if (size) {
            spr->total += size;
            *(unsigned *)out = 0x10000006;
            out += 0x70;
            *(unsigned *)out = size | 0x30000000;
            *(unsigned *)(out+4) = rec->addr & 0x0fffffff;
            out += 16;
        }
    }
    *(unsigned *)out = 0x20000000;
    spr->tag = (unsigned)(out+4);
}
