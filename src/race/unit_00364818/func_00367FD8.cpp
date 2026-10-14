typedef int s32;
typedef unsigned char u8;
typedef float f32;

struct Ob367FD8 {
    char pad0[0x10];
    u8 *unk10;
};

extern "C" s32 func_00367DD0(f32 x);
extern "C" s32 func_00367EB8(f32 x);

extern "C" s32 func_00367FD8(struct Ob367FD8 *arg0, f32 fparg0) {
    f32 var_f12;
    u8 *p;

    var_f12 = (fparg0 * 60.0f) / 6.2831851244f;
    p = arg0->unk10 + 0x234;
    if (var_f12 < 0.0f) {
        var_f12 = -var_f12;
    }
    if (p[0x13] == 3) {
        return func_00367EB8(var_f12);
    }
    return func_00367DD0(var_f12);
}
