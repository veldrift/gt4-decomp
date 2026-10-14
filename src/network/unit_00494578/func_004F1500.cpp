/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Dst {
    char pad0[0x38];
    char c38[0xCC];
    s32 u104;
    s32 u108;
    s32 u10C;
    s32 u110;
};
struct Obj {
    char pad0[0x44];
    s32 u44;
    char pad48[0x5A8 - 0x48];
    Dst *u5A8;
};
extern "C" s32 func_004F0C88(void *) throw();
extern "C" s32 func_004F0CD0(void *, s32) throw();
extern "C" void func_0050DB50(void *, s32, s32, s32, s32);
extern "C" void func_00547428(void *);
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" void func_004F15D0(void);
extern "C" s32 func_004F1500(struct Obj *self, s32 a1, s32 a2, s32 a3) {
    if (func_004F0C88(self)) {
        func_005A48D8(self->u5A8, 0, 0x114);
        Dst *d = self->u5A8;
        func_0050DB50(d, 0, a1, a2, a3);
        d->u104 = self->u44;
        d->u108 = (s32)func_004F15D0;
        d->u10C = 0;
        d->u110 = 0;
        func_00547428(d->c38);
        return func_004F0CD0(self, 4);
    }
}
