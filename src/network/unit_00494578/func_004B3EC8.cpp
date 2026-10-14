/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned short u16;
extern "C" int func_004B9978(u16 *, s32, char *);
extern "C" void func_004B9A80(void *, s32, s32);
extern "C" s32 func_004B9F90(void *, char *, s32);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" s32 func_004B3EC8(s32 a0, u16 *a1, s32 a2) {
    char sp0[0x100];
    char sp100[0x100];
    s32 n = 0;
    func_004B9A80(sp0, 0x100, a0);
    s32 r = func_004B9F90(sp0, sp100, 0x100);
    func_004B9978(a1, a2, sp100);
    u16 *p = a1;
    if (*p != 0) {
        do {
            p += 1;
            n += 1;
        } while (*p != 0);
    }
    n += 1;
    s32 l = func_0057F260(sp100) + 1;
    func_004B9978(&a1[n], a2 - n, sp100 + l);
    return r;
}
