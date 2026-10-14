extern short D_0064A164;
extern int D_0064A150;
extern int D_008A0160, D_008A0128;
extern "C" int func_00506278(int, int);
extern "C" int func_0052EAF8(int, int, int, int, int, int, int);
extern "C" int func_005052A8(int a0, int a1, int a2) {
    func_00506278(a0, 0x15);
    if (D_0064A164 != 1) return -12;
    D_008A0160 = a1;
    D_008A0128 = a2;
    return func_0052EAF8(0x40, D_0064A150, 0xFFFF, 3, 5, 0x15, a0) == 0 ? 0 : -5;
}
