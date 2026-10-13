typedef short s16;
typedef int s32;

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *); };
struct Obj { s32 m0; VEntry *vtbl; };
struct Inner { char pad0[0x4A]; s16 f4A; };
struct Holder { char pad0[0x10]; Inner *in; };
struct Guard { Holder *p; s32 pad[3]; };

extern "C" void func_00174148(void *arg0, void *arg1);
extern "C" void func_001740F0(void *arg0, int arg1);

extern "C" void func_001769F0(void *a0, void *a1, void *a2, Obj **a3) {
    Guard g;
    func_00174148(&g, a1);
    Obj *o = *a3;
    Inner *in = g.p->in;
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x58);
    in->f4A = e->fn((char *)o + e->delta);
    func_001740F0(&g, 2);
}
