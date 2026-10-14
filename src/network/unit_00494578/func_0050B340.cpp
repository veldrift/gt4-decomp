typedef int s32;
extern char D_0064A318[];
extern "C" void func_005A6AB0(void *, void *, s32);
extern "C" s32 func_0050B340(void *dst) {
    if (D_0064A318[0] == 0) return -11;
    func_005A6AB0(dst, D_0064A318, 0x11);
    return 0;
}
