typedef int s32;
typedef long s64;
struct In { s32 f0; };
extern "C" s32 func_00529E30(s32, s64);
extern "C" s32 func_00524C50(In *p, s64 h) {
    s32 r=2;
    s64 value=h;
    if(p) r=func_00529E30(p->f0,*(volatile s64 *)&value);
    return r;
}
