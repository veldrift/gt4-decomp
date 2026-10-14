/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

struct Win { char pad[8]; f32 f8; f32 fC; };
struct Inner { char pad[0xD]; u8 fD; s8 fE; };
struct Gl {
    char pad[0x14];
    Inner *f14;
    char pad2[0x28 - 0x18];
    f32 f28;
    char pad3[0x4C - 0x2C];
    s32 f4C;
    char pad4[0x64 - 0x50];
    s32 f64;
};

extern "C" Gl *PDISTD__global_font_manager;
extern "C" void func_00490700(Gl *, s32, s32, s32, s32);

extern "C" void func_0044E1E0(Win *w, s32 flags) {
    s32 s1 = 0;
    s32 t0 = 0;
    s32 a2 = (s32)w->fC;
    s32 a3 = 0x280;
    switch (flags & 3) {
    case 0:
        t0 = (s32)w->f8;
        break;
    case 2:
        a3 = (s32)w->f8;
        s1 = 2;
        break;
    case 3:
        s1 = 1;
        t0 = (s32)w->f8 - 0x140;
        break;
    }
    switch (flags & 0xC) {
    case 4:
        break;
    case 8:
        s1 |= 8;
        break;
    case 0: {
        Gl *g = PDISTD__global_font_manager;
        f32 k = g->f28;
        s32 v = g->f14->fE;
        a2 -= (s32)((f32)v * k);
        break;
    }
    case 12: {
        Gl *g = PDISTD__global_font_manager;
        f32 k = g->f28;
        s32 v = g->f14->fD;
        v >>= 1;
        a2 -= (s32)((f32)v * k);
        break;
    }
    }
    func_00490700(PDISTD__global_font_manager, t0, a2, a3, 0x1C0);
    Gl *gg = PDISTD__global_font_manager;
    gg->f64 = s1;
    gg->f4C = 1;
}
