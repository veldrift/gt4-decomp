typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
struct B4 { u8 b[4]; };
struct E { char p[0x14]; s32 f14; char p18[0x2C]; };
struct Obj { char p[0x84]; E *f84; char p88[0x5C]; void (*fE4)(s32, s32, s32); s32 fE8; };
extern "C" s32 func_00526988(Obj *o, u16 idx, B4 *pb) {
    B4 b = *pb;
    s32 arg = o->fE8;
    o->f84[idx].f14 = b.b[2];
    o->fE4(idx, b.b[2], arg);
    return 0;
}
