/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef float f32;
typedef unsigned int u32;

struct G { s32 m0; s32 m4; };
struct S {
    char pad0[1];
    u8 m1;
    char pad2[2];
    s16 m4;
    s16 m6;
    char pad8[4];
    f32 mC;
    char pad10[8];
    char m18[0x10];
    f32 m28;
    s32 m2C;
    u16 m30;
    s16 m32;
    u16 m34;
    u16 m36;
};

extern G D_00623838;
extern char D_006A1430[];
extern char D_006A1438[];

extern "C" f32 func_003AFD18(s32, f32, f32);
extern "C" s32 func_003AFEC8(s32, f32);
extern "C" void func_0044D920(void *, void *);
extern "C" void func_0044D988(void *);
extern "C" f32 func_0044DC30(void *);
extern "C" void func_0044DDF8(void *, f32, f32, f32);
extern "C" void func_0044DE80(void *, s32);
extern "C" f32 func_0044DFC8(void *, const char *);
extern "C" void func_0044E088(void *, const char *, ...);

static inline bool less(s32 a, s32 b) { return a < b; }

extern "C" void RaceDigitalSpeedmeter__render_main(S *o) {
    G *g = &D_00623838;
    f32 zero = 0.0f;
    func_0044D920(g, o->m18 - 0 );
    g->m4 = 2;
    if (o->m28 == zero) {
        f32 a = func_0044DC30(g);
        f32 b = func_0044DFC8(g, D_006A1430) / a;
        o->m28 = func_003AFD18(o->m1, (f32)o->m4, b) + b;
    }
    {
        s32 c = o->m30 + 1;
        o->m30 = c;
        if (c & 1) {
            s32 v = o->m32 < 0 ? -o->m32 : o->m32;
            u16 old = o->m34;
            o->m36 = old;
            o->m34 = v;
        }
    }
    {
        s16 s0 = (s16)o->m36 >? (s16)o->m34;
        func_0044DE80(g, func_003AFEC8(o->m2C, o->mC));
        func_0044DDF8(g, o->m28, (f32)o->m6, zero);
        func_0044E088(g, D_006A1438, s0);
    }
    g->m4 = 0;
    func_0044D988(g);
}
