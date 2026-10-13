typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Heap {
    const char *name;
};

/* 16-byte String slot: dat pointer, padded to the 0x10 stack stride */
struct Slot {
    char *p;
    s32 pad[3];
};

struct VEntry3 {
    short delta;
    short index;
    void (*fn)(void *self, void *a, void *b);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern Rep D_00659FA8;

extern "C" void mSceneViewFace__virtual_63(void);
extern "C" s32 func_0025C110(void *arg0);
extern "C" void func_00229D18(void *out, s32 v);
extern "C" const char *hModule__getName(void *arg0);
extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s);
extern "C" Slot *func_005C2630(Slot *str, s32 pos, s32 n1, const char *s, s32 n2);
extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

extern "C" void mRootWindow__virtual_63(Obj *arg0, Obj *arg1) {
    Slot a;
    Slot b;
    mSceneViewFace__virtual_63();
    if (*(s32 *)((char *)arg0 + 0xE8) & 0x10) {
        func_00229D18(&a, func_0025C110(arg0));
        Slot *ps = &b;
        const char *src = hModule__getName(arg0);
        {
            Rep *r = &D_00659FA8;
            char *d;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                d = (char *)(r + 1);
                r->ref++;
            }
            ps->p = d;
            func_005C2630(ps, 0, -1, src, func_0057F260(src));
        }
        {
            VEntry3 *e = (VEntry3 *)(arg1->vtbl + 0x1B0);
            e->fn((char *)arg1 + e->delta, &a, ps);
        }
        {
            Rep *q = (Rep *)(ps->p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        {
            Rep *q = (Rep *)(a.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
}
