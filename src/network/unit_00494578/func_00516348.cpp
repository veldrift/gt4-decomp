struct R {
    char pad0[8];
    int m8;
    int mC;
};
extern "C" char *func_00515DD8(int) throw();
extern "C" R *func_0051B8A8(int, unsigned int);
extern "C" int func_0057F238(const char *, const char *) throw();
extern signed char D_00854040[];

extern "C" int func_00516348(const char *s, int a1, int a2) {
    R *r;
    int i;
    int idx;
    if (s != 0) {
    r = func_0051B8A8(a1, a2);
    if (r != 0) {
    i = 0;
    if (r->mC > 0) {
        do {
            idx = i + r->m8;
            i++;
            if (D_00854040[idx + 0xE630] == 2) {
                char *q = func_00515DD8(idx);
                if (q != 0 && func_0057F238(q + 0xC, s) == 0) {
                    return idx;
                }
            }
        } while (i < r->mC);
    }
    }
    }
    return -1;
}
