typedef int s32;
typedef unsigned char u8;
struct In { u8 b0; char p[0xB]; s32 fC; };
extern "C" s32 func_005ADCF0(s32);
extern "C" s32 func_00539B40(In *p, u8 *out) {
    s32 r = 2;
    if (p == 0) return r;
    u8 t = p->b0;
    if (t != 1) return r;
    if (out == 0) return r;
    *out = 0;
    if (func_005ADCF0(p->fC) != -1) *out = t;
    r = 0;
    return r;
}
