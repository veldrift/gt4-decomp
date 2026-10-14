/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_004FF800(void *, int, int, int, int, int, int);
extern "C" void func_00577F80(void);
extern "C" void func_004FF760(void *a, int b, int c, int d, int e, int f, int g) {
    while (func_004FF800(a, b, c, d, e, f, g) == 0) {
        func_00577F80();
    }
}
