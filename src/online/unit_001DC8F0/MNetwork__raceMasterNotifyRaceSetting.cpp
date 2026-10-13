typedef int s32;
struct Blob32;

extern "C" void func_001DC5F8(void *arg0, s32 arg1);
extern "C" void func_001DC650(void *arg0, void *arg1);
extern "C" void func_001F7330(void *ctx, Blob32 *blob);
extern "C" void func_001FFF30(void *arg0, s32 arg1);
extern "C" void func_001FFF88(void *arg0, s32 arg1);

extern "C" void func_001E6CF0(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    if (arg2 > 0) {
        s32 buf[4];
        func_001FFF88(buf, arg3);
        void *obj = (void *)buf[0];
        s32 s0val = *(s32 *)((char *)obj + 0x10);
        func_001FFF30(buf, 2);
        func_001DC650(buf, arg1);
        func_001F7330((void *)buf[0], (Blob32 *)s0val);
        func_001DC5F8(buf, 2);
    }
}
