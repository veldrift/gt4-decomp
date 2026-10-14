extern "C" int func_0051BE28(void) throw();
extern "C" int func_0051BE60(void) throw();
extern "C" int func_0051DCF8(unsigned int);
extern "C" int func_0051D1F0(unsigned int, int);
extern "C" int func_0051D798(void);
extern "C" unsigned int D_0064AE10;
extern "C" int D_00863798;
extern "C" int func_0051C340(int arg) {
    int result = 0;
    int r = func_0051BE28();
    if (r == 0) {
        unsigned int i = 0;
        if (D_0064AE10 != 0) {
            do {
                if (func_0051DCF8(i) != 0)
                    result = func_0051D1F0(i, arg);
                i++;
            } while (i < D_0064AE10 && result == 0);
        }
        if (D_00863798 != 0 && arg != 0 && result == 0)
            result = func_0051D798();
        func_0051BE60();
        r = result;
    }
    return r;
}
