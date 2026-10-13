typedef int s32;

extern "C" void func_001FFF88(void *arg0, void *arg1);
extern "C" void func_001FFF30(void *arg0, s32 arg1);
extern "C" void func_001DC650(void *arg0, void *arg1);
extern "C" void func_001F72A0(void *ctx, void *blob);
extern "C" void func_001DC5F8(void *arg0, s32 arg1);

extern "C" void func_001E6C80(void *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf[4];

    if (arg2 > 0) {
        func_001FFF88(buf, arg3);
        s32 v = ((s32 *)buf[0])[4];
        func_001FFF30(buf, 2);
        func_001DC650(buf, arg1);
        func_001F72A0((void *)buf[0], (void *)v);
        func_001DC5F8(buf, 2);
    }
}
