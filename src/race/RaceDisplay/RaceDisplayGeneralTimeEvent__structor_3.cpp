/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct VEntry {
    short delta;
    short index;
    int (*fn)(void *);
};

static inline int vcall1(VEntry *vtbl, void *o) {
    VEntry *e = &vtbl[1];
    return e->fn((char *)o + e->delta);
}

struct Event {
    int id;
    VEntry *vtbl;
    int value;
    int kind;
};

struct Sub {
    char pad[0x800];
    u8 counts[1];
    int count(int t) { return counts[t]; }
};

struct Info {
    char pad0[0xFC];
    Sub sub;
};

struct VEntryV { s16 delta; s16 index; void (*fn)(void *, s32, s32); };

struct Self {
    char *vtbl;
};

extern VEntry RaceDisplayGeneralTimeEvent__vtable[];
extern "C" void RaceDisplayCheckPointEvent__structor_0(Event *);
extern "C" Event *RaceDisplayDiffEvent__structor_0(Event *);
extern "C" int func_003A3248(Event *, Info *, int);
extern "C" s32 func_003A3680(Event *);

extern "C" void RaceDisplayGeneralTimeEvent__structor_3(Self *self, Info *info, s32 key) {
    Event ev;
    RaceDisplayCheckPointEvent__structor_0(&ev);
    for (int i = 0; i < info->sub.count(vcall1(ev.vtbl, &ev)); i++) {
        if (func_003A3248(&ev, info, i) == 0) continue;
        if (ev.id != key) continue;
        s32 k = ev.kind;
        Event ev2;
        Event *p = &ev2;
        RaceDisplayDiffEvent__structor_0(p);
        ev2.vtbl = RaceDisplayGeneralTimeEvent__vtable;
        p->id = key;
        if (func_003A3248(p, info, 0) == 0) continue;
        s32 r = func_003A3680(p);
        VEntryV *e = (VEntryV *)(self->vtbl + 0x180);
        e->fn((char *)self + e->delta, k + 1, r);
    }
}
