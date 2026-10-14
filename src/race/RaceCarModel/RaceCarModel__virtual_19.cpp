/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct O0 { char b[0x40]; };
struct O40 { s32 f0, f4, f8; char pad[0x14]; };
struct A { s32 f0, f4; char pad[0x18]; };
struct B { void *f0; s32 f4; char pad[8]; };
struct Obj { char pad[0x18]; char sub[1]; };
extern "C" void func_0038F900(void);
extern "C" void func_0044CC18(O0 *, A *, B *, s32);
extern "C" s32 func_00450BD0(void *, s32);
extern "C" s32 func_00450BF0(void *);
extern "C" void func_00451598(void *);
extern "C" void func_004515A8(void *);
extern "C" void GT4Model__CarModel__getWingFileName(const char *, O0 *, s32);
extern "C" void func_004AE6B0(O40 *, O0 *);
extern "C" s32 func_00594470(const char *, s32, s32);
extern "C" void RaceCarModel__virtual_19(Obj *self, const char *name, s32 arg2) {
    if (name == 0) {
        func_004515A8(self->sub);
        return;
    }
    if (*name == 0) {
        func_00451598(self->sub);
        return;
    }
    void *s2 = self->sub;
    if (func_00594470(name, func_00450BF0(s2), 8) != 0) {
        O0 o0;
        O40 o40;
        A a;
        B b;
        GT4Model__CarModel__getWingFileName(name, &o0, arg2);
        func_004AE6B0(&o40, &o0);
        s32 v = func_00450BD0(s2, (o40.f8 + 0x3F) & ~0x3F);
        A *pa = &a;
        B *pb = &b;
        pa->f0 = v;
        pa->f4 = 0;
        pb->f0 = (void *)func_0038F900;
        pb->f4 = (s32)self;
        func_0044CC18(&o0, pa, pb, 1);
    }
}
