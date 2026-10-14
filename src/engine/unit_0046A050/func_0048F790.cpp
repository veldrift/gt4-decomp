extern "C" int func_0057F260(const char *);
extern "C" void func_00490B98(int, float *, float *, const char *);
extern "C" int func_004B9930(const char *);
extern "C" void func_0048F708(int, const char *, int, const char *);
extern char D_006AE488[];

extern "C" int func_0048F790(int a, int b, int c, const char *s, float limit) {
    float o[2];
    const char *lit = D_006AE488;
    if (func_0057F260(s) + 3 >= c) return 0;
    func_00490B98(a, &o[0], &o[1], s);
    if (o[0] < limit) return 0;
    float r = limit / o[0];
    int k = (int)((float)func_004B9930(s) * r);
    while (k >= 0) {
        int cur = k;
        k--;
        func_0048F708(b, s, cur, lit);
        func_00490B98(a, &o[0], &o[1], (const char *)b);
        if (o[0] < limit) break;
    }
    return 1;
}
