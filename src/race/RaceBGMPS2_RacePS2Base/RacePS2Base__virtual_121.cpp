/* compiler: ee-gcc2.96-nogcse */
typedef int s32;
typedef unsigned int u32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    char pad0[8];
    VEntry *vtbl;
};

struct Entry0 {
    char pad0[0x2880];
    Obj *p2880;
};

struct List0 {
    u32 count;
    char pad4[4];
    Entry0 **items;
};

struct Inner {
    char pad0[0x60];
    List0 *list;
};

struct Obj0 {
    char pad0[0x6C];
    Inner *inner;
};

extern "C" void RacePS2Base__virtual_121(Obj0 *self) {
    List0 *list = self->inner->list;
    u32 i = 0;
    if (list->count != 0) {
        do {
            Entry0 *e = list->items[i];
            i++;
            if (e->p2880 != 0) {
                Obj *o = e->p2880;
                VEntry *entry = o->vtbl + 29;
                entry->fn((char *)o + entry->delta);
            }
        } while (i < list->count);
    }
}
