extern "C" unsigned int func_005A2F88(signed char *) throw();
extern "C" void func_005A6AB0(void *, const void *, int) throw();
extern "C" int func_00512408(signed char *arg0, void *arg1, int *arg2, int *arg3) {
    signed char *p = arg0;
    int n = 0;
    while (*p != '.') { ++p; ++n; }
    if (*p == '.') ++p;
    func_005A6AB0(arg1, arg0, n - 1);
    unsigned int v = func_005A2F88(p);
    *arg2 = (v >> 7) & 0x1FF;
    *arg3 = v & 0x7F;
    return 0;
}
