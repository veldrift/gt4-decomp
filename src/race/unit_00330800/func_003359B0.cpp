/* compiler: ee-gcc2.96-no-strict-aliasing */
extern unsigned int D_008434F0;
extern "C" unsigned int func_00579330(unsigned int *);
extern "C" unsigned long func_003359B0() {
    unsigned long hi = func_00579330(&D_008434F0);
    unsigned long lo = func_00579330(&D_008434F0);
    return (hi << 32) | lo;
}
