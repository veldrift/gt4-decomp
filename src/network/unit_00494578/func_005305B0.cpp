struct Obj { int a, b, c; char pad[16]; };
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern int *D_0064B47C;
extern "C" int func_005305B0(Obj *self) {
    func_005A48D8(self, 0, 0x1c);
    self->a = 1;
    self->b = *D_0064B47C;
    self->c = 3;
    return 0;
}
