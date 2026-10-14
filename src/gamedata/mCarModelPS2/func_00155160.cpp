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
    char pad160[0x1DC - 0x160];
    Q f1DC;
};

extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" s32 func_005767E0(void *);

extern "C" s32 func_00155160(Obj *self, Q *dst, s32 arg2) {
    char *s1 = self->f11C;
    s32 r;
    func_00576788(s1);
    r = self->f15C;
    if (arg2 != 0) {
        if (r == 0) {
            func_005767E0(s1);
        }
        r = 1;
    }
    if (r != 0) {
        *dst = self->f1DC;
        self->f15C = 0;
        self->f1DC.type = 0;
    }
    func_005767C0(s1);
    return r;
}
