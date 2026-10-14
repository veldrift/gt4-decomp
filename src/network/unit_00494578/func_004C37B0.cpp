/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef short s16;
struct Obj { char p[0xC]; u32 *fC; };
extern "C" s16 func_004C37B0(Obj *o, u32 t) {
    u32 d = *o->fC;
    s16 r;
    if (d >= t) d = 0x0FFFFFFF - (d - t);
    else d = t - d - 1;
    if ((s32)d > 0x0FFFFFEF) {
        s32 v = d + 0xF0000010;
        r = v * 70 + 1000;
    } else {
        d = d + 0xF00003F8;
        r = 0x50;
        if ((s32)d >= 0x50) r = d;
    }
    return r;
}
