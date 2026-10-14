/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Inner {
    char pad0[0x18];
    s32 f18;
    char pad1[4];
    s32 f20;
};

struct Obj {
    Inner *inner;
    char pad[0x34 - 4];
    s32 f34;
};

extern "C" s32 *func_00450FE0(Obj *) throw();
extern "C" s32 *func_00451020(Obj *) throw();
extern "C" void func_00454C58(s32, float, s32);
extern "C" void func_004573B8(s32, s32 *, s32);

extern "C" void func_00451110(Obj *self, s32 arg, float t)
{
    Inner *in = self->inner;
    self->f34 = self->f34 + (s32)(t * 1000.0f);
    if (in != 0 && arg != 0) {
        s32 a = in->f18;
        s32 b = in->f20;
        if (a != 0) {
            s32 *p = func_00450FE0(self);
            func_004573B8(*p, p, arg);
            func_00454C58(a, t, -1);
        }
        if (b != 0) {
            s32 *q = func_00451020(self);
            func_004573B8(*q, q, arg);
        }
    }
}
