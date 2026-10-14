extern "C" int func_0057F238(const char *, const char *) throw();
extern const char *D_00618DE0[];

extern "C" int func_001F0DC0(const char *name) {
    int r = 0;
    int i = 0;
    while (i < 3) {
        if (func_0057F238(name, D_00618DE0[i]) == 0) {
            r = i;
            break;
        }
        i++;
    }
    return r;
}
