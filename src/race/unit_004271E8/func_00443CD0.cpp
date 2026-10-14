typedef unsigned int u32;
struct R { int a, b, c, d, e; };
extern "C" void func_004AF6B8(R *);
extern "C" R func_004AE6B0(char *);
extern "C" void func_005A5DC8(char *, const char *);
extern "C" char *func_005A609C(char *, const char *);
extern char *D_00623580[];

extern "C" u32 func_00443CD0(int unused, const char *a1, const char *a2) {
    char s[0x100];
    R r;
    u32 best = 0;
    for (int i = 0; i < 9; i++) {
        func_005A609C(s, a1);
        func_005A5DC8(s, D_00623580[i]);
        func_005A5DC8(s, a2);
        func_004AF6B8(&r);
        r = func_004AE6B0(s);
        if (best < (u32)r.c) best = r.c;
    }
    return best;
}
