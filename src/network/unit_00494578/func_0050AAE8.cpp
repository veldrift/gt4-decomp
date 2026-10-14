extern int D_0064A340;
extern char D_008535B0[];
extern char D_00853678[];
extern "C" void func_005A4724(void *, const void *, unsigned int);
extern "C" void func_0050AAE8(int type, const void *data) {
    D_0064A340 = type;
    if (type != 18) {
        if (type == 44) return func_005A4724(D_008535B0, data, 0xC4);
    } else {
        func_005A4724(D_00853678, data, 0xEC);
    }
}
