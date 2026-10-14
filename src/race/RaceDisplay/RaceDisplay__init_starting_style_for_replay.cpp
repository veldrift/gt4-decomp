typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef float f32;

struct VEntryI { s16 delta; s16 index; void (*fn)(void *self, s32 a, f32 b); };
struct VEntryF { s16 delta; s16 index; void (*fn)(void *self, f32, f32, f32, f32); };

struct Msg {
    u32 w0;
    char pad4[0x14];
    f32 f18;
    f32 f1C;
};

struct Self {
    char *vtbl;
    char pad4[0x18];
    s32 f1C;
    char pad20[0x54 - 0x20];
    s32 f54;
    char pad58[0xBC - 0x58];
    char bc[1];
    char padBD[0x11B0 - 0xBD];
    Msg m11B0;
    char pad11D0[0x17BC - 0x11B0 - sizeof(Msg)];
    char m17BC[1];
};

extern char D_006A0508[];

extern "C" void RaceMessageDisplay__show(void *, f32, f32);
extern "C" void RaceEventDisplay__addEvent(void *, const char *, f32, f32, f32, f32);
extern "C" void AutomaticFader__oneshot(void *, f32, f32, f32, f32);
extern "C" void AutomaticFader__reset(void *);

extern "C" void RaceDisplay__init_starting_style_for_replay(Self *self) {
    Msg *m1 = &self->m11B0;
    char *bc = self->bc;
    m1->f18 = 1.0f;
    m1->f1C = 1.0f;
    RaceMessageDisplay__show(m1, 6.0f, 0x1.999998p-4f);
    m1->w0 = (m1->w0 & ~0xFF) | 1;
    RaceEventDisplay__addEvent(self->m17BC, D_006A0508, 6.0f, 0.0f, 0.0f, 0.0f);
    AutomaticFader__reset(bc);
    AutomaticFader__oneshot(bc, 0x1.866666p+2f, -1.0f, 0.5f, 0.0f);
    if (self->f54 != 0) {
        VEntryI *e = (VEntryI *)(self->vtbl + 0xA0);
        e->fn((char *)self + e->delta, self->f54, 4.5f);
        self->f54 = 0;
    }
    if ((u32)(self->f1C - 8) >= 2) {
        VEntryF *e = (VEntryF *)(self->vtbl + 0x168);
        e->fn((char *)self + e->delta, 0x1.999998p-4f, 6.0f, 1.0f, 1.0f);
    }
}
