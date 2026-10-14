typedef int s32;
extern s32 D_0064A308;
extern s32 D_0064A30C;
extern char D_008537D0[];
extern "C" int func_0057D9C0(const char *, ...);
extern "C" s32 func_0050B460(s32, s32, s32, void *);
extern "C" s32 func_0050BE40(void) {
    func_0057D9C0("IDF... MediusAccountLogoutInternal\n");
    if (D_0064A308 != 1) return -15;
    if (D_0064A30C == 0) return -16;
    return func_0050B460(1, 0x15, 0x26, D_008537D0) ? -5 : 0;
}
