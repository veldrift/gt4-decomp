typedef int s32;

struct Obj {
    s32 f00;
    void *f04;
    s32 f08;
    char pad0C[0x94];
    s32 fA0;
    char padA4[0x34];
    s32 fD8;
    s32 fDC;
    s32 fE0;
    s32 fE4;
    char padE8[0x8];
    s32 fF0;
    s32 fF4;
    s32 fF8;
};

struct Sub {
    char pad0[0x44];
    s32 f44;
};

struct Node {
    char pad0[0x10];
    s32 f10;
    s32 f14;
    s32 f18;
};

extern s32 D_00622F4C;

extern "C" void func_004076E0(void *s, s32 a);
extern "C" void func_004078D0(void *s, s32 a, s32 b);
extern "C" s32 func_00407BC0(void *s, s32 a);
extern "C" s32 func_00407C40(void *s, s32 a);
extern "C" s32 func_004462E0(s32 a);
extern "C" s32 func_00446320(s32 a);
extern "C" void func_00474F38(void *p, s32 a, s32 b, s32 c);
extern "C" void func_00475D78(void *p, void (*fn)(void), Obj *o);
extern "C" void *exception__structor_0(s32 size);
extern "C" void func_003DCC28(void);

extern "C" void func_003DCC50(Obj *arg0, s32 arg1, s32 arg2) {
    Sub *s3 = (Sub *)((char *)arg0 + 0x10);
    s32 s2 = arg1 + 0x20;
    arg0->fD8 = arg1;
    arg0->fE0 = 0;
    arg0->fDC = 0;
    arg0->fE4 = 0;
    func_004076E0(s3, s2);
    if (arg2 != 0) {
        func_004078D0(s3, s2, D_00622F4C + 0x13938);
    }
    arg0->fF0 = func_00407BC0(s3, func_004462E0(s2));
    arg0->fF4 = func_00407C40(s3, func_00446320(s2));
    if (arg0->fF0 < 0) {
        arg0->fF0 = s3->f44;
    }
    if (arg0->fF4 < 0) {
        arg0->fF4 = arg0->fA0;
    }
    arg0->fF8 = 1;
    if (arg0->f00 != 0) {
        Node *n = (Node *)exception__structor_0(0x19C);
        func_00474F38(n, arg0->f00, 0, arg0->f08);
        arg0->f04 = n;
        func_00475D78(n, func_003DCC28, arg0);
        *(volatile s32 *)&((Node *)arg0->f04)->f10 = 1;
        {
            Node *m = *(Node * volatile *)&arg0->f04;
            m->f18 = 1;
            m->f14 = 0;
        }
    }
}
