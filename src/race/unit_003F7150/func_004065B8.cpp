/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int *f0; char p4[0xC]; int *f10; int f14; };
extern "C" float *func_00385BB8(int *);
extern "C" float *func_00385BC8(int *);
extern "C" int func_00402270(int, int) throw();

extern "C" void func_004065B8(Obj *o)
{
    switch (func_00402270(o->f14, *o->f10)) {
    case 3:
        break;
    case 4:
        *func_00385BB8(o->f0) = 0.0f;
        *func_00385BC8(o->f0) = 0.25f;
        return;
    }
    *func_00385BB8(o->f0) = 0.25f;
    *func_00385BC8(o->f0) = 0.25f;
}
