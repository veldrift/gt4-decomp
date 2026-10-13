typedef int s32;
typedef float f32;

struct mDBox {
    char pad[0xC8];
    s32 unkC8;
    s32 unkCC;
};

extern "C" s32 func_00206868(void *arg0);
extern "C" void func_00207208(struct mDBox *arg0, s32 arg1, s32 arg2);
extern "C" s32 func_002073D8(struct mDBox *arg0, s32 arg1);
extern "C" s32 func_0025C300(s32 arg0);
extern "C" f32 func_002E94E0(struct mDBox *arg0, s32 arg1);
extern "C" void func_002E94F0(struct mDBox *arg0, s32 arg1, f32 *arg2, f32 *arg3);
extern "C" s32 func_002E9540(struct mDBox *arg0, s32 arg1);
extern "C" void func_002E9600(struct mDBox *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern "C" void func_002E9730(struct mDBox *arg0, f32 fparg0, f32 fparg1);

extern "C" void mDBox__doUpdateChildren(struct mDBox *arg0, s32 arg1) {
    f32 fr[4];
    s32 s1;
    f32 f20;
    f32 f21;

    arg0->unkC8 = 0;
    f21 = 0.0f;
    arg0->unkCC = 0;
    s1 = func_00206868(arg0);
    f20 = f21;
    while (s1 != 0) {
        func_00207208(arg0, arg1, s1);
        if (func_002073D8(arg0, s1)) {
            if (arg0->unkC8 > 0) {
                f20 += func_002E94E0(arg0, s1);
            }
            func_002E94F0(arg0, s1, fr, &fr[1]);
            f20 += fr[0];
            if (f21 < fr[1]) {
                f21 = fr[1];
            }
            if (func_002E9540(arg0, s1) != 0) {
                arg0->unkCC = arg0->unkCC + 1;
            }
            arg0->unkC8 = arg0->unkC8 + 1;
        }
        s1 = func_0025C300(s1);
    }
    func_002E9600(arg0, &fr[1], fr, &fr[2], &fr[3]);
    func_002E9730(arg0, f20 + (fr[1] + fr[0]), f21 + (fr[2] + fr[3]));
}
