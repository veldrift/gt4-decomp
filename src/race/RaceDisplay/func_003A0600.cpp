/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
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
    f32 value;
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

extern "C" void RaceDisplaySpeedEvent__structor_0(Event *);
extern "C" int func_003A3248(Event *, Info *, int);
extern "C" void func_003A12A0(void *, f32);

extern "C" void func_003A0600(void *self, Info *info, int arg2) {
    Event ev;
    RaceDisplaySpeedEvent__structor_0(&ev);
    for (int i = 0; i < info->sub.count(vcall1(ev.vtbl, &ev)); i++) {
        ev.id = arg2;
        if (func_003A3248(&ev, info, i) != 0) {
            func_003A12A0(self, ev.value);
        }
    }
}
