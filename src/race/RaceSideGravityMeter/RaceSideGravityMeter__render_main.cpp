/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef float f32;

static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct Meter {
    char pad0;
    u8 b1;
    u8 b2;
    char pad3;
    s16 h4;
    s16 h6;
    s16 h8;
    s16 hA;
    f32 fC;
    void *p10;
    void *p14;
    s32 i18;
    f32 f1C;
    f32 f20;
    f32 f24;
    void *p28;
};

extern "C" void func_003AB3B8(Meter *);
extern "C" void func_003AEF18(void *, f32, f32, unsigned, unsigned);
extern "C" void func_003AF108(f32, f32, f32, f32, s32, s32, s32);
extern "C" f32 func_003AFD18(int, f32, f32);
extern "C" s32 func_003AFEC8(s32, f32);
extern "C" void func_004AA168(s32);

extern "C" void RaceSideGravityMeter__render_main(Meter *self) {
    f32 x, y, c, h;
    if (self->p10 == 0)
        func_003AB3B8(self);
    x = func_003AFD18(self->b1, (f32)self->h4, (f32)self->h8);
    y = func_003AFD18(self->b2, (f32)self->h6, (f32)self->hA);
    func_004AA168(func_003AFEC8(0x80FFFFFF, self->fC));
    func_003AF108(x, y, (f32)self->h8, (f32)self->hA, self->i18, 0, 0);
    func_004AA168(func_003AFEC8((s32)self->p28, self->fC));
    h = (f32)self->h8 * 0.5f;
    c = self->f20;
    func_003AEF18(self->p10, x + h + h * self->f24 * (minf(maxf(self->f1C, -c), c) / c), y + 8.0f, 2, 2);
}
