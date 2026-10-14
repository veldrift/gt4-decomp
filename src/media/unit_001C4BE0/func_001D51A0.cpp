/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Inner { char pad[0x16]; unsigned short f16; char pad2[0x7C-0x18]; s32 **f7C; };
struct Self {
    Inner *p0; Inner *p4; Inner *p8; s32 fC; s32 f10; void *f14; void *f18; s32 f1C;
    char pad[0x20-0x20]; char m20[0xC]; char m2C[0x14]; s32 f40; s32 f44; s32 f48;
    char pad2[0x1A8-0x4C]; s32 f1A8; char pad3[4]; s32 f1B0;
};
extern "C" void GT4_Motion__MotionSetPlayer__set(void *, int, int);
extern "C" void func_00454698(s32 *, s32 **, int, int);
extern "C" void func_001D51A0(Self *s) {
    s32 **a;
    a = s->p0->f7C; func_00454698(*a, a, 0, 0);
    a = s->p4->f7C; func_00454698(*a, a, 0, 0);
    a = s->p8->f7C; func_00454698(*a, a, 0, 0);
    GT4_Motion__MotionSetPlayer__set(s->m20, 0, s->fC);
    GT4_Motion__MotionSetPlayer__set(s->m2C, 0, s->f10);
    s->f14 = 0;
    s->f18 = 0;
    s->f1C = s->p0->f16;
    s->f1B0 = 1;
    s->f44 = 0;
    s->f48 = 0;
    s->f1A8 = 0;
    s->f40 = 0;
}
