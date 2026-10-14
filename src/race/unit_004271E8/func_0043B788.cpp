typedef int s32;

typedef s32 (*VFn0043B788)(void *self, void *a1, s32 a2);

struct VEntry0043B788 {
    short delta;
    short index;
    VFn0043B788 fn;
};

struct Obj0043B788 {
    void *vt;
};

static inline s32 vcall0043B788(void *o, void *a1) {
    struct VEntry0043B788 *e = (struct VEntry0043B788 *)((char *)((struct Obj0043B788 *)o)->vt + 0x20);
    short d = e->delta;
    return e->fn((char *)o + d, a1, d);
}

extern "C" void func_0043B788(void *arg0, void *arg1) {
    __builtin_memcpy((char *)arg0 + 4, arg1, 0x24);
    vcall0043B788(arg0, arg1);
}
