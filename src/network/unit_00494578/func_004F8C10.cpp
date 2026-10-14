/* compiler: ee-gcc2.96-nogcse */
extern "C" int func_0052E9E0(int *);
extern "C" int func_004F8C10(void) {
    int out;
    bool ok = func_0052E9E0(&out) == 0;
    if (ok) return out;
    return -1;
}
