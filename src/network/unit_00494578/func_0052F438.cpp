struct V { char pad[0x34]; int (*f34)(int); };
extern "C" V *D_0064B4B4;
extern "C" int func_00535780(int);
extern "C" int func_00536CF8(void);
extern "C" int func_00536D38(void);

static inline int finish() { return func_00535780(func_00536D38()); }
extern "C" int func_0052F438(int *out, int a) {
    int r = func_00535780(func_00536CF8());
    if (r != 0) return r;
    if (out == 0) return 0x17;
    *out = D_0064B4B4->f34(a);
    return finish();
}
