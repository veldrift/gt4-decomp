extern "C" void func_00360200(char *arg0, int arg1, float *arg2, float *arg3, float fparg0, float fparg1) {
    char *p;
    int v;
    p = arg0 + arg1 * 0xEC + 0x164;
    v = (unsigned char)p[0x89];
    if (v < 5) {
        if (v >= 2) {
            *arg2 = fparg0 * *(float *)(p + 0xB4);
            *arg3 = fparg1 * *(float *)(p + 0xB8);
        }
    }
}
