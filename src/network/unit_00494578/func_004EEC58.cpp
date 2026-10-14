/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj { s32 f0; };
extern "C" s32 func_004EF8C0(Obj *, s32 *, s32);
extern "C" s32 func_004EEC58(Obj *o, s32 idx, s32 *out) {
    s32 arr[8];
    if (o->f0 == 0) return 0;
    s32 n = func_004EF8C0(o, arr, 8);
    if (idx < 0) return 0;
    if (idx >= n) return 0;
    *out = arr[idx];
    return 1;
}
