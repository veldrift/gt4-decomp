typedef int s32;
extern char D_006C1370[];
extern "C" int func_0057DA20(void *, void *, s32, s32, s32);
extern "C" void func_005A6AB0(void *, void *, s32) throw();
extern "C" s32 func_005062C8(char *dst, s32 n) {
    char buf[0x40];
    func_0057DA20(buf, D_006C1370, 2, 8, 6);
    func_005A6AB0(dst, buf, n);
    dst[n - 1] = 0;
    return 0;
}
