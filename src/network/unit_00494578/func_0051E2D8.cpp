extern "C" int func_0051F9D8(char *);
extern "C" int func_00538460(char *, int, int);
extern "C" int func_005385E0(char *, unsigned int *);
extern int D_0064AE18;
extern "C" int func_0051E2D8(char *obj, unsigned int limit) {
    int result;
    unsigned int count[4];
    char *ctx = obj + 0x6c;
    count[0] = 0;
    func_005385E0(ctx, count);
    if (count[0] >= limit) goto zero;
    result = func_0051F9D8(obj);
    if (result != 0) return result;
    result = func_00538460(ctx, 1, D_0064AE18);
    if (result != 0) return result;
    func_005385E0(ctx, count);
    if (count[0] < limit) return 0xcb2c;
zero:
    return 0;
}
