typedef int s32;
struct O { char p0[8]; s32 f8; s32 fC; char p10[0xC]; s32 f1C; };
extern "C" s32 func_005220F8(void);
extern "C" s32 func_005216D8(O *, s32 *);
extern "C" s32 func_005230A8(s32, s32 *);
extern "C" s32 func_005214F0(O *o, s32 *out) {
    *out = 0;
    if (func_005220F8() == 0) return 2;
    if (o->f1C == 0 && o->fC == 0) {
        s32 loc = 0;
        s32 r = func_005216D8(o, &loc);
        if (r != 0) return r;
        if (loc == 0) {
            *out = 0;
            return 0;
        }
        o->f1C = 1;
    }
    return func_005230A8(o->f8, out);
}
