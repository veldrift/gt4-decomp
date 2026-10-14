struct Obj { char pad[0x58]; int (*f58)(); int pad5c; int (*f60)(); int pad64[2]; int (*f6c)(); char pad70[0x38]; int (*fa8)(); char padac[0x64]; int x110; };
struct Other { char pad[0x10]; int (*f10)(); };
extern Obj *D_0064B4B4, *D_0064B4BC;
extern Other *D_0064B4A8;
extern int D_0064B4F0;
extern "C" void func_00531738(int *) throw();
extern "C" int func_005354B8(void *) throw();
extern "C" int func_005359C8();
extern "C" void *func_00535A18(unsigned int);
extern "C" int func_00536308();
extern "C" int func_0053A0E8();
extern "C" int func_00535680() {
    func_00536308();
    if (D_0064B4B4) {
        D_0064B4B4->fa8();
        D_0064B4B4->f58();
        D_0064B4B4->f60();
    }
    func_0053A0E8();
    if (D_0064B4B4 && D_0064B4B4->x110) func_00531738(&D_0064B4B4->x110);
    for (int i=0; i<4; ++i) func_005354B8(func_00535A18(i));
    func_005359C8();
    if (D_0064B4F0) {
        D_0064B4BC->f6c();
        D_0064B4F0 = 0;
    }
    if (D_0064B4A8) D_0064B4A8->f10();
    return 0;
}
