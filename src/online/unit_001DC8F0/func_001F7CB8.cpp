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

struct H {
    void *p;
    char pad[0xC];
};

struct Str {
    char *p;
    char pad[0xC];
};

struct Query {
    char name[0x80];
    s32 f80;
    s32 f84;
    s32 f88;
    s32 f8C;
    s32 f90;
    s32 f94;
    char pad[0x18];
};

struct Item {
    char name[0x94];
    s32 f94;
    s32 f98;
    s32 f9C;
    s32 fA0;
};

struct Cnt {
    char pad[0x5B30];
    s32 count;
};

struct Global {
    char pad[0x5A8];
    Cnt *cnt;
};

extern Global D_00645570;
extern Rep D_00659FA8;
extern char D_00696D10[];

extern "C" s32 func_001F1368(void *) throw();
extern "C" void mUpdateContext__Sync(s32);
extern "C" void func_002ED590(void *, s32 *);
extern "C" void func_002ED5A8(void *, void *);
extern "C" void func_002ED5C0(H *, s32);
extern "C" void func_002EEEB0(H *, void *, H *);
extern "C" H *func_002EFBF0(H *);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00309378(void *, s32);
extern "C" void func_00312318(void *, s32);
extern "C" H *func_00314B20(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_004FE4C0(void *, void *);
extern "C" Item *func_004FE8A0(void *, s32);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" void *func_005A48D8(void *, s32, unsigned);
extern "C" void func_005A6AB0(void *, const char *, s32) throw();
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(void *, unsigned, unsigned, const char *, unsigned);

extern "C" void *func_001F7CB8(void *arg0, void *arg1, const char *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    Query q;
    H hB0;
    H hC0;
    H hD0;
    H hE0;
    Str sF0;
    H h100;
    H h110;
    H h120;
    H h130;
    s32 z140;
    func_005A48D8(&q, 0, 0xB0);
    if (arg2 != 0) {
        func_005A6AB0(&q, arg2, 0x80);
    } else {
        __builtin_strcpy(q.name, "*");
    }
    q.f80 = arg3;
    q.f84 = arg4;
    q.f88 = arg5;
    q.f8C = arg6;
    q.f94 = arg7;
    while (func_004FE4C0(&D_00645570, &q) == 0) {
        mUpdateContext__Sync(1);
    }
    if (func_001F1368(arg1) == 0) {
        z140 = 0;
        func_002ED590(arg0, &z140);
    } else {
        s32 i = 0;
        s32 n;
        func_002EFBF0(&hB0);
        n = D_00645570.cnt->count;
        if (n > 0) {
            H *pd = &hD0;
            H *pc = &hC0;
            do {
                Item *item = func_004FE8A0(&D_00645570, i);
                void *s0;
                func_002EFBF0(pc);
                s0 = pc->p;
                {
                    Rep *r = &D_00659FA8;
                    char *d;
                    if (r->sel != 0) {
                        d = func_005C2560(r);
                    } else {
                        d = (char *)(r + 1);
                        r->ref++;
                    }
                    sF0.p = d;
                }
                func_005C2630(&sF0, 0, -1, item->name, func_0057F260(item->name));
                func_00314B20(&hE0, &sF0);
                func_002EEEB0(pd, s0, &hE0);
                func_00309378(pd, 2);
                func_00312318(&hE0, 2);
                {
                    Rep *rr = (Rep *)(sF0.p - 0x10);
                    if (--rr->ref == 0) {
                        s32 size = rr->cap + 0x10;
                        func_00326798(rr, size, 4, func_005C11A8()->name);
                    }
                }
                s0 = pc->p;
                func_002FE278(&h100, item->f94);
                i++;
                func_002EEEB0(pd, s0, &h100);
                func_00309378(pd, 2);
                func_002FC870(&h100, 2);
                s0 = pc->p;
                func_002FE278(&h110, item->f98);
                func_002EEEB0(pd, s0, &h110);
                func_00309378(pd, 2);
                func_002FC870(&h110, 2);
                s0 = pc->p;
                func_002FE278(&h120, item->f9C);
                func_002EEEB0(pd, s0, &h120);
                func_00309378(pd, 2);
                func_002FC870(&h120, 2);
                s0 = pc->p;
                func_002FE278(&h130, item->fA0);
                func_002EEEB0(pd, s0, &h130);
                func_00309378(pd, 2);
                func_002FC870(&h130, 2);
                func_002EEEB0(pd, hB0.p, pc);
                func_00309378(pd, 2);
                func_002ED5C0(pc, 2);
            } while (i < n);
        }
        func_002ED5A8(arg0, &hB0);
        func_002ED5C0(&hB0, 2);
    }
    return arg0;
}
