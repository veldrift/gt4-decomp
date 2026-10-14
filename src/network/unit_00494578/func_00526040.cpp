typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
struct E { s32 f0; char p[0x40]; };
struct Obj { char p[0x84]; E *f84; char p88[0x14]; u16 f9C; };
extern "C" void func_00526040(Obj *o, s32 *out1, u16 *out2) {
    s32 t = 0;
    *out1 = 0;
    *out2 = 0xFFFE;
    s32 i = o->f9C;
    while (1) {
        s32 prev = i;
        i--;
        if (prev <= 0) break;
        t = o->f84[i].f0;
        if ((u32)(t - 5) < 3) break;
    }
    if (i >= 0) {
        *out1 = t;
        *out2 = i;
    }
}
