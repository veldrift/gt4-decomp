typedef int s32;
typedef long s64;
typedef float f32;
struct S { char pad[0x10]; void *f10; };
extern "C" s32 func_0057F238(s32, const char *);
extern "C" s32 dpdiv(s64, s32);
extern "C" f32 dptofp(s32);
extern "C" s32 func_0057FB50(f32);
extern "C" void func_002C3C30(void *, s32, f32);
extern "C" void func_0023F938(S *arg0, s32 arg1, f32 fparg0) {
    if (func_0057F238(arg1, "keep") != 0) {
        s64 k = 0xFFC0;
        func_002C3C30(arg0->f10, arg1, dptofp(dpdiv(k << 46, func_0057FB50(fparg0 * 60.0f))));
    }
}
