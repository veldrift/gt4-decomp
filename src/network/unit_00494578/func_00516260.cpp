struct G { char pad[0x118]; int m118; };
extern G D_00854038;
extern "C" void func_00516130(unsigned int) throw();
extern "C" int func_00532588(int, int, int, int, void *);

extern "C" int func_00516260(unsigned int a) {
    unsigned short h;
    if (a >= 0x1000) {
        return 0x17;
    }
    if (D_00854038.m118 == 0) {
        return 8;
    }
    func_00516130(a);
    h = a;
    func_00532588(D_00854038.m118, -1, 0xA, 2, &h);
    return 0;
}
