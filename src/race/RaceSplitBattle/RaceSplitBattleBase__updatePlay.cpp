/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef short s16;

struct Ent { char pad[0x114]; s32 f114; };
struct VEntry { s16 delta; s16 pad; Ent *(*fn)(void *, s32); };
struct Org { char pad[0xF4]; };

struct Self {
    char pad0[0x64];
    char *tbl;
    char pad68[4];
    char *org;
    char pad70[0xCC8 - 0x70];
    u32 mode;
};

extern "C" void RaceBasic__updatePlay(void *, float);
extern "C" void RaceSplitBattleBase__update_display(void *, float);
extern "C" void func_003B76F0(void *, s32, s32, s32);

static inline Ent *getEnt(Self *s, s32 i) {
    VEntry *e = (VEntry *)(s->tbl + 0x240);
    return e->fn((char *)s + e->delta, i);
}

extern "C" void RaceSplitBattleBase__updatePlay(Self *self, float f) {
    RaceBasic__updatePlay(self, f);
    RaceSplitBattleBase__update_display(self, f);
    if (self->mode < 2) {
        if (getEnt(self, 0x100)->f114 != 0)
            func_003B76F0(self->org + 0xF4, 0x1A, 0, 2);
        if (getEnt(self, 0x101)->f114 != 0)
            return func_003B76F0(self->org + 0xF4, 0x1A, 1, 2);
    } else if (self->mode - 2 < 2) {
        if (getEnt(self, 0x100)->f114 != 0 || getEnt(self, 0x101)->f114 != 0)
            func_003B76F0(self->org + 0xF4, 1, 0, 0);
    }
}
