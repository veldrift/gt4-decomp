typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct RefCounter;

extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_003285A8(struct RefCounter *p);
extern "C" void func_003285F8(struct RefCounter *p);

extern "C" void func_002F1BC8(s32 *arg0, void *arg1, s32 *arg2) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    if (*arg2 == 0) {
        func_002FE278(buf0, (void *)1);
        if (arg0 != buf0) {
            newVal = buf0[0];
            if (newVal != 0) {
                func_003285A8((struct RefCounter *)newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8((struct RefCounter *)oldVal);
            }
            *arg0 = newVal;
        }
        func_002FC870(buf0, 2);
    } else {
        func_002FE278(buf0, (void *)0);
        if (arg0 != buf0) {
            newVal = buf0[0];
            if (newVal != 0) {
                func_003285A8((struct RefCounter *)newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8((struct RefCounter *)oldVal);
            }
            *arg0 = newVal;
        }
        func_002FC870(buf0, 2);
    }
}
