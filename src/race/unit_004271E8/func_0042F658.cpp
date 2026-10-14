/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef long s64;
struct R16 { char x[16]; };
struct R4 { char x[4]; };
struct Ent { s64 a; s64 b; };
struct List { s32 count; char pad[12]; Ent items[1]; };
struct VT { short off; short pad; int (*fn)(void *, void *); };
struct Obj {
    VT **vtbl;
    char pad4[4];
    List list;
};
struct Obj2 { char pad[0xB6C0]; R4 tail; };
extern "C" void func_00600A18(void *, s32);

extern "C" int func_0042F658(Obj *self, char *src) {
    R4 c = *(R4 *)src;
    R16 r;
    Ent *pe = (Ent *)&r;
    s32 i = 0;
    char *p = src + 4;
    List *l = &self->list;
    for (; i < 0xB6A; i++, p += 16) {
        if (i < *(s32 *)&c) {
            r = *(R16 *)p;
            Ent *dst = &l->items[l->count];
            dst->a = pe->a;
            dst->b = ((Ent *)&r)->b;
            func_00600A18(l, 1);
        }
    }
    ((Obj2 *)self)->tail = *(R4 *)p;
    VT *vt = (VT *)((char *)*(void **)self + 0x20);
    return vt->fn((char *)self + vt->off, src);
}
