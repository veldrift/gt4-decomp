typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Vec4 {
    f32 v[4];
};

extern "C" void func_001298C8(void *arg0, void *arg1);
extern "C" void func_00129870(void *arg0, s32 arg1);
extern "C" struct Vec4 *func_002030E8(struct Vec4 *arg0, struct Vec4 *arg1);
extern "C" void func_00203620(void *arg0, s32 arg1);
extern "C" void func_00203678(void *arg0, s32 arg1);
extern "C" void func_00204558(void *arg0, s32 arg1);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);

extern "C" void func_0012A358(s32 *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 newVal;
    s32 oldVal;

    func_001298C8(buf0, arg1);
    if (arg2 == 0) {
        s32 *p = buf1;
        func_00204558(p, buf0[0] + 0xB0);
        if (arg0 != p) {
            newVal = *p;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_00203620(p, 2);
    } else if (arg2 == 1) {
        s32 *p = buf1;
        func_00203678(p, arg3);
        func_002030E8((struct Vec4 *)((char *)buf0[0] + 0xB0),
                      (struct Vec4 *)((char *)p[0] + 0x10));
        func_00203620(p, 2);
    }
    func_00129870(buf0, 2);
}
