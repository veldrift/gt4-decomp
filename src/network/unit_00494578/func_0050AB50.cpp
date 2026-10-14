extern int D_0064A340;
extern char D_008535B0[];
extern char D_00853678[];
extern "C" void func_005A4724(void *, const void *, unsigned int);
extern "C" void func_0050AB50(void *data) {
    int type = D_0064A340;
    if (type != 18) {
        if (type == 44) return func_005A4724(data, D_008535B0, 0xC4);
    } else {
        func_005A4724(data, D_00853678, 0xEC);
    }
}
