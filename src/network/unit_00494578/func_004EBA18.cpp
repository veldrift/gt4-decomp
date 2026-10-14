/* compiler: ee-gcc2.96-no-strict-aliasing */
extern unsigned char D_006D0E79[];
extern "C" signed char func_004EBA18(signed char c) {
    int f = D_006D0E79[c] & 1;
    int r = c;
    if (f) r = c + 0x20;
    return r;
}
