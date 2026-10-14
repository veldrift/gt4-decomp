extern unsigned char D_0064C1A0;
extern "C" void func_00539670(int);
extern "C" void func_00543BE0(void) {
    unsigned char *p = &D_0064C1A0;
    if (*p == 0) {
        *p = 1;
        return func_00539670(0x035D2325);
    }
}
