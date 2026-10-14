typedef int s32;
struct B { char b[0x80]; };
extern "C" s32 func_00544880(void *) throw();
extern "C" void func_005460C8(void *, void *);
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void func_00544E20(void *dst, void *a1, void *src) {
    B a, b;
    func_005A4724(&a, a1, 0x80);
    func_005A4724(&b, src, 0x80);
    for (;;) {
        func_005460C8(&a, &b);
        if (func_00544880(&a)) {
            func_005A4724(dst, &b, 0x80);
            return;
        }
        func_005460C8(&b, &a);
        if (func_00544880(&b)) {
            func_005A4724(dst, &a, 0x80);
            return;
        }
    }
}
