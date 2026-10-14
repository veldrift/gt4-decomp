/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj { char p[0xCC0]; s32 fCC0; char p2[0x30C]; s32 fFD0; };
extern "C" void func_004F9C08(Obj *, s32);
extern "C" void func_004FABC0(Obj *o, s32 unused, s32 v) {
    o->fFD0 = o->fFD0 + 1;
    if (v == o->fCC0) o->fCC0 = -1;
    func_004F9C08(o, v);
}
