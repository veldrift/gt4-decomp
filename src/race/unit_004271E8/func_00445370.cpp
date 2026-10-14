struct Db { char p[0x1E4]; int f1E4; };
extern Db D_006235A8;
extern char D_006A6DD0[];
extern "C" long func_004454C0();
extern "C" int SPEC_DATABASE__DatabaseStorage__getRow_2(void *, int, int, void *);
extern "C" const char *func_00449CD8(int, int);

extern "C" const char *func_00445370() {
    int v;
    int key = (int)((unsigned long)func_004454C0() & 0xFFFFFFFFUL);
    if (SPEC_DATABASE__DatabaseStorage__getRow_2(&D_006235A8, key, 0x27, &v) == 0)
        return D_006A6DD0;
    return func_00449CD8(D_006235A8.f1E4, v);
}
