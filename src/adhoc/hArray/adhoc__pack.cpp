typedef int s32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; int pad[3]; };
struct H { s32 p; s32 pad[3]; };
struct VEntryB { short delta; short index; void (*fn)(Str *, void *); };
struct Obj { char pad0[4]; char *vtbl; };
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_002ED5C0(void *, int) throw();
extern "C" void func_002ED618(void *) throw();
extern "C" void func_002EF1C8(Str *, s32, Str *);
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

extern "C" void adhoc__pack(s32 *self, s32 unused, s32 flag, Obj **arg3) {
    if (flag == 1) {
        H it;
        H h;
        Str s20;
        Str s30;
        func_002ED618(&it);
        Obj *o = *arg3;
        s32 itp = it.p;
        Str *ps30 = &s30;
        VEntryB *e = (VEntryB *)(o->vtbl + 0x18);
        Str *ps20 = &s20;
        e->fn(ps30, (char *)o + e->delta);
        func_002EF1C8(ps20, itp, ps30);
        H *ph = &h;
        func_00314B20(ph, ps20);
        if (self != (s32 *)ph) {
            s32 nv = ph->p;
            if (nv) func_003285A8(nv);
            if (*self) func_003285F8(*self);
            *self = nv;
        }
        func_00312318(ph, 2);
        {
            Rep *q = (Rep *)ps20->p - 1;
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        {
            Rep *q = (Rep *)ps30->p - 1;
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        func_002ED5C0(&it, 2);
    }
}
