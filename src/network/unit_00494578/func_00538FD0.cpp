extern "C" int func_00538FD0(signed char *p, int n) {
    if (p == 0) return 2;
    *p++ = n;
    *p++ = n >> 8;
    *p++ = n >> 16;
    *p++ = n >> 24;
    return 0;
}
