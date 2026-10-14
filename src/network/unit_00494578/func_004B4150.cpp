/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_004BB230(int, int, char *, int, unsigned char);
extern "C" int func_004B9978(unsigned short *, int, const char *);
extern "C" int func_0057F260(const char *) throw();
extern "C" int func_004B4150(int arg0, int arg1, unsigned short *out, int cap, unsigned char flag) {
    char buf[256];
    int n = 0;
    int result = func_004BB230(arg0, arg1, buf, 256, flag);
    func_004B9978(out, cap, buf);
    unsigned short *p = out;
    if (*p) {
        do {
            ++p;
            ++n;
        } while (*p);
    }
    ++n;
    int len = func_0057F260(buf) + 1;
    func_004B9978(out + n, cap - n, &buf[len]);
    return result;
}
