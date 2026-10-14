struct Obj { char p0[0x38]; void *f38; void *f3C; char p40[0x19C - 0x40]; float f19C; char p1A0[0x1AC - 0x1A0]; float f1AC; };
struct Local { char p0[0x54]; float f54; };
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_001D61D8(Obj *s);
extern "C" void func_004523E8(float a, float b, float c, float d);
extern "C" void func_00459780(Local *l, void *v);
extern "C" void func_00451A00(void *a, void *b, int c, int d, int e, int f, float g);

extern "C" void func_001D6DC8(Obj *self) {
    Local L;
    func_004A53F8();
    func_001D61D8(self);
    func_004523E8(0.0f, 0.0f, 0.0f, self->f19C);
    func_00459780(&L, self->f3C);
    L.f54 = self->f1AC;
    func_00451A00(self->f38, &L, 0, 1, 0, 1, 0.0f);
    func_004A5400();
}
