/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Q {
    s32 type;
    char rest[196];
};

struct Obj {
    char pad0[0x11C];
    char f11C[0x15C - 0x11C];
    s32 f15C;
    char pad160[0x1D8 - 0x160];
    s32 f1D8;
    Q f1DC;
};

extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_005768D8(void *);

extern "C" s32 func_001564D8(Obj *self) {
    Q q;
    q.type = 3;
    char *s1 = self->f11C;
    func_00576788(s1);
    if (self->f15C == 0) {
        self->f1DC = q;
        self->f15C = 1;
        func_005768D8(s1);
    } else {
        self->f1D8 = 0;
    }
    func_005767C0(s1);
    return 1;
}
