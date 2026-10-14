/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
struct St { char p[2]; u8 count; };
struct O { char p[0x234]; St state; };
struct S {
    char pad0[0x10];
    O *owner;
    char pad14[0x624 - 0x14];
    u8 f624;
};
extern "C" s32 func_00343BE0(S *);
extern "C" float func_00344698(S *);
extern "C" float func_003446A0(S *);
extern "C" s32 func_00350F30(S *);
extern "C" s32 func_0036BEE0(S *, s32);
extern "C" s32 func_0036BF28(S *, s32);
extern "C" s32 func_0036BF68(S *, float);

extern "C" void func_0040CA58(S *self, s32 *a1, s32 *a2, s32 *a3, s32 *a4) {
    St *st = &self->owner->state;
    s32 s4 = func_00350F30(self);
    s32 s6 = st->count;
    s32 c = self->f624;
    func_00343BE0(self);
    float f20 = func_00344698(self);
    float f21 = func_003446A0(self);
    float *fp = (float *)((char *)self + 0x14);
    float x = fp[10] < fp[9] ? fp[10] : fp[9];
    s32 s3 = func_0036BF68(self, x);
    if (a4) *a4 = s3;
    s32 s2;
    if (c == 0 || c == s6) s2 = 99999;
    else s2 = func_0036BEE0(self, c);
    s32 v1 = (s32)0xFFFE7961;
    if (c >= 2) v1 = func_0036BF28(self, c);
    if (c == 1) {
        if (s2 - 1000 < s4)
            if (f20 > 0.2f) *a1 = c;
    } else if (s2 - 300 < s4 && f20 > 0.7f) {
        *a1 = 1;
    }
    if (c == s3) {
        if (s4 < v1 - 1000) *a2 = 1;
    } else if (f20 > 0) {
        if (s4 < v1) *a2 = 1;
    } else if (f21 == 0) {
        if (s4 < v1 + 500) *a2 = 1;
    } else {
        if (s4 < v1 + 1000) *a2 = 1;
        if (s3 > 0 && s3 < c) *a3 = 1;
    }
}
