typedef int s32;
typedef short s16;

extern char D_00623800[];

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self, s32 v);
};

struct Obj {
    char pad[0x68];
    char *vtbl;
};

extern "C" void func_00447B60(s32 arg0) {
    Obj **slot = (Obj **)(D_00623800 + arg0 * 4);
    Obj *o = *slot;
    if (o) {
        VEntry *e = (VEntry *)(o->vtbl + 8);
        e->fn((char *)o + e->delta, 3);
        *slot = 0;
    }
}
