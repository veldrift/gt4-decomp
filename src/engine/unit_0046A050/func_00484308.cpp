typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
};

extern Rep D_00659E20;

extern "C" char *func_005D2B58(Rep *src);
extern "C" s32 func_0057F260(const char *s);
extern "C" void *func_005D2C20(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" void *func_00481410(void *m, Str *k);
extern "C" s32 func_00476768(void *a, void *b);
extern "C" void func_00575DA0(s32 p);

extern "C" void *func_00484308(void *arg0, void *arg1) {
    Str s;
    Str *ps = &s;
    const char *src = "THIS";
    Rep *r = &D_00659E20;
    char *d = (char *)(r + 1);
    if (r->sel != 0) {
        d = func_005D2B58(r);
    } else {
        r->ref++;
    }
    ps->p = d;
    func_005D2C20(ps, 0, -1, src, func_0057F260(src));
    func_00476768(arg0, func_00481410(arg1, &s));
    {
        Rep *q = (Rep *)(s.p - 0x10);
        if (--q->ref == 0) {
            func_00575DA0((s32)q);
        }
    }
    return arg0;
}
