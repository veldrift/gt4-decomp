extern "C" int func_004FEF58(int a, int b, int c);
extern "C" void func_00577F80(void);

extern "C" void func_004FEEF8(int a, int b, int c) {
    while (func_004FEF58(a, b, c) == 0) {
        func_00577F80();
    }
}
