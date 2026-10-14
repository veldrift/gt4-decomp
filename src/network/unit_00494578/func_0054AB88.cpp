/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char *D_0064C3E4;
extern "C" int func_0054A370() throw();
extern "C" int func_0054A8A8(int, int) throw() __attribute__((const));
extern "C" void func_00549858(char *, int, int) throw();
extern "C" int func_005622A8(int, int, int);
extern "C" int func_0054AB88(int id, int arg1) {
    int status = 1;
    if (func_0054A370()) {
        int q = id / 4;
        int r = id - q * 4;
        status = 9;
        int result = func_005622A8(q, r, arg1);
        if (result == 0) status = 0;
        status = func_0054A8A8(status, result);
        int off = (q * 111 + r * 27) * 4;
        func_00549858((char *)(off + (int)D_0064C3E4) + 0x78, result, status);
        *(int *)((char *)(off + (int)D_0064C3E4) + 0xCC) = 1;
        *((char *)(off + (int)D_0064C3E4) + 0x78) = 0;
    }
    return status;
}
