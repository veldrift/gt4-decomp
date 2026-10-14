extern char D_006A6D78[];

extern "C" int exception__structor_0(int n);
extern "C" void func_0044A478(int a0);
extern "C" void func_0044A540(int a0, void *a1);
extern "C" void func_005A5DC8(void *a0, char *a1);
extern "C" void func_005A609C(void *a0, void *a1);

extern "C" void func_00443C68(char *arg0) {
    char buf[0x100];
    int s0 = exception__structor_0(8);
    func_0044A478(s0);
    *(int *)(arg0 + 0x1E8) = s0;
    func_005A609C(buf, arg0 + 8);
    func_005A5DC8(buf, D_006A6D78);
    func_0044A540(*(int *)(arg0 + 0x1E8), buf);
}
