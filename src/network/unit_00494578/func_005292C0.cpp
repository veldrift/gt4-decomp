extern char D_0064B4B0[];

struct Obj80 {
    char pad0[0x80];
    int f80;
};

extern "C" int func_005292C0(Obj80 *arg0, int arg1, int *arg2) {
    if (arg0 == 0)
        return 0xD2F2;
    int (*fn)(int) = *(int (**)(int))((char *)*(void **)D_0064B4B0 + 0x40);
    int r = fn(arg1);
    if (r != 0)
        return r;
    int t = arg0->f80;
    *arg2 = t;
    return 0;
}
