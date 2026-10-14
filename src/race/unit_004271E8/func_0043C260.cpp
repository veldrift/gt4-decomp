extern unsigned short D_00623158[];
extern "C" void func_004386F0(void *, int, int, int);
extern "C" short func_0055EF50(void *, int);
extern "C" void func_0043C260(int a0, void *a1, void *a2, signed char *a3) {
    int i = 0;
    do {
        int t = func_0055EF50(a2, i + 0x18);
        int w = t;
        unsigned short *q = D_00623158 + w;
        w = -w;
        w = w << 2;
        if (i != 0) w = *q;
        func_004386F0(a1, a0, a3[i], w);
        i++;
    } while (i < 3);
}
