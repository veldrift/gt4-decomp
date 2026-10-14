extern "C" void func_00544830(int *, int) throw();
extern "C" int func_00544880(int *) throw();
extern "C" void func_00544B38(int *, int *, int *) throw();
extern "C" unsigned func_00545A54(int *);
extern "C" void func_00546668(int *, int *, int *, int *);
extern "C" void func_005A2E98(const char *, int, const char *);
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern char D_006C5200[], D_006C5248[];
extern "C" void func_00544EC8(int *dst, int *base, int *exponent, int *modulus) {
    unsigned i;
    int out[32], power[32];
    int *cursor;
    unsigned mask = 1;
    unsigned bits = func_00545A54(exponent);
    func_00544B38(power, base, modulus);
    if (func_00544880(modulus)) {
        func_005A2E98(D_006C5200, 0x2A7, D_006C5248);
        func_005A4724(dst, modulus, 0x80);
        return;
    }
    func_00544830(out, 1);
    i = 0;
    if (bits) {
        cursor = exponent;
        do {
            if (i) {
                mask <<= 1;
                func_00546668(power, power, power, modulus);
                if (mask == 0) {
                    mask = 1;
                    ++cursor;
                }
            }
            if (mask & *cursor) func_00546668(out, out, power, modulus);
            ++i;
        } while (i < bits);
    }
    func_005A4724(dst, out, 0x80);
}
