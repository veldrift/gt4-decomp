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

extern "C" void func_002DD640(void *, s32);
extern "C" void func_002DD698(void *, void *);
extern "C" s32 func_002DF9F0(s32, s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_002FC8C8(void *, void *);
extern "C" s32 func_002FE250(s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

extern "C" void MSliderBar__decIndex(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s3;
    s32 var_s0;
    s32 newVal;
    s32 oldVal;
    func_002DD698(buf0, arg1);
    var_s0 = 1;
    if (arg2 > 0) {
        p_s3 = buf1;
        func_002FC8C8(p_s3, arg3);
        var_s0 = func_002FE250(p_s3[0]);
        func_002FC870(p_s3, 0x2);
    } else {
        p_s3 = buf1;
    }
    func_002FE278(p_s3, func_002DF9F0(buf0[0], var_s0) != 0);
    if (arg0 != p_s3) {
        newVal = *p_s3;
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_002FC870(p_s3, 0x2);
    func_002DD640(buf0, 0x2);
}
