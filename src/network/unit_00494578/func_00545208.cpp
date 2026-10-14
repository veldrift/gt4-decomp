/* compiler: ee-gcc2.96-no-strict-aliasing */
extern int D_0064C2DC;
extern "C" unsigned int func_00539528() throw();
extern "C" void func_00539670(unsigned int) throw();
extern "C" void func_00545208(unsigned int *out, unsigned int n) {
    unsigned int i = 0;
    if (n > 1024) n = 1024;
    if (!D_0064C2DC) {
        D_0064C2DC = 1;
        func_00539670(0x2eb3ae77);
    }
    if (n > 32) {
        unsigned int *p = out;
        do {
            n -= 32;
            ++i;
            *p ^= func_00539528();
            ++p;
        } while (n > 32);
    }
    unsigned int r = func_00539528();
    unsigned int *e = out + i;
    *e = (r | 0x80000000u) >> -n;
    ++i;
    for (; i < 32; ++i) out[i] = 0;
}
