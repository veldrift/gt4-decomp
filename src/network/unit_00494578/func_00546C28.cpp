extern "C" void func_005A48D8(void *buf, int a, int b);
extern "C" void func_00546CA0(void *a, const void *b, int c, int d, int e);

extern "C" void func_00546C28(void *arg0, int arg1, int arg2, int arg3) {
    char buf[0x40];
    func_005A48D8(buf, 0, 0x40);
    *(int *)buf = 0x11;
    func_00546CA0(arg0, buf, arg1, arg2, arg3);
}
