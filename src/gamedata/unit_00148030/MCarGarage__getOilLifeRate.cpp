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

struct S00659988 {
    const char *name;
};

extern "C" void func_0013BDC0(void *, void *);
extern "C" s32 func_00147D80(s32);
extern "C" void func_0013BD68(void *, s32);
extern "C" f32 func_003437F0(s32);
extern "C" void func_002F9360(void *, f32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002F7B68(void *, s32);

extern "C" void func_0014E9C0(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 v_s0;
    s32 t1;
    s32 newVal;
    s32 oldVal;
    func_0013BDC0(buf0, arg1);
    t1 = func_00147D80(buf0[0]);
    v_s0 = t1 + 0x4a0;
    func_0013BD68(buf0, 0x2);
    func_002F9360(buf0, func_003437F0(v_s0));
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
    func_002F7B68(buf0, 0x2);
}
