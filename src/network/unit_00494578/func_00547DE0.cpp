typedef int s32;

extern "C" void func_00547858(void);
extern "C" s32 D_0064C3C4;

extern "C" void func_00547DE0(void) {
    if (D_0064C3C4 != 0) {
        D_0064C3C4 = 0;
        func_00547858();
    }
}
