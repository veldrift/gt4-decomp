typedef int s32;
typedef float f32;

struct Opt {
    char pad0[0xC0];
    void *c0;
    void *c4;
    void *c8;
    char pad1[0x30];
    s32 fc;
    char pad2[4];
    s32 f104;
    char pad3[0x14];
    f32 f11C;
};

extern "C" void func_002638D8(void *, s32, s32);
extern "C" f32 func_00267DB0(void *);
extern "C" void func_00267DB8(void *, f32);
extern "C" void *func_0057B0F8(void *, f32, f32);
extern "C" void func_0025BA08(void *, f32);
extern "C" void func_0025B500(void *, f32 *, f32 *, f32 *, f32 *);
extern "C" void func_0025B538(void *, f32, f32, f32, f32);

extern "C" void func_002C9C90(Opt *arg0, s32 arg1) {
    f32 sv[4];

    func_002638D8(arg0, arg1, 0);
    if (arg0->fc != 0) {
        if (arg0->c0 != 0) {
            f32 t = func_00267DB0(arg0->c0);
            if (t < 1.0f) {
                f32 x = t + 0x1.999998p-4f;
                if (x >= 1.0f) {
                    x = 1.0f;
                }
                func_00267DB8(arg0->c0, x);
            }
        }
    }
    if (arg0->c4 != 0) {
        if (arg0->fc != 0) {
            if (arg0->f104 != 0) {
                char *s0 = (char *)arg0 + 0x110;
                func_0057B0F8(s0, arg0->f11C, 0x1.999998p-2f);
                func_0025BA08(arg0->c4, *(f32 *)(s0 + 8));
                if (arg0->c8 != 0) {
                    func_0025B500(arg0->c4, sv, sv + 1, sv + 2, sv + 3);
                    func_0025B538(arg0->c8, sv[0] + 4.0f, sv[1] + 4.0f, sv[2], sv[3]);
                }
            }
        }
    }
}
