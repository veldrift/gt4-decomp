/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct S { s32 f0; char p4[0x3C]; void *f40; char p44[0x3C]; char f80[4]; };
extern s32 D_0064C3C8;
extern char D_0086CB80[];
extern S D_0086CC80;
extern "C" void func_00578148(void *, s32);
extern "C" s32 func_00578168(void *, s32, s32, s32, s32);
extern "C" s32 func_005782E8(s32, s32);
extern "C" void func_00578500(s32);
extern "C" void func_00548500(void) {
    s32 *g = &D_0064C3C8;
    *g = func_005782E8(1, 1);
    func_00578148(D_0086CB80, 0x50434456);
    func_00578148(&D_0086CC80, 0x50636476);
    func_00578500(D_0086CC80.f0);
    D_0086CC80.f40 = D_0086CC80.f80;
    func_00578168(&D_0086CC80, 0, 0, 0, 0);
}
