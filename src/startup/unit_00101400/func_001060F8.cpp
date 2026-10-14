typedef int s32;
typedef unsigned int u32;
struct El { char p[0x30]; s32 u30; char q[8]; };
struct Blk { El e[2]; s32 idx; };
struct O {
    s32 u0; u32 u4; s32 u8; char p[8]; float u14; char q[0x30 - 0x18]; s32 u30; char r[8];
    Blk b;
};
extern "C" s32 func_001060A0(s32, s32, s32);
extern "C" void func_004A0808(s32, s32, s32);
extern "C" void func_004A0910(s32);
extern "C" void func_004A22C0(s32);
extern "C" void func_001060F8(O *o, s32 a, u32 b, s32 c) {
    if (o->u0 != a || o->u4 != b || o->u8 != c) {
        o->u0 = a;
        o->u4 = b;
        o->u8 = c;
        o->u30 = func_001060A0(a, b, c);
        func_004A22C0(1);
        func_004A0808(a, b, c);
        func_004A0910(0);
        Blk *k = &o->b;
        float f = 1.0f;
        El *e = k->e;
        El *t = k->e + k->idx;
        t->u30 = 0;
        e += 1 - k->idx;
        e->u30 = 0;
        switch (o->u4) {
        case 2: f = 1.098f; break;
        case 3: f = 0.914f; break;
        case 0x50: f = 1.0f; break;
        case 0x51: f = 1.0f; break;
        case 0x52: f = 1.0f; break;
        default: f = 1.0f; break;
        }
        o->u14 = 1.0f / f;
    }
}
