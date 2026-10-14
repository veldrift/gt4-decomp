typedef int s32;

extern "C" s32 func_0034C190(s32 arg0, s32 arg1);

extern "C" void DynamicsConductor__InitializeStandings(void *arg0) {
    char *base = (char *)arg0;
    char *a4 = base + 4;
    s32 m = -1;
    s32 *w;
    s32 k;
    s32 *s1;

    w = (s32 *)(base + 0xF8B8);
    k = 5;
    do {
        k -= 1;
        *w = m;
        w -= 1;
    } while (k >= 0);

    k = 0;
    if (*(s32 *)(base + 0xF8A0) > 0) {
        s1 = (s32 *)(a4 + 0xF8A0);
        do {
            s32 r = func_0034C190((s32)arg0, k);
            s32 t = k + 1;
            *(char *)(r + 0x5B3) = (char)t;
            *s1 = k;
            k = t;
            s1 += 1;
        } while (k < *(s32 *)(base + 0xF8A0));
    }
}
