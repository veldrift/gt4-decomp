typedef int s32;
typedef short s16;
extern s16 D_0064A164;
extern s32 D_0064A150;
extern char D_006C1220[];
extern "C" s32 func_0052FBD8(s32);
extern "C" void func_0057D9C0(const char *, ...);
extern "C" s32 func_005055B8(void) {
    if (D_0064A164 != 1) return -12;
    s32 e = func_0052FBD8(D_0064A150);
    D_0064A150 = 0;
    if (e == 0) return e;
    func_0057D9C0(D_006C1220, e);
    return -3;
}
