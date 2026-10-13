typedef int s32;
typedef short s16;

struct func_004AF568_arg0;

extern "C" void func_00576788(s32 a0);
extern "C" void func_005767C0(s32 a0);
extern "C" void func_004AF568(struct func_004AF568_arg0 *arg0);

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

struct Sub {
    char pad0[0xA8];
    char *vt;
};

struct Obj {
    char pad0[0xE8];
    Sub *sub;
    char lock[0x64];
    s32 f150;
    s32 f154;
};

extern "C" void func_001558D8(Obj *o)
{
    func_00576788((s32)o->lock);
    if (o->f150 != 0) {
        Sub *s = o->sub;
        VEntry *e = (VEntry *)(s->vt + 0x18);
        e->fn((char *)s + e->delta);
    }
    if (o->f154 != 0) {
        Sub *s = o->sub;
        o->sub = 0;
        func_005767C0((s32)o->lock);
        VEntry *e = (VEntry *)(s->vt + 0x20);
        e->fn((char *)s + e->delta);
        func_00576788((s32)o->lock);
        func_004AF568((struct func_004AF568_arg0 *)s);
        o->f154 = 0;
    }
    func_005767C0((s32)o->lock);
}
