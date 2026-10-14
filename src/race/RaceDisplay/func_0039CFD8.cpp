typedef int s32;
typedef unsigned char u8;
typedef float f32;

struct Item { int dummy; };
struct List { char pad[8]; char **items; };
struct Info { char pad[0x60]; List *list; };

struct Gauge {
    f32 f0;
    char pad4[0x14];
    s32 i18;
};

struct Self {
    char pad0[4];
    Info *info;
    char pad8[0x20 - 8];
    s32 f20;
    char pad24[0x2E - 0x24];
    signed char id2E;
    char pad2F[0x43 - 0x2F];
    u8 b43;
    char pad44[0x4C - 0x44];
    s32 f4C;
    char pad50[0xBC - 0x50];
    f32 bc;
    char padC0[0x23DC - 0xC0];
    char m23DC[0x2F2C - 0x23DC];
    char m2F2C[0x3F14 - 0x2F2C];
    Gauge g3F14;
};

extern "C" void func_0039F110(Self *, char *, s32, char *);
extern "C" void RaceMessageDisplay__setMessage(void *, const char *, f32, f32);
extern "C" void RaceMessageDisplay__clear(void *);
extern "C" void RaceMessageDisplay__show(void *, f32, f32);
extern "C" void RaceEventDisplay__clear(void *, f32);
extern "C" void RaceEventDisplay__addEvent(void *, const char *, f32, f32, f32, f32);

static inline int ready(Gauge *g) {
    int r = 0;
    if (g->i18 == 2 && g->f0 <= 0.0f) r = 1;
    return r;
}

extern "C" void func_0039CFD8(Self *self) {
    char buf[0x80];
    if (self->f20 != 0 && self->b43 == 0 && !(self->bc < 1.0f)) {
        if ((ready(&self->g3F14) ^ 1) == 0) {
            func_0039F110(self, buf, 0x80, self->info->list->items[self->id2E]);
            char *m = self->m23DC;
            RaceMessageDisplay__clear(m);
            RaceMessageDisplay__setMessage(m, buf, 0.0f, 0.0f);
            ((f32 *)m)[6] = 0.25f;
            ((f32 *)m)[7] = 0.25f;
            RaceMessageDisplay__show(m, 5.0f, 0.0f);
            if (self->f4C == 0) {
                char *m2 = self->m2F2C;
                RaceEventDisplay__clear(m2, 0x1.999998p-4f);
                RaceEventDisplay__addEvent(m2, buf, 5.0f, 0x1.999998p-4f, 0x1.999998p-3f, 0x1.999998p-3f);
            }
        }
    }
}
