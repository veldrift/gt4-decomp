/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct P6C { char pad[0x80]; struct P80 *u80; };
struct P80 { s32 u0; s32 u4; };
struct G {
    char pad0[0x6C];
    P6C *u6C;
    char pad70[0xCF5C - 0x70];
    f32 fCF5C;
    char padCF60[0xE330 - 0xCF60];
    s32 uE330;
};
struct Obj {
    G *g;
    char pad4[8];
    s32 uC, u10;
    char pad14[0x118 - 0x14];
    s32 u118;
    char pad11C[0x124 - 0x11C];
    s32 u124;
};

extern s32 D_006201A8;
extern s32 D_006201AC;

extern "C" void func_003323B0(void *, s32);
extern "C" void func_003336B8(Obj *);
extern "C" void func_00333C40(Obj *);
extern "C" void func_00334B28(Obj *);
extern "C" void func_00397438(s32);

extern "C" void func_00333808(Obj *arg0, s32 arg1) {
    if (arg0->g != 0) {
        if (D_006201A8 != 0) {
            arg0->uC = D_006201AC;
            arg0->u10 = D_006201AC;
        }
        if (arg1 != 0) {
            func_00333C40(arg0);
        } else {
            func_003336B8(arg0);
        }
        if (arg1 == 0) {
            arg0->g->fCF5C = 0x1.111110p-6f / (f32)arg0->u118;
        }
        arg0->g->uE330 = 0x200;
        if (arg0->u124 == 0) {
            P80 *p = arg0->g->u6C->u80;
            func_00397438(p->u4);
        }
        func_003323B0((char *)arg0 + 0x44, arg0->u118);
        func_00334B28(arg0);
    }
}
