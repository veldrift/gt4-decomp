typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

extern "C" void func_00137D60(void *arg0, int arg1);
extern "C" void *func_00137DB8(void *arg0, void *arg1);
extern "C" void func_00151800(void *arg0, void *arg1);
extern "C" void func_00151830(void *arg0, int arg1);
extern "C" void *func_00151888(void *arg0, void *arg1);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);

extern "C" void func_00138C40(void *arg0, void *arg1, s32 arg2, s32 *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 newVal;
    s32 oldVal;

    if (arg2 > 0) {
        func_00137DB8(buf0, arg1);
        if (*arg3 == 0) {
            s32 *p = buf1;
            s32 *pf = (s32 *)((char *)buf0[0] + 0x2A4);
            buf2[0] = 0;
            func_00151800(p, buf2);
            if (pf != p) {
                newVal = *p;
                if (newVal != 0) {
                    func_003285A8(newVal);
                }
                oldVal = *pf;
                if (oldVal != 0) {
                    func_003285F8(oldVal);
                }
                *pf = newVal;
            }
            func_00151830(p, 2);
        } else {
            s32 *p = buf1;
            func_00151888(p, arg3);
            s32 *pf = (s32 *)((char *)buf0[0] + 0x2A4);
            if (pf != p) {
                newVal = *p;
                if (newVal != 0) {
                    func_003285A8(newVal);
                }
                oldVal = *pf;
                if (oldVal != 0) {
                    func_003285F8(oldVal);
                }
                *pf = newVal;
            }
            func_00151830(p, 2);
        }
        func_00137D60(buf0, 2);
    }
}
