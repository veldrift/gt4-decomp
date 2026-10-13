typedef int s32;
typedef float f32;

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, s32, f32, f32);
};

struct Obj {
    char pad0[0x64];
    char *inner;
    char pad1[0xE468 - 0x68];
    s32 flag;
};

extern char D_0069F158[];
extern "C" s32 func_003AEAE8(char *arg0);
extern "C" void func_0038BC98(Obj *self, s32 a, f32 c, s32 b);

extern "C" void func_00337260(Obj *o) {
    o->flag = 1;
    f32 v = 0x1.4p2f;
    func_0038BC98(o, func_003AEAE8(D_0069F158), v, 0);
    VEntry *e = (VEntry *)(o->inner + 0x2B8);
    e->fn((char *)o + e->delta, 7, v, 0x1p-1f);
}
