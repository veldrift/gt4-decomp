/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_004C4F38(unsigned short);
extern "C" int func_004C4E58(const unsigned short *src) {
    int n = 0;
    for (;;) {
        if (*src == 0) goto done;
        int c = func_004C4F38(*src++);
        if (n == 0 && c != 1) goto done;
        if (c == 0) goto done;
        ++n;
    }
done:
    return n;
}
