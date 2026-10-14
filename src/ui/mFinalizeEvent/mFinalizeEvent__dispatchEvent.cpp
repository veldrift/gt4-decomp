/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct Ev;
struct VEntryP { s16 delta; s16 index; void *(*fn)(void *); };
struct VEntry3 { s16 delta; s16 index; void (*fn)(void *, s32, s32, ...); };
extern char D_0069B158[], D_0069B160[], D_0069B178[];
struct Ev {
    char pad0[4];
    char *vtbl;
    char pad8[8];
    s32 u10;
    s32 u14;
};
extern "C" s32 func_0028EA08(void *);
extern "C" s32 func_0028EA18(void *);
extern "C" char *hModule__getName(void *);
extern "C" void func_005D4AD8(const char *, ...);
extern "C" s32 mFinalizeEvent__dispatchEvent(struct Ev *self) {
    func_005D4AD8(D_0069B158);
    VEntryP *e = (VEntryP *)(self->vtbl + 0x50);
    func_005D4AD8(D_0069B160, hModule__getName(e->fn((char *)self + e->delta)), self->u14, self->u10);
    if (func_0028EA18(self)) {
        s32 s0 = func_0028EA08(self);
        s32 r2 = func_0028EA18(self);
        VEntry3 *f = (VEntry3 *)(self->vtbl + 0x198);
        s16 d = f->delta;
        void (*fn)(void *, s32, s32, ...) = f->fn;
        fn((char *)self + d, s0, r2);
    }
    func_005D4AD8(D_0069B178);
    return 1;
}
