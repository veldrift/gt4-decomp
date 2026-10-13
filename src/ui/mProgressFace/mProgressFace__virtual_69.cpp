typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct MProgressFace {
    char pad0[0xF0];
    s32 unkF0;
    s32 unkF4;
    f32 unkF8;
    f32 unkFC;
};

extern "C" f32 func_00228A38(s32 arg0);
extern "C" f32 func_00228A78(s32 arg0);
extern "C" void func_0025B3A0(char *arg0, f32 fparg0);
extern "C" void func_002638D8(char *arg0, s32 arg1, s32 arg2);
extern "C" void func_002A3800(char *arg0, s32 arg1, f32 *arg2);

extern "C" void func_002CAE28(char *arg0, s32 arg1, s32 arg2) {
    struct MProgressFace *self = (struct MProgressFace *)arg0;
    f32 buf[8];
    f32 *s0;
    f32 sp10;
    f32 sp14;
    s32 t;
    f32 f;

    t = self->unkF0;
    if (t == 0) {
        *(s32 *)&self->unkF8 = 0;
    } else {
        if (self->unkF4 != 0) {
            f = func_00228A38(t);
        } else {
            f = func_00228A78(t);
        }
        self->unkF8 = f;
    }

    func_0025B3A0(arg0, self->unkFC * self->unkF8);

    sp10 = self->unkF8;
    sp14 = 1.0f;
    s0 = &buf[4];
    buf[0] = sp10;
    *(s32 *)&buf[1] = 0;
    *s0 = sp10;
    buf[5] = sp14;

    func_002A3800(arg0, 1, buf);
    func_002A3800(arg0, 2, s0);
    func_002638D8(arg0, arg1, arg2);
}
