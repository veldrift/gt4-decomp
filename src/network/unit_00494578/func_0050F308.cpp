/* compiler: ee-gcc2.96-nosib */
struct Obj {
    char pad0[0x24];
    int (*fn)(Obj *, int, int);
};

extern "C" Obj *D_0064A550;
extern "C" char D_006C2078[];
extern "C" void func_0057D9C0(const char *fmt, ...);

extern "C" int func_0050F308(int arg0, int arg1) {
    Obj *o = D_0064A550;
    int r = o->fn(o, arg0, arg1);
    int t = r;
    if (t != 0) {
        func_0057D9C0(D_006C2078, t);
        return -0xD;
    }
    return r;
}
