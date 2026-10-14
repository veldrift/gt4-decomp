/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
typedef short s16;

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *); };
struct Ev { s32 idx; char *vt; s32 f8; s32 fC; };
struct Car { char pad[0x11E8]; s32 f11E8; s32 f11EC; };
struct Arr { char pad[8]; Car **cars; };
struct Self {
    char pad0[0xC0];
    s32 fC0;
    char padC4[0xE8 - 0xC4];
    s32 fE8;
    char padEC[0xF4 - 0xEC];
    char qF4[8];
    char bytes[0x800 + 0x100];
};
struct SelfW { char pad[0x60]; Arr *f60; };

extern char RaceDisplayTimeDiffEvent__vtable[];
extern char RaceDisplayLapDiffEvent__vtable[];

extern "C" void *RaceDisplayDiffEvent__structor_0(Ev *);
extern "C" s32 func_003A3248(Ev *, void *, s32);
extern "C" s32 func_003A3620(Ev *);
extern "C" void RaceEntryBase__sortByRank(void *);
extern "C" s32 RaceEventQueue__get(void *, s32, void *, s32);

struct Events { char pad[0x800]; u8 counts[256]; };
static inline s32 count(Ev *pe, Ev *ev, Events *base) {
    VEntry *e = (VEntry *)(ev->vt + 8);
    return base->counts[e->fn((char *)pe + e->delta)];
}

static inline int getEvent(Ev *ev, char *self, int key) { ev->idx = -1; return func_003A3248(ev,self,key); }

static inline void setTime(Car *c, int t) { c->f11E8=t; c->f11EC=0; }

extern "C" void RaceDisplayLapDiffEvent__structor_2(char *self) {
    s32 sp0;
    char *q = self + 0xF4;
    RaceEntryBase__sortByRank(((SelfW *)self)->f60);
    if (RaceEventQueue__get(q, 8, 0, 1) != 0) {
        *(s32 *)(self + 0xC0) = 0;
    }
    *(s32 *)(self + 0xE8) = 0;
    while (RaceEventQueue__get(q, 0xF, &sp0, 1) != 0) {
        if (sp0 == 0) *(s32 *)(self + 0xE8) = 1;
    }
    {
    Ev ev;
    Ev *pe = &ev;
    s32 j = 0;
    RaceDisplayDiffEvent__structor_0(pe);
    ev.vt = RaceDisplayTimeDiffEvent__vtable;
    for (;j < count(pe, &ev, (Events *)(self + 0xFC));j++) {
        if (getEvent(pe, self, j) != 0) {
            Car *c = ((SelfW *)self)->f60->cars[pe->idx];
            if (c != 0) {
                setTime(c,func_003A3620(pe));
            }
        }
    }
    }
    {
    Ev ev;
    Ev *pe = &ev;
    RaceDisplayDiffEvent__structor_0(pe);
    int k = 0;
    ev.vt = RaceDisplayLapDiffEvent__vtable;
    for (;k < count(pe, &ev, (Events *)(self + 0xFC));k++) {
        if (getEvent(pe, self, k) != 0) {
            Car *c = ((SelfW *)self)->f60->cars[pe->idx];
            if (c != 0) {
                c->f11E8 = 0x157529FF;
                c->f11EC = ev.f8;
            }
        }
    }
}
}
