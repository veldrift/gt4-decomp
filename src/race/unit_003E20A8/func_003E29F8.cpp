/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct Res {
    char pad0[0x14];
    f32 f14, f18, f1C, f20, f24, f28;
    u16 f2C;
    s16 f2E;
};
struct Info { s32 x; s32 f4; };
struct Obj {
    char pad0[0x10];
    f32 pos[3];
    char pad1[0x34 - 0x1C];
    f32 f34, f38, f3C, f40;
    char pad2[2];
    u8 b46, b47;
    s32 f48;
};

extern Info *D_006D6060;
extern "C" s32 CourseData__getRunway(s32 arg);
extern "C" s32 GT4Course__RunwayData__search(s32 rw, Res *out, f32 *pos);

extern "C" u32 func_003E29F8(Obj *self) {
    Res r;
    u16 *pf = &r.f2C;
    *pf = -1;
    r.f2E = -1;
    s32 rw = CourseData__getRunway(D_006D6060->f4);
    GT4Course__RunwayData__search(rw, &r, self->pos);
    u32 lo = *pf;
    f32 a = minf(maxf(r.f14 * 255.0f, 0.0f), 255.0f);
    f32 b = minf(maxf(r.f18 * 255.0f, 0.0f), 255.0f);
    self->f34 = r.f1C;
    self->f38 = r.f20;
    self->f3C = r.f24;
    self->f40 = r.f28;
    s32 bi = (s32)b;
    s32 ai = (s32)a;
    self->b46 = ai;
    self->b47 = bi;
    self->f48 = (r.f2E << 16) | lo;
    GT4Course__RunwayData__search(rw, &r, self->pos);
    return (u32)~self->f48 >> 31;
}
