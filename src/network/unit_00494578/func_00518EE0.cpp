typedef int s32;
typedef unsigned int u32;
struct Msg { volatile s32 a; volatile s32 b; volatile u32 c; volatile s32 d; };
struct G1 { char pad[0x5C]; s32 unk5C; };
struct G2 { char pad[0x128]; void (*unk128)(Msg *); s32 unk12C; };
extern G1 *D_0064B47C;
extern G2 *D_0064B4B4;
extern "C" void func_00518FA8(s32 *);
extern "C" s32 *func_0051B8A8(s32, u32);
extern "C" s32 *func_0051B968(s32, u32);
extern "C" void func_0051BAE0(s32, u32);
extern "C" s32 func_00535C88(s32, u32);
extern "C" void func_00518EE0(s32 arg0, u32 arg1) {
    s32 *p;
    if (arg1 < 0x40 && arg0 != 0) {
        p = func_0051B8A8(arg0, arg1);
        if (p == 0) p = func_0051B968(arg0, arg1);
        if (func_00535C88(arg0, arg1) != 0) {
            *p = D_0064B47C->unk5C;
            func_00518FA8(p);
            G2 *g = D_0064B4B4;
            if (g->unk128 != 0) {
                Msg m;
                s32 d = g->unk12C;
                m.a = 0;
                m.b = arg0;
                m.c = arg1;
                m.d = d;
                g->unk128(&m);
            }
            func_0051BAE0(arg0, arg1);
        }
    }
}
