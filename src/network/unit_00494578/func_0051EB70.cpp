typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;
struct O {
    s32 f0; char p4[4]; s32 f8; char p0c[0x4C]; s32 f58; s32 f5C; char p60[0x24];
    s32 f84; s32 (*f88)(s32, s32, s32, s32, s32);
};
extern "C" s32 func_00538F98(u8 *, u16 *);
extern "C" s32 func_0051DCF8(unsigned int) throw();
extern "C" s32 func_0051EB70(O *o, s32 a1, u8 *p, unsigned int n) {
    u16 v;
    unsigned minimum = 1;
    int r = 0xCB20;
    if (minimum >= n) return r;
    func_00538F98(p, &v);
    o->f8 = 8;
    o->f5C = v;
    if (o->f88 != 0) {
        s32 s0 = o->f0;
        o->f88(o->f84, 1, o->f58, v, 0);
        if (func_0051DCF8(s0) == 0) return 0xCB23;
    }
    r = 0;
    return r;
}
