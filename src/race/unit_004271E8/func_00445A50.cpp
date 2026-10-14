extern void *D_0062378C;

extern "C" int func_004458D0(void *a0, int a1, void *out);
extern "C" void func_00449CD8(void *a0, int a1);

extern "C" void func_00445A50(void *arg0, int arg1) {
    unsigned char buf[0x40];
    func_004458D0(arg0, arg1, buf);
    func_00449CD8(D_0062378C, *(int *)(buf + 0xC));
}
