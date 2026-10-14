/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct In { char pad[0x2C]; s32 *p2C; };
extern In *D_006452D4;
extern "C" void func_004BC6E8(In *);
extern "C" s32 func_004C9790(In *, s32, s32);
extern "C" s32 func_004BC118(s32 a, s32 b) {
    if (*D_006452D4->p2C == 0x65) return 0x80000275;
    if (a == 0) return 0x80004675;
    if (b <= 0) return 0x80004775;
    func_004BC6E8(D_006452D4);
    return func_004C9790(D_006452D4, a, b);
}
