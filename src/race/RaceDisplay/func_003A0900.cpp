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
    char *text;
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

struct Disp {
    char pad[0x20];
    unsigned int color;
};

struct Self {
    char pad[0x17BC];
    Disp disp;
};

extern char D_006A0718[];
extern "C" void RaceDisplayMessageEvent__structor_0(Event *);
extern "C" int func_003A3248(Event *, Info *, int);
extern "C" void func_003A5268(Disp *, char *, s32);
extern "C" void RaceEventDisplay__addEvent(Disp *, char *, float, float, float, float);

extern "C" void func_003A0900(Self *self, Info *info) {
    Event ev;
    RaceDisplayMessageEvent__structor_0(&ev);
    for (int i = 0; i < info->sub.count(vcall1(ev.vtbl, &ev)); i++) {
        ev.id = -1;
        if (func_003A3248(&ev, info, i) == 0) return;
        Disp *d = &self->disp;
        func_003A5268(d, D_006A0718, 1);
        d->color = 0x80C8C8C8;
        RaceEventDisplay__addEvent(d, ev.text, 3.0f, 0.0f, 0.0f, 0.0f);
    }
}
