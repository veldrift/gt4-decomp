/* compiler: ee-gcc2.96-no-strict-aliasing */
extern signed char D_006B0C80[];
extern "C" int func_004B9930(unsigned char *p) {
    int n = 0;
    while (*p) {
        int step = D_006B0C80[*p];
        if (!step) break;
        p += step;
        ++n;
    }
    return n;
}
