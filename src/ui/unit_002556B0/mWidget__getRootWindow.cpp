typedef int s32;
typedef short s16;

struct VEntry_C1E8 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct WObj_C1E8 {
    char pad0[4];
    char *vtbl;
    char pad8[0x4C];
    WObj_C1E8 *next;
};

extern "C" void *mWidget__getRootWindow(void *arg0) {
    WObj_C1E8 *self = (WObj_C1E8 *)arg0;
    s32 r;
    for (;;) {
        VEntry_C1E8 *e = (VEntry_C1E8 *)((char *)self->vtbl + 0x1A0);
        r = e->fn((char *)self + e->delta);
        if (r != 0) {
            return self;
        }
        WObj_C1E8 *n = self->next;
        if (n == 0) {
            return (void *)r;
        }
        self = n;
    }
}
