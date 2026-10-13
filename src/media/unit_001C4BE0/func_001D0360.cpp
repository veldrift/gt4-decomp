typedef short s16;
typedef int s32;

extern char D_00694EE0[];
extern char D_00694EF8[];

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj {
    char pad0[0x4C];
    char *sub;
};

extern "C" char *func_001D0360(Obj *arg0) {
    char *res;
    VEntry *e = (VEntry *)(arg0->sub + 0x108);

    if (e->fn((char *)arg0 + e->delta) != 0) {
        res = D_00694EE0;
    } else {
        res = D_00694EF8;
    }
    return res;
}
