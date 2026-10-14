/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Q {
    s32 type;
    char rest[196];
};

struct Obj {
    char pad0[0x158];
    s32 f158;
};

extern "C" s32 func_00155160(Obj *, Q *, s32) throw();
extern "C" void func_00155510(Obj *, Q *);
extern "C" void func_001558D8(Obj *);

extern "C" void func_001552A0(Obj *self) {
    Q a;
    Q b;
    while (self->f158 != 0) {
        func_00155160(self, &a, 1);
        if (a.type != 0) {
            func_001558D8(self);
            if (func_00155160(self, &b, 0) != 0 && b.type == 2) {
                a = b;
            }
            if (a.type == 1) break;
            func_00155510(self, &a);
        }
    }
    func_001558D8(self);
}
