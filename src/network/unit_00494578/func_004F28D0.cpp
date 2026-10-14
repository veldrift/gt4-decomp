/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Dst {
    char pad0[0x15];
    char c15[0x11];
    s32 u28;
    s32 u2C;
    char c30[0x40];
    char c70[0x20];
};
struct Q3 { s32 u0, u4, u8; };
struct Obj {
    char pad0[0x40];
    Q3 q;
    char pad4C[0x5A8 - 0x4C];
    Dst *u5A8;
    char pad5AC[0xAF8 - 0x5AC];
    char c_af8[0x11];
};
extern "C" s32 func_004F0C88(void *) throw();
extern "C" s32 func_004F0CD0(void *, s32) throw();
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" int func_005A6AB0(void *, void *, s32) throw();
static inline void fill(Q3 *q, s32 a3, Dst *d) {
    s32 lim = q->u8;
    d->u28 = q->u0;
    d->u2C = (a3 >= lim) ? lim : a3;
}
extern "C" s32 func_004F28D0(struct Obj *self, void *a1, void *a2, s32 a3) {
    if (func_004F0C88(self)) {
        func_005A48D8(self->u5A8, 0, 0xA4);
        Dst *d = self->u5A8;
        func_005A6AB0(d->c15, self->c_af8, 0x11);
        fill(&self->q, a3, d);
        func_005A6AB0(d->c30, a1, 0x40);
        if (a2) {
            func_005A6AB0(d->c70, a2, 0x20);
        } else {
            d->c70[0] = 0;
        }
        return func_004F0CD0(self, 0x18);
    }
}
