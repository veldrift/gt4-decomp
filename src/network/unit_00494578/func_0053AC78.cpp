extern "C" unsigned char D_0064C10C;
extern char D_0086B3F8[];
extern "C" int func_0053A9F8(void) throw();
extern "C" int func_0053ACD0(void *a, int b);

extern "C" int func_0053AC78(int arg0) {
    int r = 2;
    if (arg0 != 0) {
        if (D_0064C10C == 0) {
            r = func_0053A9F8();
            if (r != 0)
                return r;
        }
        r = func_0053ACD0(D_0086B3F8, arg0);
    }
    return r;
}
