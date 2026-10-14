/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rec { char p0[8]; int f8; int fC; int f10; };
struct Obj { int f0; int f4; };
extern "C" void func_004AF6B8(Rec *);
extern "C" void func_00407470(Obj *);
extern "C" void func_004074F0(int);
extern "C" Rec func_004AE230(int, int);
extern "C" Rec func_004AE268(int, int, int, int);

extern "C" int func_00407348(Obj *o, int a1, int a2, int a3)
{
    Rec r;
    func_004AF6B8(&r);
    func_00407470(o);
    if (a2 != 0) {
        r = func_004AE268(a1, a2, a3, 1);
    } else {
        r = func_004AE230(a1, 1);
        o->f4 = r.f10;
    }
    if (r.f8 != 0) {
        o->f0 = r.f10;
    } else {
        o->f0 = 0;
    }
    int v = o->f0;
    if (v != 0) {
        func_004074F0(v);
        v = o->f0;
    }
    return v;
}
