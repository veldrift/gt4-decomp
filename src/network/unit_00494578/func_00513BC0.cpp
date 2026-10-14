struct Input { int offset, a, b, status; char name[21]; };
struct Packet { char data[0x1D0]; int offset, size, a, b, status; char name[21]; };
extern char *D_006D622C;
extern int D_006D6230;
extern int D_0064A308;
extern int D_008A0338;
extern void (*D_008A0560)(Packet *, int);
extern "C" int func_0050B460(int, int, int, Packet *) throw();
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" int func_00513BC0(int arg0, int arg1, int arg2, Input *input) {
    Packet p;
    p.offset = ((const volatile Input *)input)->offset;
    p.size = 0;
    p.a = ((const volatile Input *)input)->a;
    p.b = ((const volatile Input *)input)->b;
    p.status = ((const volatile Input *)input)->status;
    func_005A4724(p.name, input->name, 21);
    if (p.b) {
        int n = D_006D6230 - p.offset;
        if (n >= 0x1D1) n = 0x1D0;
        p.size = n;
        func_005A4724(p.data, D_006D622C + p.offset, n);
    }
    if (D_0064A308 != 1) p.status = -0x3C6;
    if (D_008A0560) D_008A0560(&p, D_008A0338);
    func_0050B460(1, 0xA8, 0x1FC, &p);
    return 40;
}
