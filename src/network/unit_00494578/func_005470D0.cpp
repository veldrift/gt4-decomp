extern "C" void func_005471C0(void *buf);
extern "C" void func_00547200(void *buf, int arg1, int arg2);
extern "C" void func_00547360(int arg0, void *buf);

extern "C" void func_005470D0(int arg0, int arg1, int arg2) {
    char buf[0x60];
    func_005471C0(buf);
    func_00547200(buf, arg0, arg1);
    func_00547360(arg2, buf);
}
