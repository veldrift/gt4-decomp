typedef short s16;
extern s16 D_0064A164;
extern int D_0064A168;
extern char D_006C1198[];
extern "C" int func_0052E6D8(void);
extern "C" void func_0057D9C0(const char *fmt, ...);

extern "C" int func_00505438(void) {
    int r = 0;
    if (D_0064A164 != 1) {
        return -0xC;
    }
    if (D_0064A168 == 1) {
        r = func_0052E6D8();
    }
    if (r == 0) {
        D_0064A164 = 0;
        return 0;
    }
    func_0057D9C0(D_006C1198, r);
    return -7;
}
