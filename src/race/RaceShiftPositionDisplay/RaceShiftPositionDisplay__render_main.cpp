/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef short s16;
typedef float f32;

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *);
};

struct Vt {
    char pad[0x50];
};

struct Self {
    char pad0[1];
    u8 b1;
    u8 b2;
    char pad3;
    s16 x4;
    s16 x6;
    s16 w;
    s16 h;
    f32 fC;
    void *tex;
    Vt *vt;
    char pad18[0x20];
    f32 f38;
    char pad3c[0x18];
    u8 b54;
    char pad55;
    u8 b56;
    u8 b57;
};

struct Font { s32 m0; s32 m4; };
extern Font D_00623838;
extern char D_006A1408[];
extern char D_006A1420[];

extern "C" void func_003AF4F8(void *t, f32 x0, f32 y0, f32 x1, f32 y1, s32 filter, s32 blend);
extern "C" s32 func_003AFD78(s32 x, s32 w, s32 fl);
extern "C" s32 RaceDisplayUtil__getScaledColor(u32 c, f32 a, f32 b);
extern "C" s32 func_003AFEC8(u32 c, f32 a);
extern "C" void func_0044D920(void *p, const char *name);
extern "C" void func_0044D988(void *p);
extern "C" void GT3OLDFONT__GT3OldFontManagerClass__position(void *p, s32 x, s32 y, s32 z);
extern "C" void func_0044DE80(void *p, s32 v);
extern "C" void func_0044E088(void *p, const char *fmt, ...);
extern "C" void func_004AA168(s32 v);

extern "C" void RaceShiftPositionDisplay__render_main(Self *a) {
    s32 s3, s2;
    s16 s0, s1;
    s32 c;
    f32 fa, fb;

    if (a->tex == 0) {
        VEntry *e = (VEntry *)((char *)a->vt + 0x50);
        e->fn((char *)a + e->delta);
    }
    s3 = func_003AFD78(a->x4, a->w, a->b1);
    s2 = func_003AFD78(a->x6, a->h, a->b2);
    s0 = a->w;
    s1 = a->h;
    func_004AA168(func_003AFEC8(0x80FFFFFF, a->fC));
    s32 e1 = s2 + s1;
    s32 e0 = s3 + s0;

    func_003AF4F8(a->tex, (f32)s3, (f32)s2, (f32)e0, (f32)e1, 0, 0);
    func_0044D920(&D_00623838, D_006A1420);
    D_00623838.m4 = 0xF;
    GT3OLDFONT__GT3OldFontManagerClass__position(&D_00623838, s3 + a->w / 2, e1 - 12, 0);
    fa = a->f38 * 1.5f;
    fb = a->fC;
    if (a->b57 == 0) {
        fb = fb * 0.5f;
    }
    func_0044DE80(&D_00623838, RaceDisplayUtil__getScaledColor(0x80E3B896, fa, fb));
    c = 0x52;
    if (a->b54 != 0) {
        c = 0x43;
        if (a->b56 == 0) {
            c = a->b54 + 0x30;
        }
    }
    func_0044E088(&D_00623838, D_006A1408, c);
    func_0044D988(&D_00623838);
    D_00623838.m4 = 0;
}
