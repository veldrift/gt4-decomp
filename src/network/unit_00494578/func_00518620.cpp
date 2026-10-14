typedef int s32;
struct X { unsigned char b0; char p1[3]; unsigned char b4; char p5[0x27]; char f2C[4]; };
extern "C" X *func_00515EE8(s32);
extern "C" s32 func_005385B0(void *, s32 *);
extern "C" s32 func_00518620(s32 *out, s32 a1) {
    s32 local = 0;
    if (out == 0) return 0x17;
    *out = 0;
    X *p = func_00515EE8(a1);
    if (p == 0) return 0x17;
    if (p->b0 != 2) return 9;
    if (p->b4 != 0) return 9;
    if (p->f2C == 0) return 9;
    s32 r = func_005385B0(p->f2C, &local);
    if (r == 0) {
        *out = local;
        return r;
    }
    return 9;
}
