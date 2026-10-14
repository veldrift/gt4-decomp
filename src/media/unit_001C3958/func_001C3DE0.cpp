/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct B { char b[0x1C]; };
struct E { s32 a; s32 b; char pad2[0x4C - 8]; };
struct Obj {
    char pad0[0x10]; B bs[1];
};
extern "C" s32 func_001C3F50(void *, s32, s32);
extern "C" s32 func_001C2388(void *, void *, s32, s32);
extern "C" s32 func_001C3DE0(char *self, s32 y, s32 x) {
top:
    {
        s32 r = func_001C3F50(self, y, x);
        if (r == 0) return r;
        if (y == 0 || x == 0) {
            *(s32 *)(self + 0x2C8) = y;
            *(s32 *)(self + 0x2C4) = x;
            return 1;
        }
        E *eo = (E *)(self + 0x12C) + y;
        x--;
        y--;
        B *s4 = (B *)(self + 0x10) + x;
        E *s3 = (E *)(self + 0x10C) + y;
        s32 s1 = eo->a * 2;
        s32 s0 = eo->b * 2;
        s32 s6 = s1 + 1;
        if (func_001C2388(s3, s4, s1, s0)) goto top;
        if (func_001C2388(s3, s4, s6, s0)) goto top;
        s0 = s0 + 1;
        if (func_001C2388(s3, s4, s1, s0)) goto top;
        r = func_001C2388(s3, s4, s6, s0);
        if (r) goto top;
        return r;
    }
}
