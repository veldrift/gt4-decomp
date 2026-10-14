typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct RefCounter {
    s32 ref;
};

struct Obj {
    char pad[0x10];
};

extern "C" void func_00312370(void *, void *);
extern "C" char *func_00314AD8(void *);
extern "C" int func_00448AD0(int, int);
extern "C" void func_00312318(void *, s32);
extern "C" void func_002FE278(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);

extern "C" void MCarData__IsDirtRunnable(s32 *arg0, s32 arg1, void *arg2) {
    s32 buf0[16];
    s32 buf3[4];
    s32 buf4[4];
    s32 *p_s1;
    s32 v_s0;
    s32 newVal;
    s32 oldVal;

    if (arg1 > 0) {
        p_s1 = buf4;
        func_00312370(p_s1, arg2);
        v_s0 = func_00448AD0((int)func_00314AD8((void *)p_s1[0]), (int)buf0);
        func_00312318(p_s1, 2);
        if (v_s0 != 0) {
            func_002FE278(p_s1, (void *)(s32)(*(s64 *)((char *)buf0 + 0x38) != -1));
            if (arg0 != p_s1) {
                newVal = *p_s1;
                if (newVal != 0) {
                    func_003285A8(newVal);
                }
                oldVal = *arg0;
                if (oldVal != 0) {
                    func_003285F8(oldVal);
                }
                *arg0 = newVal;
            }
            func_002FC870(p_s1, 2);
        } else {
            func_002FE278(p_s1, (void *)0);
            if (arg0 != p_s1) {
                newVal = *p_s1;
                if (newVal != 0) {
                    func_003285A8(newVal);
                }
                oldVal = *arg0;
                if (oldVal != 0) {
                    func_003285F8(oldVal);
                }
                *arg0 = newVal;
            }
            func_002FC870(p_s1, 2);
        }
    }
}
