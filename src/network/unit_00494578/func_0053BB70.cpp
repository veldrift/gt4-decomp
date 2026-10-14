extern "C" int func_0053B5E0(const char *, const char *, int) throw();
extern "C" void func_005A6AB0(void *, void *, int) throw();
extern "C" void func_005A6900(void *, void *, int);
extern "C" int func_0053BB70(char *arg0, int arg1, void *arg2) {
    if (!arg0) return 2;
    if (!arg2) return 2;
    char *p;
    if (arg1 == 0x1000) p = arg0 + 0x1004;
    else if (arg1 == 0x800) p = arg0 + 0xc04;
    else return 2;
    if (func_0053B5E0(p, "http", 4) == 0) {
        func_005A6AB0(arg2, p, 0x800);
    } else {
        func_005A6AB0(arg2, arg0 + 4, 0x800);
        func_005A6900(arg2, p, 0x800);
    }
    return 0;
}
