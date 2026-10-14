typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct MButtonPressEvent {
    s32 pad0;
    void *vtbl;
    char pad8[0x18];
    u16 flag20;
    u16 pad22;
    s32 f24;
    f32 f28;
    f32 f2C;
};

extern char D_0069A9F0[];
extern char mButtonPressEvent__vtable[];
extern "C" void *func_00326750(s32, s32, void *);
extern "C" void *mWindowEvent__structor_0(void *, s32, s32);
extern "C" int func_0027F2F0(void *, void *);
extern "C" void func_00280630(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

extern "C" void MButtonPressEvent__global_00833620(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    s32 v_s0;
    s32 newVal;
    s32 oldVal;
    f32 zero = 0.0f;
    struct MButtonPressEvent *ev;
    p_s1 = buf1;
    ev = (struct MButtonPressEvent *)func_00326750(0x30, 0x4, D_0069A9F0);
    v_s0 = (s32)ev;
    mWindowEvent__structor_0(ev, 0, 0);
    ev->flag20 = 0;
    ev->f24 = 0;
    ev->vtbl = mButtonPressEvent__vtable;
    ev->f28 = zero;
    ev->f2C = zero;
    buf1[0] = v_s0;
    func_0027F2F0(buf0, p_s1);
    if (arg0 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_00280630(buf0, 0x2);
}
