typedef int s32;
extern s32 D_0064A308;
extern s32 D_0064A30C;
extern char D_00853768[];
extern "C" int func_0057D9C0(const char *, ...);
extern "C" s32 func_0050B460(s32, s32, s32, void *);
extern "C" s32 func_0050BC50(void) {
    func_0057D9C0("IDF... MediusAccountLoginInternal\n");
    if (D_0064A308 != 1) return -15;
    if (D_0064A30C == 0) return -16;
    return func_0050B460(1, 7, 0x66, D_00853768) ? -5 : 0;
}
