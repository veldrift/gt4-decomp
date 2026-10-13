typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

extern "C" void func_001237B0(void *arg0, s32 *arg1);
extern "C" void func_00123838(void *arg0, s32 *arg1);
extern "C" void func_001237E0(void *arg0, int arg1);
extern "C" void func_0011FF38(char *arg0, s32 arg1, void *arg2);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void func_001BBF80(char *arg0, s32 *arg1) {
    s32 buf[4];
    s32 zero;
    s32 *dst;
    s32 newVal;
    s32 oldVal;
    s32 temp;

    dst = (s32 *)(arg0 + 0xA4);
    if (*arg1 == 0) {
        zero = 0;
        func_001237B0(buf, &zero);
    } else {
        func_00123838(buf, arg1);
    }
    if (dst != buf) {
        newVal = buf[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *dst;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *dst = newVal;
    }
    func_001237E0(buf, 2);
    temp = *dst;
    if (temp != 0) {
        func_0011FF38((char *)temp, *(s32 *)(arg0 + 0xA0), arg0);
    }
}
