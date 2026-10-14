extern "C" void func_003F84E0(const int *s, int *d);
extern "C" void func_003F8510(int *d, const int *s);
extern "C" void func_00463930(void *a, int b, void *c);

extern "C" void func_003F85F0(void *arg0, const void *arg1) {
    int tmp[8];
    func_003F84E0((const int *)arg0, tmp);
    __builtin_memcpy(arg0, arg1, 0x10A0);
    func_003F8510((int *)arg0, tmp);
    func_00463930((char *)arg0 + 0x14, ((int *)arg0)[1], arg0);
}
