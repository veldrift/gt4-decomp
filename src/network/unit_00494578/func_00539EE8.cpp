struct P {
    char pad0[8];
    signed char *m8;
    char padC[4];
    int m10;
};
extern "C" void func_00539CA0(int, P *, signed char *, short) throw();
extern "C" void func_00539DF0(int, P *, short *) throw();
extern "C" int func_0053A760(signed char *, unsigned int);

extern "C" void func_00539EE8(int a, P *p, signed char *s) {
    short sp0;
    signed char *save = p->m8;
    if (p->m10 != 0) {
        return;
    }
    if (s == 0) {
        p->m10 = 2;
        return;
    }
    if (a == 1) {
        int v = ((func_0053A760(s, 0x7FFF) << 16) + 0x10000) >> 16;
        sp0 = v;
        if (v >= 0x7FFF) {
            p->m10 = 9;
            return;
        }
    }
    func_00539DF0(a, p, &sp0);
    if (p->m10 != 0) {
        return;
    }
    func_00539CA0(a, p, s, sp0);
    if (p->m10 != 0 || p->m8[-1] != 0) {
        p->m8 = save;
        if (save[-1] != 0) {
            p->m10 = 9;
        }
    }
}
