/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj { char p[0x15C]; s32 f15C; char p2[0x28]; s32 f188; };
extern "C" s32 func_004F0D48(Obj *);
extern "C" s32 func_004F0DB0(Obj *o) {
    if (o->f15C != 0) {
        o->f188 = 0;
        return func_004F0D48(o);
    }
    return 0;
}
