struct O { char pad[0x14]; char f14; char pad15[3]; unsigned f18; };
struct T { char pad[0xEC]; int fEC; int fF0; };
extern int D_0064A308, D_0064A30C, D_0064A334, D_0064A330;
extern unsigned D_006D6228;
struct U { char pad[0xEC]; void *fEC; int fF0; };
extern T D_008A0190;
extern U D_008A03B8;
extern "C" int func_0050B460(int, int, int, int) throw();
extern "C" int func_0050DF58(O *o, void *a1, int a2, int a3, int a4) {
    o->f14 = 0;
    if (D_0064A308 != 1) return -15;
    if (D_0064A30C == 0) return -16;
    unsigned fl = o->f18;
    if (fl & 1) {
        D_006D6228 = 0x78;
        if (fl & 2) D_006D6228 = 0x7A;
        if (fl & 0x200) D_006D6228 |= 0x200;
        o->f18 = D_006D6228;
    } else {
        D_006D6228 = fl;
    }
    D_0064A330 = 0;
    D_0064A334 = 1;
    D_008A03B8.fEC = a1;
    D_008A0190.fEC = a4;
    D_008A0190.fF0 = a4;
    D_008A03B8.fF0 = a2;
    return func_0050B460(1, 0xC8, 0x24, (int)o) == 0 ? 0 : -5;
}
