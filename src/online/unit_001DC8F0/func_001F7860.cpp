typedef int s32;

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

struct Info {
    char pad[0x94];
    void *f94;
    void *f98;
    void *f9C;
    void *fA0;
};

extern Rep D_00659FA8;
extern char D_00645570[];

extern "C" s32 func_001F1368(void *);
extern "C" void mUpdateContext__Sync(int);
extern "C" void func_002ED590(void *, void *);
extern "C" void func_002ED5A8(void *, void *);
extern "C" void func_002ED5C0(void *, int);
extern "C" void *func_002EEEB0(void *, void *, void *);
extern "C" void *func_002EFBF0(void *);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, void *);
extern "C" void func_00309378(void *, int);
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" s32 func_004FE8D0(void *);
extern "C" Info *func_004FEC48(void *);
extern "C" s32 func_0057F260(Info *);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(void *, s32, s32, Info *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void *func_001F7860(void *arg0, void *arg1) {
    Str sp0;
    char sp10[0x10];
    Str sp20;
    Str sp30;
    Str sp40;
    Str sp50;
    Str sp60;
    Str sp70;
    s32 sp80;
    while (func_004FE8D0(D_00645570) == 0) {
        mUpdateContext__Sync(1);
    }
    if (func_001F1368(arg1) == 0) {
        sp80 = 0;
        func_002ED590(arg0, &sp80);
        return arg0;
    }
    Info *info = func_004FEC48(D_00645570);
    func_002EFBF0(&sp0);
    Str *p10 = (Str *)sp10;
    Str *p30 = &sp30;
    void *obj = sp0.p;
    {
        Rep *rp = &D_00659FA8;
        char *d;
        if (rp->sel != 0) {
            d = func_005C2560(rp);
        } else {
            d = (char *)(rp + 1);
            rp->ref++;
        }
        p30->p = d;
        func_005C2630(p30, 0, -1, info, func_0057F260(info));
        func_00314B20(&sp20, p30);
        func_002EEEB0(p10, obj, &sp20);
        func_00309378(p10, 2);
        func_00312318(&sp20, 2);
        str_release(p30);
    }
    {
        Str *q = &sp40;
        void *o = sp0.p;
        func_002FE278(q, info->f94);
        func_002EEEB0(p10, o, q);
        func_00309378(p10, 2);
        func_002FC870(q, 2);
    }
    {
        Str *q = &sp50;
        void *o = sp0.p;
        func_002FE278(q, info->f98);
        func_002EEEB0(p10, o, q);
        func_00309378(p10, 2);
        func_002FC870(q, 2);
    }
    {
        Str *q = &sp60;
        void *o = sp0.p;
        func_002FE278(q, info->f9C);
        func_002EEEB0(p10, o, q);
        func_00309378(p10, 2);
        func_002FC870(q, 2);
    }
    {
        Str *q = &sp70;
        void *o = sp0.p;
        func_002FE278(q, info->fA0);
        func_002EEEB0(p10, o, q);
        func_00309378(p10, 2);
        func_002FC870(q, 2);
    }
    func_002ED5A8(arg0, &sp0);
    func_002ED5C0(&sp0, 2);
    return arg0;
}
