/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0043A408(void *, int);
extern "C" void SPEC_DATABASE__CarEquipments__setVariationOrder(void *, int);
extern "C" void func_005C1628(void *) throw();
extern char D_00687AE0[];
extern char D_00688280[];
struct Elem { char data[0x178]; ~Elem() { SPEC_DATABASE__CarEquipments__setVariationOrder(this, 2); } };
struct Sub { void *vt; int pad; Elem arr[3]; ~Sub() {} };
struct Self { void *vt; char pad[0x7D04]; Sub sub; };
extern "C" void func_00435268(Self *self, int flags) {
    self->vt = D_00687AE0;
    Sub *sub = &self->sub;
    sub->vt = D_00688280;
    sub->~Sub();
    func_0043A408(sub, 0);
    func_0043A408(self, 0);
    if (flags & 1) return func_005C1628(self);
}
