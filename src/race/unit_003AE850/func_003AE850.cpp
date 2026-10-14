/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int D_00621874;
extern "C" int DisplayRText__load_rtext(void);
extern "C" void func_003AE918(int);
extern "C" void func_003AE9A0(void);
extern "C" int func_003AE850(void) {
    int *p = &D_00621874;
    if (*p == 0) {
        DisplayRText__load_rtext();
        func_003AE918(0x66);
        func_003AE9A0();
    }
    ++*p;
}
