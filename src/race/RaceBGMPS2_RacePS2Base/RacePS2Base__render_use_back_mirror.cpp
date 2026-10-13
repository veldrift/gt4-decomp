typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct Sub {
    char pad0[0xD0];
    VEntry e1;
    char pad1[0x2E0];
    VEntry e2;
};

struct Owner {
    char pad0[0x64];
    Sub *sub;
    char pad1[0xC60];
    s32 flag;
};

struct Obj {
    char *vt;
};

typedef Obj *(*GetFn)(void *self, s32 arg);
typedef float (*FloatFn)(void *self);
typedef s32 (*IntFn)(void *self);

extern "C" s32 func_00341CC8(void *arg0)
{
    Owner *self = (Owner *)arg0;
    s32 res = 0;

    VEntry *e1 = &self->sub->e1;
    Obj *o = ((GetFn)e1->fn)((char *)self + e1->delta, 0);

    VEntry *e2 = &self->sub->e2;
    if (((FloatFn)e2->fn)((char *)self + e2->delta) > 0x1.47AE14p-7f) {
        if (self->flag == 0) {
            VEntry *e3 = (VEntry *)(o->vt + 0x1A0);
            res = ((IntFn)e3->fn)((char *)o + e3->delta) != 0;
        }
    }
    return res;
}
