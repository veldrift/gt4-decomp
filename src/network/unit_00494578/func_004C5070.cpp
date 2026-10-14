/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
extern u16 D_006B9818[];
extern u16 D_006B9890[];
extern u16 D_006B98C0[];
extern u16 D_006B98D0[];
extern u16 D_006B9948[];
extern "C" int func_004C51C0(u16 *, int);
extern "C" int func_004C5070(u16 *dst, u16 *src, int n) {
    u16 *start = dst;
    while (n--) {
        u16 c = *src++;
        int k = func_004C51C0(D_006B9818, c);
        if (k >= 0) {
            *dst = D_006B98D0[k];
        } else {
            k = func_004C51C0(D_006B9890, c);
            if (k >= 0) {
                *dst++ = D_006B9948[k];
                *dst = 0x8EDE;
            } else {
                k = func_004C51C0(D_006B98C0, c);
                if (k >= 0) {
                    *dst++ = D_006B9948[k];
                    *dst = 0x8EDF;
                } else {
                    *dst = c;
                }
            }
        }
        dst++;
    }
    return dst - start;
}
