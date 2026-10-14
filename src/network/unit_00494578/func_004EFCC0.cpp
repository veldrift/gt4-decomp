/* compiler: ee-gcc2.96-no-strict-aliasing */
struct NamePair { char a[0x40]; char b[0x40]; };
struct Obj { int f0, f4, f8; NamePair n1, n2; };
extern "C" NamePair func_004EFF48(void);
extern "C" int func_0057FBE0(void);
extern "C" void func_004EFCC0(Obj *self) {
    self->f0 = func_0057FBE0();
    self->f4 = 0x20;
    self->f8 = 0x40;
    self->n1 = func_004EFF48();
    self->n2 = func_004EFF48();
}
