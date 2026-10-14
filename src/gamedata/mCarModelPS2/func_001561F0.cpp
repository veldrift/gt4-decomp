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
    char pad2A4[0x2A4 - 0x1DC - sizeof(Q)];
    char f2A4[1];
};

extern "C" char *func_00450B90(void *);
extern "C" int GT4Model__CarModel__getWheelFileName(const char *, void *, s32);
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_005768D8(void *);
extern "C" s32 func_00594470(const char *, const char *, unsigned int);

extern "C" s32 func_001561F0(Obj *self, const char *name) {
    Q q;
    s32 r = func_00594470(name, func_00450B90(self->f2A4), 8);
    if (r != 0) {
        void *s1 = self->f11C;
        q.type = 4;
        GT4Model__CarModel__getWheelFileName(name, q.rest, 1);
        func_00576788(s1);
        if (self->f15C == 0) {
            self->f1DC = q;
            self->f15C = 1;
            func_005768D8(s1);
        } else {
            self->f1D8 = 0;
        }
        func_005767C0(s1);
        r = 1;
    }
    return r;
}
