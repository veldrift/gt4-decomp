/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
typedef unsigned char u8;
typedef long long s64;

#define MASK (~(0xFFLL << 48))

struct Inner { char pad[0x18]; void *unk18; };
struct Obj {
    char pad0[8];
    f32 m8;
    f32 mC;
    char pad1[0x184 - 0x10];
    f32 m184;
    f32 m188;
    Inner *m18C;
    char pad2[0x260 - 0x190];
    union {
        s64 m260;
        struct { char p[7]; u8 m267; } hb;
    };
    u8 m268;
    u8 m269;
    u8 m26A;
    u8 m26B;
    char pad4[0x278 - 0x26C];
    f32 m278;
};

extern "C" f32 func_00344798(void *, f32);
extern "C" f32 func_003447F8(void *, f32);
extern "C" f32 func_00344828(void *, f32);
extern "C" f32 func_003448B8(void *, f32);
extern "C" void func_004A7844(f32, f32, f32);
extern "C" void func_004A7988(f32);
extern "C" void func_004A79B0(float);

extern "C" void func_0037B918(Obj *o) {
    f32 v = o->m184;
    void *t = o->m18C->unk18;
    func_004A7988(9.0f);
    func_004A7844(0.0f, -0x1.333332p+1f, -6.5f);
    func_004A79B0(-func_003448B8(t, 0.0f) * 0x1.ca5dcp+5f);
    s32 f = 0;
    if (*(u8 *)((char *)o + 0x26B) != 0 || *(u8 *)((char *)o + 0x269) != 0)
        f = 1;
    if (f)
        func_004A79B0(180.0f);
    f32 a = -func_00344798(t, 0.0f);
    f32 b = -func_003447F8(t, 0.0f);
    func_004A7844(a, b, -func_00344828(t, 0.0f));
    o->m260 = o->m260 & MASK;
    o->m278 = 0.0f;
    o->m8 = 100.0f;
    if (o->hb.m267 != 0) {
        o->m260 = (o->m260 & MASK) | (0x8000LL << 33);
        v = o->m188;
    }
    o->mC = v;
}
