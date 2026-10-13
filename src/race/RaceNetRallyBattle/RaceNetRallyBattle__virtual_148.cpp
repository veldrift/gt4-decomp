typedef short s16;
typedef int s32;

struct VEntry1 {
    s16 delta;
    s16 index;
    void *(*fn)(void *self);
};

struct VEntry2 {
    s16 delta;
    s16 index;
    void (*fn)(void *self, s32 a, float b, float c);
};

struct func_00426A08_arg0;
extern "C" s32 func_00426A08(struct func_00426A08_arg0 *arg0);

struct Obj {
    char pad0[0x64];
    char *vtbl;
};

extern "C" void func_00339828(Obj *self) {
    VEntry1 *e1 = (VEntry1 *)(self->vtbl + 0x230);
    void *o = e1->fn((char *)self + e1->delta);
    s32 r = func_00426A08((struct func_00426A08_arg0 *)o);
    if (r & 0x40) {
        VEntry2 *e2 = (VEntry2 *)(self->vtbl + 0x2B8);
        e2->fn((char *)self + e2->delta, 2, 0.0f, 0.0f);
    }
}
