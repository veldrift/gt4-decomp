/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct Rect { char pad[8]; f32 x; f32 y; };
struct SF { f32 sp0; f32 sp4; f32 sp8; f32 spC; };
extern "C" {
f32 func_00200EA8(void *);
void func_00200EB8(void *);
f32 func_00200EC8(void *);
void func_00200ED8(void *);
void func_00207378(void *, s32, void *);
s32 func_002073D8(void *, void *);
void mWidget__getWindowSize(void *, f32 *, f32 *);
void func_0025B500(void *, void *, f32 *, f32 *, f32 *);
void func_0025B538(void *, f32, f32, f32, f32);
Rect *func_0025BF60(void *);
void *func_0025C300(void *);
void func_00263C40(void *);
s32 func_00266368(void *);
s32 func_00266398(void *);
s32 func_002663C8(void *);
s32 func_002663F8(void *);
void *func_00206868b(void *) __asm__("func_00206868");
void mRootWindow__virtual_96(void *arg0, s32 arg1) {
    SF sp_;
    f32 f26 = func_00200EA8(arg0);
    func_00200EB8(arg0);
    f32 f25 = func_00200EC8(arg0);
    func_00200ED8(arg0);
    mWidget__getWindowSize(arg0, &sp_.sp8, &sp_.spC);
    Rect *r = func_0025BF60(arg0);
    f32 f23 = sp_.sp8 - r->x;
    f32 f22 = sp_.spC - r->y;
    void *s0 = func_00206868b(arg0);
    if (s0 != 0) {
        do {
            func_00263C40(s0);
            if (func_002073D8(arg0, s0) != 0) {
                func_0025B500(s0, &sp_, &sp_.sp4, &sp_.sp8, &sp_.spC);
                f32 f21 = 0.0f;
                f32 f20 = 0.0f;
                if (func_00266368(s0) != 0) {
                    sp_.sp0 = f26;
                    if (func_002663C8(s0) != 0) {
                        sp_.sp8 += f23;
                    } else {
                        f21 = f23 * 0.5f;
                    }
                }
                if (func_00266398(s0) != 0) {
                    sp_.sp4 = f25;
                    if (func_002663F8(s0) != 0) {
                        sp_.spC += f22;
                    } else {
                        f20 = f22 * 0.5f;
                    }
                }
                func_0025B538(s0, sp_.sp0 + f21, sp_.sp4 + f20, sp_.sp8, sp_.spC);
            }
            func_00207378(arg0, arg1, s0);
            s0 = func_0025C300(s0);
        } while (s0 != 0);
    }
}
}
