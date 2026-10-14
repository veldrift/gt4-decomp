/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    char pad0[0x1c];
    unsigned char state;
    char pad1[4];
    unsigned char previous;
    char pad2[0xa];
    float blend;
    char pad3[0xbc];
    void *data;
};
extern "C" int func_0046BB48(void *, unsigned);
extern "C" int func_00463C00(Obj *, int) throw();
extern "C" void func_00467AA8(Obj *);
extern "C" int func_00463C28(Obj *self, int state, int immediate) {
    int next = func_0046BB48(self->data, state);
    if (next == -1) return 0;
    if (immediate == 0) {
        if (state == self->previous) self->blend = 1.0f - self->blend;
        else self->blend = 1.0f;
        int old = self->state;
        self->state = next;
        self->previous = old;
        func_00467AA8(self);
    } else {
        func_00463C00(self, next);
    }
    return 1;
}
