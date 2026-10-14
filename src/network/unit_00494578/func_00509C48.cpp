struct S { char data[100]; };
extern int D_00853538;
extern void (*D_0064A300)();
extern "C" void func_00507A68();
extern "C" int func_0050A958() throw();
extern "C" int func_0050A968();
extern "C" int func_0050B460(int, int, int, void *);
extern "C" int func_00509C48(S s) {
    char buf[0x84];
    if (D_00853538 != 0) {
        if (func_0050A968() != 1) return -5;
        if (func_0050A958() == 0) return -6;
        D_0064A300 = func_00507A68;
        return func_0050B460(1, 0xe2, 0x84, buf) == 0 ? 0 : -7;
    }
    return -5;
}
