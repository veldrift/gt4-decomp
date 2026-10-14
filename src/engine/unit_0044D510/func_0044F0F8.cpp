/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short d; short i; void *fn; };
struct Vt { char pad[0x18]; VE e18; char pad2[0x160 - 0x20]; VE e160; };
struct O { Vt *vt; };
struct R { char pad[0x18]; int f18; };
extern "C" void func_0044EFD0(void *, int, float) throw();
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A7454(void);
extern "C" void func_0044F0F8(void *self, O *o, float f) {
    func_004A53F8();
    func_004A7454();
    VE *e = &o->vt->e18;
    ((void (*)(void *, float))e->fn)((char *)o + e->d, f);
    VE *e2 = &o->vt->e160;
    R *r = ((R *(*)(void *))e2->fn)((char *)o + e2->d);
    func_0044EFD0(self, r->f18, f);
    func_004A5400();
}
