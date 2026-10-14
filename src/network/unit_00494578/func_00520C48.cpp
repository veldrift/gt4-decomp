extern int D_0064B43C;
extern char D_00863C08[];
extern "C" void func_00522138(void);
extern "C" int func_00522598(void);
extern "C" void *func_005A48D8(void *, int, unsigned int);

extern "C" int func_00520C48(void) {
    if (D_0064B43C == 0) {
        int r = func_00522598();
        if (r != 0) {
            return r;
        }
        func_00522138();
        func_005A48D8(D_00863C08, 0, 0x224);
    }
    D_0064B43C++;
    return 0;
}
