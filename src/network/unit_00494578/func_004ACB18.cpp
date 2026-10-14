/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self { char pad[0xEC]; int ec, f0; };
extern "C" void func_004B15B8();
extern "C" void func_004B1C70(Self *);
extern "C" int func_005487C0();
extern "C" int func_00549130(int, int, void *);
extern "C" void func_00577F80();
extern int D_00617AA4;
extern "C" void func_004ACB18(Self *o) {
    int buf[4];
    if (o->f0) {
        func_004B15B8();
        while ((o->ec = func_005487C0()) <= 0) {
            while (func_00549130(D_00617AA4, 0, buf) == 0)
                func_00577F80();
        }
    }
    func_004B1C70(o);
}
