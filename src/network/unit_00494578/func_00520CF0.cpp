extern int D_0064B43C;
extern char D_00863C08[];
extern "C" int func_00521A58(void *);
extern "C" int func_00521B38(void *);
extern "C" int func_005226F0(void);
extern "C" int func_00520CF0(void) {
    if (D_0064B43C) {
        int r = func_00521A58(D_00863C08);
        if (r) return r;
        r = func_005226F0();
        if (r) return r;
        r = func_00521B38(D_00863C08);
        if (r) return r;
    }
    return 0;
}
