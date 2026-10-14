/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32; typedef float f32;

struct Obj {
    s32 i0;
    char pad4[0x34 - 4];
    f32 f34;
    char pad38[4];
    f32 f3C;
    char pad40[8];
    f32 f48[4];
    f32 f58[2];
    f32 f60[3];
    f32 f6C;
    char pad70[0x80 - 0x70];
    s32 i80;
    char pad84[4];
    f32 f88[4];
    char pad98[0xCC - 0x98];
    f32 fCC;
};

extern "C" f32 func_0036F4E0(void *);
extern "C" void func_003704D0(Obj *, f32, f32);
extern "C" void func_00370DD0(Obj *, void *, s32);
extern "C" s32 func_00370EF8(Obj *, s32 *, f32 *, void *, s32, f32);
extern "C" void func_003FEE08(void *, void *, s32, s32, void *);
extern "C" void func_005F5040(f32 *, f32 *);
extern "C" void func_005F5230(f32 *, s32);

extern "C" void func_00371530(Obj *self, f32 *a1, s32 a2) {
    f32 v0[4];
    f32 ang;
    s32 flag;
    f32 v1[4];
    f32 v2[4];
    f32 *p60 = self->f60;
    f32 *p6C = &self->f6C;
    f32 t = func_0036F4E0(self->f48);
    s32 id = self->i80;
    ang = t;
    func_005F5040(p60, v0);
    f32 saved = ang;
    func_005F5040(a1, v1);
    func_005F5230(v1, a2);
    func_005F5040(v1, v2);
    func_003FEE08(p60, v2, self->i0, id, self->f88);
    func_00370DD0(self, p60, id);
    if (func_00370EF8(self, &flag, &ang, p60, id, *p6C) == 0 || flag != 0) {
        func_005F5040(v0, p60);
        func_00370DD0(self, p60, id);
        ang = saved;
        func_00370EF8(self, &flag, &ang, p60, id, *p6C);
    }
    f32 *p34 = &self->f34;
    self->fCC = ang;
    func_005F5040(p60, p34);
    func_003704D0(self, *p34, self->f3C);
}
