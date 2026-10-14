/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct B8 { char b[8]; };
struct Obj { s32 f0; char pad[8]; s32 fC; s32 *f10; };
extern "C" void func_00503300(void *, s32, s32);
extern "C" void func_005223B8(void *, B8);
extern "C" void func_00523130(B8 *);
extern "C" s32 func_0052F6F0(s32 *, s32);
extern "C" void func_004FFA30(Obj *o) {
    B8 a;
    char obj[16];
    s32 v;
    s32 *out = o->f10;
    if (o->fC == 0) {
        func_00523130(&a);
        func_005223B8(obj, a);
        func_0052F6F0(&v, o->f0);
        func_00503300(obj, v, 1);
        out[0] = 1;
    } else {
        out[1] = 1;
    }
}
