typedef int s32;
typedef short s16;
extern s32 D_0064A308;
extern s32 D_0064A30C;
extern s16 D_0064A310;
extern char D_0064A318[];
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" void func_0050B5F8() throw();
extern "C" s32 func_0052E6D8(void);
extern "C" s32 func_0050B378(void) {
    func_005A48D8(D_0064A318, 0, 0x11);
    if (D_0064A308 != 1) return -15;
    if (D_0064A30C != 0) {
        func_0050B5F8();
        D_0064A30C = 0;
    }
    if (func_0052E6D8() != 0) return -4;
    D_0064A308 = 0;
    D_0064A310 = 0;
    return 0;
}
