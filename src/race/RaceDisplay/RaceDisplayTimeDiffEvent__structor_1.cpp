typedef int s32;
typedef float f32;
typedef unsigned char u8;
typedef short s16;

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

struct VEntryI { s16 delta; s16 index; s32 (*fn)(void *self, s32 a); };

struct Self {
    char *vtbl;
    char pad4[0xBC - 4];
    f32 bc;
};

extern VEntry RaceDisplayTimeDiffEvent__vtable[];
extern "C" Event *RaceDisplayDiffEvent__structor_0(Event *);
extern "C" int func_003A3248(Event *, Info *, int);
extern "C" int func_003A3620(Event *);
extern "C" void func_003A1098(Self *, s32, s32, s32);

extern "C" void RaceDisplayTimeDiffEvent__structor_1(Self *self, Info *info, int arg2) {
    if (!(self->bc < 1.0f)) {
        Event ev;
        RaceDisplayDiffEvent__structor_0(&ev);
        ev.vtbl = RaceDisplayTimeDiffEvent__vtable;
        for (int i = 0; i < info->sub.count(vcall1(ev.vtbl, &ev)); i++) {
            ev.id = arg2;
            if (func_003A3248(&ev, info, i) != 0) {
                int r = func_003A3620(&ev);
                VEntryI *e = (VEntryI *)(self->vtbl + 0x198);
                int a2 = e->fn((char *)self + e->delta, r);
                s32 color;
                switch (ev.kind) {
                case 1:
                    color = (s32)0x80E3B896;
                    break;
                case 2:
                    color = 0x800000C8;
                    break;
                case 0:
                default:
                    color = r > 0 ? 0x800000C8 : (s32)0x80E3B896;
                    break;
                }
                func_003A1098(self, r, a2, color);
            }
        }
    }
}
