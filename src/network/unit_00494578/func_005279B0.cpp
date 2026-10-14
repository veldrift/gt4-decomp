typedef unsigned short u16;
extern "C" int func_005279B0(char *o, u16 *out) {
    u16 min = 0xFFFE;
    u16 best = 0xFFFF;
    int ret = 2;
    if (out) {
        char *p = *(char **)(o+0x84);
        *out = 0xFFFE;
        u16 i = 0;
        u16 n = *(u16 *)(o+0x9C);
        char *arr = p;
        if (n) {
            do {
                int status = *(int *)p;
                if ((status == 3 || status == 6) && *(u16 *)(p+0x2C) < min) {
                    min = *(u16 *)(p+0x2C);
                    best = i;
                }
                i = (i+1) & 0xFFFF;
                p += 0x44;
            } while (i < n);
        }
        int *e = (int *)(arr+best*0x44);
        if (*e == 3) {
            *out = best;
            *e = 4;
        } else if (*e == 6) {
            *out = best;
            *e = 7;
        }
        ret = 0;
    }
    return ret;
}
