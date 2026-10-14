struct Obj { char pad[0x10]; unsigned f10; };
struct Out { int f0; int f4; };
struct Tab;
extern Tab *D_00623784;
extern "C" int func_00445808(Obj *);
extern "C" int func_00449210(Tab *, unsigned int);
extern "C" void SPEC_DATABASE__DatabaseTable__getRowN(Tab *, int, Out *);
extern "C" int func_004458D0(Obj *o, int idx, Out *out) {
    int n = func_00445808(o);
    if (idx >= n) return 0;
    {
        Tab *t = D_00623784;
        unsigned long k = o->f10;
        int base = func_00449210(t, k);
        if (base == -1) return 0;
        for (int i = 0; i < n; i++) {
            SPEC_DATABASE__DatabaseTable__getRowN(t, base + i, out);
            if (out->f4 == idx + 1) return 1;
        }
    }
    return 0;
}
