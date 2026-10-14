/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_006B04B8[], D_006B04E8[];
extern "C" int func_0057F260(const char *);
extern "C" int func_004B8BF0(int a, int b) {
    int n = func_0057F260(D_006B04B8);
    int i = 0;
    if (n > 0) {
        char *p = D_006B04B8 + 1;
        do {
            if (p[-1] == a && p[0] == b) {
                int h = i / 2;
                int l = func_0057F260(D_006B04E8);
                return h + l + 1;
            }
            i += 2;
            p += 2;
        } while (i < n);
    }
    return -1;
}
