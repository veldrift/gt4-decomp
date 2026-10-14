typedef int s32;
typedef float f32;

extern "C" void func_00343490(void *p);
extern "C" void func_0034EF30(void *a, void *b, s32 c, s32 d);
extern "C" void func_0034ACA8(void *self, void *a, void *b, s32 c);
extern "C" void func_0034F3F8(void *a, f32 *b, void *c);
extern "C" void func_0034B808(void *a, void *b, s32 c);
extern "C" f32 func_00356EA8(void *p);

extern "C" s32 func_0034B960(void *arg0, s32 arg1, f32 *arg2, void *arg3) {
    char buf0[0xE0];
    char buf1[0x100];
    char buf2[0x20];
    f32 t;
    f32 v;

    func_00343490(buf2);
    if (arg3 == 0) {
        arg3 = buf2;
    }
    func_0034EF30(buf1, arg0, 0, 0);
    func_0034ACA8(arg0, buf0, buf1, 0);
    func_0034F3F8(buf1, arg2, arg3);
    func_0034B808(buf0, buf1, arg1);
    t = func_00356EA8(buf0);
    v = *arg2 + t;
    *arg2 = v;
    return (s32)v;
}
