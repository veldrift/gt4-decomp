/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj { char p[0xCB8]; s32 fCB8; s32 fCBC; };
extern "C" void func_004F91F8();
extern "C" void func_004F94D0();
extern "C" s32 func_004F8C10(Obj *, void (*)()) throw();
extern "C" s32 func_004F8C40(Obj *o) {
    s32 a = o->fCB8;
    if (a == -1) {
        s32 r = func_004F8C10(o, func_004F91F8);
        o->fCB8 = r;
        if (r == a) return 0;
    }
    s32 b = o->fCBC;
    if (b == -1) {
        s32 r = func_004F8C10(o, func_004F94D0);
        o->fCBC = r;
        if (r == b) return 0;
    }
    return 1;
}
