/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef float f32;

static inline f32 min_s(f32 a, f32 b) {
    f32 r;
    __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

static inline f32 max_s(f32 a, f32 b) {
    f32 r;
    __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

struct VEntry { s16 delta; s16 index; void (*fn)(void *self, f32, f32, f32, f32); };

struct Info { char pad[0xB8]; volatile s32 val; };

struct Msg {
    u32 w0;
    char pad4[0x14];
    f32 f18;
    f32 f1C;
};

struct Self {
    char *vtbl;
    Info *info;
    char pad8[0xBC - 8];
    char bc[1];
    char padBD[0x11B0 - 0xBD];
    Msg m11B0;
    char pad11D0[0x17BC - 0x11B0 - sizeof(Msg)];
    char m17BC[1];
    char pad17BD[0x252C - 0x17BD];
    Msg m252C;
};

extern char D_006A0508[];

extern "C" void RaceMessageDisplay__show(void *, f32, f32);
extern "C" int RaceEventDisplay__addEvent(void *, const char *, f32, f32, f32, f32);
extern "C" void AutomaticFader__oneshot(void *, f32, f32, f32, f32);
extern "C" void AutomaticFader__reset(void *);

static inline float to_float(int x) { return (float)x; }
static inline void call_virtual(Self *self, float a, float b, float c, float d) {
    VEntry *e = (VEntry *)(self->vtbl + 0x158);
    e->fn((char *)self + e->delta,a,b,c,d);
}

extern "C" void RaceDisplay__init_starting_style_short_format(Self *self) {
    f32 c;
    f32 alpha = 1.0f;
    Msg *m1 = &self->m11B0;
    Msg *m2 = &self->m252C;
    s32 iv = self->info->val;
    f32 v = to_float(iv);
    m2->f18 = 0x1.333332p-2f;
    m2->f1C = alpha;
    RaceMessageDisplay__show(m2, 4.0f, alpha);
    c = v - 5.0f;
    call_virtual(self, 0.5f, min_s(max_s(v - 3.5f, 2.0f), 5.0f), 0.5f, alpha);
    m1->f1C = alpha;
    m1->f18 = 0.5f;
    alpha = 0.0f;
    c = min_s(max_s(c, alpha), 5.0f);
    RaceMessageDisplay__show(m1, c, 0.5f);
    s32 flag = 1;
    if (!(alpha < c)) flag = 0;
    m1->w0 = (m1->w0 & ~0xFF) | flag;
    RaceEventDisplay__addEvent(self->m17BC, D_006A0508, 5.0f, alpha, alpha, alpha);
    AutomaticFader__reset(self->bc);
    AutomaticFader__oneshot(self->bc, v - 4.5f, -1.0f, 0.5f, alpha);
}
