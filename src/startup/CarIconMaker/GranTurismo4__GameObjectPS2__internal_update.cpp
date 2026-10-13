typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

struct Obj {
    char pad0[0x64];
    char *vt;
    s32 f68;
};

extern "C" void func_00576788(s32 a0);
extern "C" void func_005767C0(s32 a0);
extern "C" void func_00109948(struct Obj *self);

extern "C" void func_00101308(struct Obj *self)
{
    s32 zero;
    s32 flag = 0;
    s32 v;

    func_00576788((s32)self);

    v = self->f68;
    zero = (v == 0);
    if (!zero) {
        self->f68 = v + 1;
        flag = (v + 1) >= 4;
    }

    func_005767C0((s32)self);

    {
        VEntry *e = (VEntry *)(self->vt + 0x30);
        e->fn((char *)self + e->delta);
    }

    if (zero) {
        VEntry *a = (VEntry *)(self->vt + 0x28);
        a->fn((char *)self + a->delta);
        VEntry *b = (VEntry *)(self->vt + 0x38);
        b->fn((char *)self + b->delta);
        return;
    }

    if (flag) {
        func_00109948(self);
    }
}
