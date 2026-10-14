typedef unsigned char u8;
extern signed char D_006B0C80[];
extern "C" char *func_005A609C(char *, const char *);
extern "C" void func_0048F708(u8 *dst, u8 *src, int n, const char *s) {
    int i = 0;
    int k;
    if (n > 0) {
        do {
            signed char len = D_006B0C80[*src];
            k = 0;
            if (len > 0) {
                k = len;
                do {
                    *dst++ = *src++;
                    k--;
                } while (k != 0);
                k = len;
            }
            i++;
            if (!(i < n)) break;
            k++;
        } while (k < n);
    }
    func_005A609C((char *)dst, s);
}
