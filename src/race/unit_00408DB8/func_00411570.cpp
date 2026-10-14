/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
typedef unsigned char u8;

struct Obj {
    s32 p0;
    char pad4[8];
    s32 *pC;
    char pad10[0x110 - 0x10];
    f32 rate;
};

extern "C" f32 *func_00385B48(s32);
extern "C" f32 *func_00385CF8(s32);
extern "C" f32 *func_00385D08(s32);
extern "C" f32 *func_00385DD8(s32);
extern "C" u8 func_00385EE0(s32);
extern "C" f32 func_004104B8(s32, s32, f32, f32, f32, f32) throw();

extern "C" void func_00411570(Obj *o) {
    s32 sp[2];
    sp[0] = 0;
    sp[1] = 0;
    f32 *a = func_00385CF8(o->p0);
    s32 side = func_00385EE0(*o->pC);
    f32 *b = func_00385B48(o->p0);
    f32 *c = func_00385DD8(o->p0);
    *a = func_004104B8(side, sp[0], *b, *c, *func_00385CF8(o->p0), o->rate);
    *func_00385D08(o->p0) = 1.0f;
}
