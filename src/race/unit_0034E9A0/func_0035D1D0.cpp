struct Obj;
extern "C" int func_0035C7C8(Obj *arg0);
extern "C" int func_0035D158(char *arg0);
extern "C" void func_0035D1D0(char *arg0) {
    unsigned char *p;
    int t;
    if (func_0035C7C8((Obj *)arg0)) {
        p = (unsigned char *)(arg0 + 0x788);
        if (func_0035D158(arg0) == 0) {
            if (*p != 0) {
                *p = *p + 0xFF;
            }
        } else {
            t = *p + 1;
            if (t >= 0x23) {
                t = 0x22;
            }
            *p = t;
        }
    }
}
