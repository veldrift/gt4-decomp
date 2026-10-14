/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; };
struct Z { char *p; char pad[0x1C]; };
struct Z2 { char *p; char pad[0xC]; };

struct VEnt {
    short adj;
    short pad;
    void (*fn)(Z *, void *);
};
struct VTab {
    char pad[0x18];
    VEnt e;
};
struct Obj {
    char pad0[4];
    VTab *vt;
};

extern Rep D_00659FA8;

extern "C" void func_00248BF0(void *, int) throw();
extern "C" int func_00248C48(void *, void *);
extern "C" void func_00249EE8(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);

struct Frame {
    Z z0;
    Str s20;
    char padx[0xC];
    Z2 z30;
};

extern "C" void MToolTipFace__set_value(void *a0, void *arg1, void *a2, Obj **pp) {
    Frame f;
    Obj *o = *pp;
    if (o == 0) {
        char *zp;
        Str *ps;
        func_00248C48(&f.z0, arg1);
        zp = f.z0.p;
        ps = &f.s20;
        {
            Rep *r = &D_00659FA8;
            char *p;
            if (r->sel != 0) {
                p = func_005C2560(r);
            } else {
                r->ref++;
                p = (char *)(r + 1);
            }
            ps->p = p;
        }
        func_00249EE8(zp, ps);
        {
            Rep *q = (Rep *)(ps->p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        func_00248BF0(&f.z0, 2);
        return;
    }
    {
        VEnt *e = &o->vt->e;
        e->fn(&f.z0, (char *)o + e->adj);
    }
    Z2 *pz = &f.z30;
    func_00248C48(pz, arg1);
    func_00249EE8(pz->p, &f.z0);
    func_00248BF0(pz, 2);
    {
        Rep *q = (Rep *)(f.z0.p - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
}
