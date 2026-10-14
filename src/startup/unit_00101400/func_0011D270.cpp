typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Inner {
    char pad0[0xDC];
    s32 fDC;
    char pad1[0xF0 - 0xE0];
    s32 fF0;
};

struct Obj {
    char pad0[0x64];
    char *vtbl;
    char pad1[0x6C - 0x68];
    Inner *p6C;
    char pad2[0xF050 - 0x70];
    s32 fF050;
};

extern "C" char D_0068DBC8[];
extern "C" void func_0012BFC0(void *);
extern "C" void func_0012BFD0(int);
extern "C" void func_0010FE40(char *);
extern "C" void func_00387EF0(void *, int, int);
extern "C" void func_003BC5A8(void *, int);

extern "C" void func_0011D270(Obj *o) {
    char *base = (char *)o;
    Inner *i = o->p6C;
    s32 saved = o->fF050;
    s32 one = 1;
    o->fF050 = 0;
    i->fDC = 1;
    i->fF0 = 1;
    func_003BC5A8(o, 1);
    func_00387EF0(o, 4, 1);
    func_0012BFC0(o);
    func_0012BFD0(1);
    func_0010FE40(D_0068DBC8);
    func_0012BFC0(0);
    VEntry *e = (VEntry *)(o->vtbl + 0x2C0);
    e->fn(base + e->delta);
    func_003BC5A8(o, 0);
    i->fF0 = 0;
    i->fDC = 0;
    o->fF050 = saved;
}
