typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Mid {
    char pad[0x10140];
    VEntry *vtbl;
};

struct Obj {
    char pad0[4];
    Mid *f4;
};

extern "C" s32 func_00359AF0(Obj *arg0) {
    s32 r = 0;
    char *p = (char *)arg0 + 0x104;
    Mid *m = arg0->f4;
    VEntry *e = m->vtbl + 6;
    if (e->fn((char *)m + e->delta)) {
        r = (*(s32 *)(p + 0x464) & 0xFFFF0000) == 0;
    }
    return r;
}
