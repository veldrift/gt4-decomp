/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct B8 { char b[8]; };
struct Obj { char p[0xC]; void *fC; void *f10; };
extern "C" void func_005223B8(void *, B8);
extern "C" s32 func_00529320(void *, void *, B8 *, s32 *);
extern "C" s32 func_00503868(Obj *o, void *out1, s32 *out2) {
    s32 x;
    B8 a;
    if (func_00529320(o->fC, o->f10, &a, &x) == 0) {
        func_005223B8(out1, a);
        *out2 = x;
        return 1;
    }
    return 0;
}
