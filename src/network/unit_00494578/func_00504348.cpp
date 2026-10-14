/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O {
    char *m0;
    int m4;
};
extern char D_006497B0[];
extern "C" void func_00503A90(void *) throw();
extern "C" int func_00503E70(char *) throw();

extern "C" int func_00504348(O *o) {
    char *p = o->m0;
    if (p == 0) {
        func_00503A90(D_006497B0);
        o->m0 = D_006497B0;
        p = D_006497B0;
    }
    int r = func_00503E70(p);
    o->m4 = r;
    return r != 0;
}
