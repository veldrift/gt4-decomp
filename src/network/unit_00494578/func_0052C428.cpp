extern "C" int func_0057F188(const char *, const char *, unsigned int);

extern "C" int func_0052C428(int a0, const char *a1, int *p) {
    int r = 0;
    short buf;
    if (p == 0) {
        return 0xD2F3;
    }
    buf = 0;
    if (func_0057F188((char *)&buf, a1, 2) != 0 || *p != 0xD) {
        r = 0xD2F4;
        if (*p != 0xD) {
            r = 0xD2F5;
        }
    }
    return r;
}
