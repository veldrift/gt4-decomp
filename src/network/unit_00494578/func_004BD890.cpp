typedef int s32;

extern "C" void func_004C8FD8(void *buf, s32 arg);
extern "C" void func_004BD7B0(s32 arg0, s32 arg1, const char *arg2, s32 arg3);

extern "C" s32 func_004BD890(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char buf[0x80];
    func_004C8FD8(buf, arg2);
    func_004BD7B0(arg0, arg1, buf, arg3);
    return 0;
}
