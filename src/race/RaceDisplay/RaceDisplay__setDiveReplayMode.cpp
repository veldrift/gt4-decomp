/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned int u32;

struct VEnt { s16 delta; s16 idx; void (*fn)(void *, s32); };
struct Self {
    char *vtbl;
    char pad4[0x1C];
    s32 mode;
    char pad24[0x1C];
    u32 w40;
    u8 pad44[0];
};

static inline void vcall(Self *o, s32 a, s32 b) {
    VEnt *e = (VEnt *)(o->vtbl + 0x108);
    e->fn((char *)o + e->delta, a);
}

extern "C" void RaceDisplay__setDiveReplayMode(Self *self, s32 v) {
    s32 k = self->mode;
    if (k >= 0) {
        if (k >= 2) {
            if (k < 5) {
                if (((u8 *)self)[0x43] != v) {
                    self->w40 = (self->w40 & 0xFFFFFF) | (v << 24);
                    vcall(self, self->mode, k);
                }
            }
        }
    }
}
