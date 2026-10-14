/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj {
    s32 f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C, f30;
    float f34;
    s32 f38;
    s32 tab[16];
};
extern "C" void func_004971A0(s32, s32, s32) throw();
extern "C" s32 func_00497518(Obj *, s32) throw();
extern "C" void func_004A1638(s32);
extern "C" void func_004A29A8(s32);
extern "C" void func_004A4550(s32, s32);
extern "C" void pglPushAttrib(s32);
extern "C" void func_004A5688(void);
extern "C" void func_004A6140(s32, s32, s32, s32);
extern "C" void func_004AA1D8(float, float, float, float);
extern "C" void func_004AB040(s32);

extern "C" int func_00497AF0(Obj *self, float f, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, s32 sp0, s32 sp8, s32 sp10) {
    s32 i = 0;
    s32 *p = self->tab;
    self->f34 = f;
    self->fC = a1;
    self->f18 = a2;
    self->f1C = a3;
    self->f10 = a2;
    self->f14 = a3;
    self->f0 = t0;
    self->f4 = t1;
    self->f2C = sp8;
    self->f30 = sp10;
    self->f20 = t2;
    self->f24 = t3;
    self->f28 = sp0;
    self->f8 = 0;
    pglPushAttrib(0x887);
    do {
        s32 k = i + 2;
        i += 1;
        *p = func_00497518(self, k);
        p += 1;
    } while (i < 16);
    func_004AB040(4);
    func_004AB040(6);
    func_004A4550(3, 1);
    func_004A4550(2, 1);
    func_004A4550(1, 0);
    func_004AB040(5);
    func_004A29A8(0);
    func_004971A0(t2, t3, sp0);
    func_004AA1D8(1.0f, 0.0f, 0.0f, 0.0f);
    func_004A6140(0, 0, 1, 1);
    func_004A29A8(1);
    func_004A1638(5);
    func_004A5688();
}
