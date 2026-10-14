struct O { char pad0[0x154]; int f154; int f158; int f15c; char pad160[0xA38 - 0x160]; int fA38; char padA3c[0x3F24 - 0xA3C]; int f3F24; };
extern "C" void func_004F0BF0(O *, int);
extern "C" void func_004F87B0(O *, int);
extern "C" void func_004F8820(O *, int);
extern "C" void func_004F8858(O *, int);
extern "C" void func_004FA278();
extern "C" void func_004FA590(O *);
extern "C" void func_004FB4C0(O *);
extern "C" void func_005032D0();
extern "C" int func_005053D8();
extern "C" int func_0050B658();
extern "C" int func_0050B6E0();
extern "C" int func_0052FA88();

extern "C" void func_004FB548(O *o) {
    if (o->f158 != 0) return;
    int ok = 1;
    func_004FA278();
    func_004FB4C0(o);
    int s3 = 0, s2 = 0, s4 = 0;
    if (o->f154 != 0) {
        s3 = func_0052FA88();
        if (s3 != 0) ok = 0;
    } else {
        if (o->fA38 != 0) s2 = func_0050B6E0();
        else s2 = func_0050B658();
        ok = (s2 == 0);
        if (o->f3F24 != 0) {
            s4 = func_005053D8();
            if (s4 != 0) ok = 0;
        }
    }
    if (ok == 0) {
        int v;
        func_004F0BF0(o, 1);
        if (s3 != 0) {
            func_004F8820(o, s3);
            v = 1;
        } else if (s2 != 0) {
            func_004F87B0(o, s2);
            v = 1;
        } else {
            if (s4 != 0) func_004F8858(o, s4);
            v = 1;
        }
        o->f158 = v;
        o->f15c = v;
    }
    func_004FA590(o);
    func_005032D0();
}
