typedef int s32;

extern "C" int func_005A48D8(void *buf, int a, int b);
extern "C" void func_00546B50(void *arg0, void *arg1, s32 arg2, s32 arg3);

extern "C" void func_00546AE8(void *arg0, s32 arg1, s32 arg2) {
    char buf[0x40];
    func_005A48D8(buf, 0, 0x40);
    *(s32 *)buf = 0x11;
    func_00546B50(arg0, buf, arg1, arg2);
}
