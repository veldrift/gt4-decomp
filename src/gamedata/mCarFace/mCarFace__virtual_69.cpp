/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned int u32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct Obj16 {
    char pad[0x10];
};

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VObj {
    char pad[4];
    char *vtbl;
    char pad8[0x8C];
    s32 f94;
};

struct Self {
    char pad0[0xA0];
    char fA0[0x30];
    char fD0[0x68];
    char f138[0x168];
    s32 f2A0;
    VObj *f2A4;
    VObj *f2AC_pad;
};

struct Self2 {
    char pad0[0xA0];
    char fA0[0x30];
    char fD0[0x68];
    char f138[0x168];
    s32 f2A0;
    VObj *f2A4;
    s32 f2A8;
    VObj *f2AC;
    s32 f2B0;
};

extern Rep D_00659FA8;
extern char D_0068EE38[];

extern "C" void func_00153BB8(void *, void *);
extern "C" void func_00154320(void *, float);
extern "C" s32 func_001FCAF8(void *);
extern "C" void func_0021CF60(void *, void *, void *, void *);
extern "C" void func_002319A0(void *, void *);
extern "C" void func_00239F08(void *, int);
extern "C" void func_0023A538(void *, void *, void *, void *, void *);
extern "C" void mColorChipFace__virtual_69(void *, void *, s32);
extern "C" void func_002ED5C0(void *, int);
extern "C" void func_002EFBF0(void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(Str *, u32, u32, const char *, u32);

static inline s32 vcall98(VObj *o) {
    VEntry *e = (VEntry *)(o->vtbl + 0x98);
    return e->fn((char *)o + e->delta);
}

extern "C" void mCarFace__virtual_69(Self2 *arg0, void *arg1, s32 arg2) {
    Obj16 res;
    Obj16 pad1;
    Obj16 pad2;
    mColorChipFace__virtual_69(arg0, arg1, 0);
    if (arg2 != 0) {
        VObj **pa = &arg0->f2A4;
        VObj *a = *pa;
        if (a != 0 && vcall98(a) != 0) {
            VObj **pb = &arg0->f2AC;
            VObj *b = *pb;
            if (b != 0 && vcall98(b) != 0) {
                s32 r = func_001FCAF8(*pb);
                func_0021CF60(*pb, arg0->fD0, arg0->f138, arg0->fA0);
                func_00154320(*pa, 1.0f);
                if (r != 0) {
                    if (arg0->f2B0 == 0) {
                        Str s;
                        Obj16 h;
                        Str *ps = &s;
                        const char *src = D_0068EE38;
                        {
                            Rep *rr = &D_00659FA8;
                            char *d;
                            if (rr->sel != 0) {
                                d = func_005C2560(rr);
                            } else {
                                d = (char *)(rr + 1);
                                rr->ref++;
                            }
                            ps->p = d;
                        }
                        func_005C2630(ps, 0, -1, src, func_0057F260(src));
                        func_002EFBF0(&h);
                        func_0023A538(&res, arg1, arg0, ps, &h);
                        func_002319A0(arg1, &res);
                        func_00239F08(&res, 2);
                        func_002ED5C0(&h, 2);
                        {
                            Rep *q = (Rep *)(ps->p - 0x10);
                            if (--q->ref == 0) {
                                s32 size = q->cap + 0x10;
                                func_00326798(q, size, 4, func_005C11A8()->name);
                            }
                        }
                        arg0->f2B0 = 1;
                    }
                }
            } else {
                func_00153BB8(*pa, arg0->fA0);
                (*pa)->f94 = (arg0->f2A0 == 1);
            }
        }
    }
}
