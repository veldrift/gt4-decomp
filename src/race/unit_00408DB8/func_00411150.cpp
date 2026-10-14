/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
typedef unsigned char u8;

struct Obj {
    s32 p0;
    char pad4[4];
    s32 p8;
    s32 *pC;
    char pad10[0x110 - 0x10];
    f32 dt;
};

extern "C" f32 func_003857A8(s32);
extern "C" f32 func_003857C0(s32);
extern "C" u8 func_00385EE0(s32);
extern "C" u8 func_00385EE8(s32);
extern "C" u8 func_00385EF0(s32);
extern "C" u8 func_00385EF8(s32);
extern "C" void func_00386030(s32 *, s32, s32);
extern "C" f32 *func_00386388(s32);

extern "C" void func_00411150(Obj *o, s32 flag) {
    if (flag == 0) {
        return;
    }
    if (func_00385EE0(*o->pC) == 0 && func_00385EE8(*o->pC) == 0) {
        f32 a = func_003857A8(o->p0);
        if (__builtin_fabsf(a - func_003857C0(o->p0)) < 0x1.921fb4p+0f) {
            *func_00386388(o->p8) += o->dt;
            if (*func_00386388(o->p8) > 0.25f) {
                f32 z = 0.0f;
                if (func_003857A8(o->p0) > z) {
                    func_00386030(o->pC, 0, 4);
                    *func_00386388(o->p8) = z;
                } else if (func_003857C0(o->p0) < z) {
                    func_00386030(o->pC, 1, 4);
                    *func_00386388(o->p8) = z;
                } else {
                    f32 n = -func_003857A8(o->p0);
                    if (n < func_003857C0(o->p0)) {
                        func_00386030(o->pC, 0, 4);
                        *func_00386388(o->p8) = z;
                    } else {
                        func_00386030(o->pC, 1, 4);
                        *func_00386388(o->p8) = z;
                    }
                }
            }
        } else {
            f32 z = 0.0f;
            if (func_003857C0(o->p0) < z) {
                *func_00386388(o->p8) += o->dt;
                if (*func_00386388(o->p8) > 2.0f) {
                    func_00386030(o->pC, 1, 7);
                    *func_00386388(o->p8) = z;
                }
            } else if (func_003857A8(o->p0) > z) {
                *func_00386388(o->p8) += o->dt;
                if (*func_00386388(o->p8) > 2.0f) {
                    func_00386030(o->pC, 0, 7);
                    *func_00386388(o->p8) = z;
                }
            } else {
                *func_00386388(o->p8) = z;
            }
        }
    }
    u8 s0 = func_00385EE0(*o->pC);
    if (s0 != func_00385EF0(*o->pC) || func_00385EE8(*o->pC) != func_00385EF8(*o->pC)) {
        *func_00386388(o->p8) = 0;
    }
}
