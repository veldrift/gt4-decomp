/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_0057F260(const char *s) throw();

extern "C" unsigned long func_0044FEC0(const char *s) {
    int n = func_0057F260(s);
    unsigned long t = 0;
    int i;
    for (i = 0; i < n; i++)
        t += (unsigned char)s[i];
    unsigned long h = t & 0xFFFF;
    for (i = 0; i < n; i++) {
        unsigned char c = s[i];
        t = h >> 57;
        h <<= 7;
        h |= t;
        h += c;
    }
    return h;
}
