typedef int s32;
typedef unsigned long long u64;
extern char D_006AE560[];
extern char D_006AE578[];
extern "C" void func_00493628(s32, s32, s32, s32, s32, s32, s32, char *, s32, s32);
extern "C" void func_00493AB0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, u64 val, s32 fmt) {
    char buf[32];
    s32 len = 0;
    char *digits;
    if (fmt == 'x') digits = D_006AE560;
    else digits = D_006AE578;
    s32 started = 0;
    for (s32 sh = 60; sh >= 0; sh -= 4) {
        s32 d = (s32)((val >> sh) & 0xF);
        if (started || d != 0) {
            started = 1;
            buf[len++] = digits[d];
        }
    }
    func_00493628(a0, a1, a2, a3, a4, a5, 0, buf, len, fmt == 'X' ? 17 : 16);
}
