/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef float f32;

static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct Font { char pad[0x18]; f32 f18; };
struct Disp {
    char pad0;
    u8 b1;
    u8 b2;
    char pad3;
    s16 h4;
    s16 h6;
    s16 h8;
    s16 hA;
    f32 fC;
    char pad10[8];
    s32 i18;
    char pad1C[0x74 - 0x1C];
    f32 f74;
    char item[4];
};

extern "C" Font D_00623838;
extern "C" char D_006A16B8[];

extern "C" void func_0044D920(Font *, char *);
extern "C" void func_0044D988(Font *);
extern "C" void func_0044DBC0(Font *, f32, f32);
extern "C" void func_0044DDF8(Font *, f32, f32, f32);
extern "C" void func_0044DE80(Font *, s32);
extern "C" f32 func_0044DFC8(Font *, void *);
extern "C" void func_0044E030(Font *, void *);
extern "C" s32 func_0044E3F8(Font *);
extern "C" f32 func_003AFD18(int, f32, f32);
extern "C" s32 func_003AFEC8(s32, f32);

extern "C" void RaceRichCountDisplay__render_main(Disp *self) {
    Font *font = &D_00623838;
    f32 w, x, sc, y, h;
    func_0044D920(font, D_006A16B8);
    func_0044DE80(font, func_003AFEC8(self->i18, self->fC));
    if (self->f74 == 0.0f) {
        self->f74 = func_0044DFC8(font, self->item) / font->f18;
    }
    w = self->f74;
    sc = 1.0f;
    x = w;
    if (self->h8 > 0) {
        sc = minf(sc, (f32)self->h8 / x);
        x *= sc;
    }
    y = (f32)func_0044E3F8(font);
    h = func_003AFD18(self->b1, (f32)self->h4, x);
    func_0044DDF8(font, h, func_003AFD18(self->b2, (f32)self->h6, y) + y, 0.0f);
    func_0044DBC0(font, sc, 1.0f);
    func_0044E030(font, self->item);
    func_0044DBC0(font, 1.0f, 1.0f);
    func_0044D988(font);
}
