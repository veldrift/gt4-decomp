typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj {
    char pad0[0x4C];
    char *sub;
};

extern char D_00618D48[];
extern char D_00618D50[];

extern "C" char *func_001D0568(Obj *arg0) {
    VEntry *e = (VEntry *)(arg0->sub + 0xB8);
    s32 r = e->fn((char *)arg0 + e->delta);

    if (r) {
        return D_00618D50;
    }
    return D_00618D48;
}
