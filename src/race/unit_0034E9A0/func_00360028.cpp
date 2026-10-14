extern "C" float func_0034FCC0(char *self, int index, float *out);
extern "C" void func_00360028(char *arg0, int arg1, float *arg2, float *arg3, float fparg0, float fparg1) {
    char *p;
    int v;
    float tmp;
    p = arg0 + arg1 * 0xEC;
    v = (unsigned char)p[0x1ED];
    if (v < 10) {
        if (v < 7 && v != 0) {
            return;
        }
    } else if (v != 12) {
        return;
    }
    *arg2 = fparg0 * func_0034FCC0(arg0, arg1, &tmp);
    *arg3 = fparg1 * tmp;
}
