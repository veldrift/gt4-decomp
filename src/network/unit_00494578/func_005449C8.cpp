typedef unsigned int u32;

extern "C" void func_005449C8(u32 *arg0, u32 arg1) {
    u32 *p = arg0;
    u32 i = 0;
    goto test;
    for (;;) {
        i++;
        p++;
    test:
        if (i >= 0x20) {
            return;
        }
        if (i != 0) {
            u32 v = *p + 1;
            *p = v;
            if (v != 0) {
                return;
            }
        } else {
            u32 s = *p + arg1;
            *p = s;
            if (s >= arg1) {
                return;
            }
        }
    }
}
