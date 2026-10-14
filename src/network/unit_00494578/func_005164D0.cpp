extern "C" void func_00516130(int) throw();
extern signed char D_00854038[];

extern "C" int func_005164D0(void) {
    int i;
    for (i = 0; i < 0x1000; i++) {
        if (D_00854038[0xE638 + i] == 2) {
            func_00516130(i);
        }
        D_00854038[0xE638 + i] = 0;
    }
    return 0;
}
