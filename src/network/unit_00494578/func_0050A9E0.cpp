struct B30 { char b[0x30]; };
extern char D_00853580[];
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void func_0050A9E0(B30 s) {
    func_005A4724(D_00853580, &s, 0x30);
}
