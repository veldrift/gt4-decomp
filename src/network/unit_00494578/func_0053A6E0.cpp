extern "C" char *func_0053A6E0(char *d, const char *s, int n) {
    char *r = d;
    if (n != 0) {
        do {
            n--;
            if (n == -1) break;
        } while ((*d++ = *s++) != 0);
        d[-1] = 0;
    }
    return r;
}
