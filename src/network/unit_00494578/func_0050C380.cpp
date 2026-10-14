struct O {
    char pad0[0x14];
    char c14;
    char pad15[0x25 - 0x15];
    char c25;
    char pad26[0x7F - 0x26];
    char c7F;
    char pad80[0x9F - 0x80];
    char c9F;
    char padA0[0xB8 - 0xA0];
    int mB8;
};
struct S {
    int m0;
    void *m4;
};
extern int D_0064A308;
extern int D_0064A30C;
extern int D_008A03F8;
extern int D_008A01D0;
extern "C" void func_0050AA88(void);
extern "C" void func_0050A9A0(void *) throw();
extern "C" void func_0050A9C0(int) throw();
extern "C" void func_0050AAE8(int, void *) throw();
extern "C" int func_0050B460(int, int, int, void *) throw();
extern "C" int func_0052EFC0(void *);
extern "C" int func_0052F010(void *, void *);

struct L {
    S s;
    char buf8[0x18];
    char buf20[0x10];
};

extern "C" int func_0050C380(O *o, int a, int b) {
    L l;
    o->c14 = 0;
    o->c25 = 0;
    o->c7F = 0;
    o->c9F = 0;
    if (D_0064A308 != 1) {
        return -0xF;
    }
    if (D_0064A30C == 0) {
        return -0x10;
    }
    int t = o->mB8;
    D_008A03F8 = a;
    D_008A01D0 = b;
    if (t == 2) {
        if (func_0052EFC0(&l.s) != 0) {
            return -2;
        }
        func_0050A9A0(l.buf8);
        l.s.m4 = (void *)func_0050AA88;
        func_0050A9C0(3);
        func_0050AAE8(0x12, o);
        int r = func_0052F010(&l.s, l.buf20);
        if (r != 0) {
            func_0050A9C0(0);
            return -2;
        }
        return r;
    }
    return func_0050B460(1, 0x1F, 0xEC, o) == 0 ? 0 : -5;
}
