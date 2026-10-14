typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct RefCounter;

extern char *D_00622F4C;
extern "C" void func_00132F48(void *, void *);
extern "C" void func_00132D60(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

extern "C" void MCalendar__global_008222B8(s32 *arg0) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    func_00132F48(buf0, (char *)D_00622F4C + 0x568);
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
    func_00132D60(buf0, 2);
}
