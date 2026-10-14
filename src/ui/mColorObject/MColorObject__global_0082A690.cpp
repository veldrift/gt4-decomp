typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef float f32;

struct Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

extern "C" void func_002F7BC0(void *arg0, void *arg1);
extern "C" f32 func_002F9158(void *arg0);
extern "C" void func_002F7B68(void *arg0, int arg1);
extern "C" void func_00203678(void *arg0, void *arg1);
extern "C" void func_00203148(Vec4 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern "C" Vec4 *func_002030E8(Vec4 *arg0, Vec4 *arg1);
extern "C" void func_00203118(void *arg0, int arg1);
extern "C" void func_00203620(void *arg0, int arg1);

extern "C" void MColorObject__global_0082A690(void *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf[4];
    Vec4 vec;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f23;
    s32 v;

    if (arg2 > 0) {
        f21 = 0x1p+0f;
        func_002F7BC0(buf, arg3);
        f20 = f21;
        f23 = f20;
        f22 = func_002F9158((void *)buf[0]);
        func_002F7B68(buf, 2);
        if (arg2 >= 2) {
            func_002F7BC0(buf, (char *)arg3 + 0x4);
            f21 = func_002F9158((void *)buf[0]);
            func_002F7B68(buf, 2);
        }
        if (arg2 >= 3) {
            func_002F7BC0(buf, (char *)arg3 + 0x8);
            f23 = func_002F9158((void *)buf[0]);
            func_002F7B68(buf, 2);
        }
        if (arg2 >= 4) {
            func_002F7BC0(buf, (char *)arg3 + 0xC);
            f20 = func_002F9158((void *)buf[0]);
            func_002F7B68(buf, 2);
        }
        func_00203678(buf, arg1);
        v = buf[0];
        func_00203148(&vec, f22, f21, f23, f20);
        func_002030E8((Vec4 *)((char *)v + 0x10), &vec);
        func_00203118(&vec, 2);
        func_00203620(buf, 2);
    }
}
