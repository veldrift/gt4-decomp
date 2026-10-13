typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 pad;
    void (*fn)(void *);
};

struct Obj {
    char pad0[0x64];
    char *vt;
    char pad68[0x3C];
    s32 unkA4;
    s32 unkA8;
    char padAC[0xC1C];
    s32 unkCC8;
};

extern "C" void *D_00618840;
extern "C" char D_00821D18[];

extern "C" void func_00387EF0(Obj *arg0, s32 arg1, s32 arg2);
extern "C" void func_00576100(Obj *arg0);
extern "C" void func_00576140(Obj *arg0);

extern "C" void func_0012B888(Obj *arg0) {
    Obj **pg = (Obj **)&D_00618840;
    Obj *o = *pg;
    VEntry *e = (VEntry *)((char *)o->vt + 0x2C0);
    e->fn((char *)o + e->delta);

    Obj *g = *pg;
    func_00387EF0(g, g->unkCC8, 0);
    func_00576100((Obj *)&D_00821D18);
    arg0->unkA4 = 0;
    arg0->unkA8 = 1;
    func_00576140((Obj *)&D_00821D18);
}
