typedef int s32;
typedef unsigned int u32;
typedef short s16;

struct Ent {
    s16 delta;
    s16 pad;
    void *(*fn)(void *, void *);
};

struct Vt {
    char pad[0x240];
    Ent ent;
};

struct Obj {
    char pad[0x64];
    Vt *vt;
};

struct List {
    u32 count;
    s32 pad4;
    void **items;
};

struct Self {
    char pad[0x60];
    List *list;
};

struct Item {
    char pad0[0x198];
    void *f198;
    char pad1[0x343C - 0x19C];
    s32 f343C;
};

struct Res {
    char pad[0x1CC];
    s32 f1CC;
};

extern "C" void AutomobileControlRecord__Manager__reset(void *arg0);

extern "C" void RaceOrganization__inputInitialize(Self *arg0, Obj *arg1) {
    u32 i = 0;
    List *l = arg0->list;
    for (i = 0; i < l->count; i++) {
        Item *x = (Item *)arg0->list->items[i];
        Vt *v = arg1->vt;
        Ent *e = (Ent *)((char *)v + 0x240);
        Res *r = (Res *)e->fn((char *)arg1 + e->delta, x->f198);
        x->f343C = (s32)r;
        if (r->f1CC != 0) {
            AutomobileControlRecord__Manager__reset((char *)r + 0xD4);
        }
    }
}
