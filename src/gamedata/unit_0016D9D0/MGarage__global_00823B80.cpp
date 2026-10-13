typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct RefCounter;

extern s32 D_00622F4C;
extern "C" void func_00170A18(void *, void *);
extern "C" void func_0016D7F0(void *, s32);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void func_0016D9D0(s32 *arg0) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    func_00170A18(buf0, (void *)(D_00622F4C + 0xBC30));
    if (arg0 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *arg0 = newVal;
    }
    func_0016D7F0(buf0, 2);
}
