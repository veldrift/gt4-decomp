/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int D_00621878;
extern "C" unsigned int PDISTD__LOCALE;
extern "C" char D_00621880[];
extern "C" int D_00621888;
extern "C" char D_006A2308[], D_006A2320[];
extern "C" void *func_0048EDA0(unsigned int);
extern "C" int func_0057DA20(char *, const char *, ...) throw();
extern "C" int func_00485E28(void *, char *, int, int);
extern "C" int func_00485F48(void *, char *);
extern "C" int DisplayRText__load_rtext(void) {
    int *p = &D_00621878;
    if (*p == 0) {
        char buf[128];
        func_0057DA20(buf, D_006A2308, func_0048EDA0(PDISTD__LOCALE));
        *p = func_00485E28(D_00621880, buf, 0, -1);
        D_00621888 = func_00485F48(D_00621880, D_006A2320);
    }
}
