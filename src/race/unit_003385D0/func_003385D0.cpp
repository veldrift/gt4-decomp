extern char D_008434F0;
extern char D_006201B0;
extern char D_006201B8;

extern "C" void func_005792D8(void *a);
extern "C" void func_00387B30(void *a, void *b);

extern "C" void func_003385D0(int arg0, int arg1) {
    if (arg1 == 0xFFFF && arg0 == 1) {
        func_005792D8(&D_008434F0);
    }
    if (arg1 == 0xFFFF && arg0 == 1) {
        func_00387B30(&D_006201B0, &D_006201B8);
    }
}

extern "C" void func_00338620(void) {
    func_003385D0(1, 0xFFFF);
}
