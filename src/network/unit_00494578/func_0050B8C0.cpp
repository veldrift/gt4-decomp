struct O { char pad[0x14]; char f14; char f15; char pad16[0xF]; char f25; };
extern int D_0064A308, D_0064A30C;
extern int D_008A0198, D_008A03C0;
extern "C" int func_0050B460(int, int, int, O *) throw();
extern "C" int func_0050B8C0(O *o, int a1, int a2) {
    int r = -15;
    if (D_0064A308 != 1) return r;
    r = -16;
    if (D_0064A30C == 0) return r;
    r = -19;
    if (o == 0) return r;
    r = o->f15;
    if (r == 0) {
        r = -19;
    } else {
        o->f25 = 0;
        o->f14 = 0;
        D_008A03C0 = a1;
        D_008A0198 = a2;
        int c = func_0050B460(1, 5, 0x26, o);
        int x = -5;
        if (c == 0) x = 0;
        r = x;
    }
    return r;
}
