/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_004FF270(void *, int, int, int);
extern "C" void func_00577F80(void);

extern "C" void func_004FF200(void *a, int b, int c, int d) {
    while (func_004FF270(a, b, c, d) == 0) {
        func_00577F80();
    }
}
