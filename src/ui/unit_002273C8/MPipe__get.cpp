/* compiler: ee-gcc2.96-no-strict-aliasing */
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

extern Rep D_00659FA8;
extern "C" void func_00227128(void *, s32) throw();
extern "C" void func_00227180(void *) throw();
extern "C" s32 func_00227B70(s32, char *, s32);
extern "C" void func_00312318(void *, s32);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(void *, s32, s32, const char *, s32);

extern "C" void MPipe__get(s32 *arg0) {
    char buf[0x100];
    s32 gap[4];
    s32 hv[8];
    s32 str[4];
    s32 *ph = hv;
    s32 *ps;
    s32 n;
    func_00227180(ph);
    n = func_00227B70(ph[0], buf, 0x100);
    func_00227128(ph, 2);
    {
        Rep *r = &D_00659FA8;
        char *d;
        ps = str;
        s32 sel = r->sel;
        buf[n] = 0;
        const char *b = buf;
        if (sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        ps[0] = (s32)d;
        func_005C2630(ps, 0, -1, b, func_0057F260(b));
    }
    func_00314B20(ph, ps);
    if (arg0 != ph) {
        s32 v = ph[0];
        if (v != 0) {
            func_003285A8(v);
        }
        if (*arg0 != 0) {
            func_003285F8(*arg0);
        }
        *arg0 = v;
    }
    func_00312318(ph, 2);
    {
        Rep *q = (Rep *)(ps[0] - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
}
