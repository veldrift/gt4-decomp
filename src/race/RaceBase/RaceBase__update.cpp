typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct VEntryF {
    s16 delta;
    s16 index;
    void (*fn)(void *, float);
};

struct VEntryI {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Self {
    char pad0[0x64];
    char *vt;
    char pad68[4];
    char *f6C;
    char pad70[0xCD8 - 0x70];
    s32 fCD8;
    char padCDC[0xD30 - 0xCDC];
    float fD30;
    float fD34;
    char padD38[0xD50 - 0xD38];
    s32 fD50;
};

extern "C" s32 RaceEventQueue__get(void *t, s32 id, s32 *value, s32 remove);

static inline void vcall(Self *o, int off) {
    VEntry *e = (VEntry *)(o->vt + off);
    e->fn((char *)o + e->delta);
}

extern "C" void RaceBase__update(Self *self) {
    char *t = self->f6C;
    VEntryI *e = (VEntryI *)(self->vt + 0x248);
    if (e->fn((char *)self + e->delta) != 0) {
        s32 v;
        self->fD30 = self->fD30 + self->fD34;
        v = self->fD50;
        if (v > 0) {
            v--;
            self->fD50 = v;
            if (v == 0) {
                vcall(self, 0x160);
            }
        }
        if (self->fCD8 == 0) {
            VEntryF *e2 = (VEntryF *)(self->vt + 0x250);
            e2->fn((char *)self + e2->delta, 0x1.111110p-6f);
        } else {
            vcall(self, 0x268);
        }
        vcall(self, 0x270);
    }
    if (RaceEventQueue__get(t + 0xF4, 0xA, 0, 1) != 0) {
        vcall(self, 0x280);
    }
}
