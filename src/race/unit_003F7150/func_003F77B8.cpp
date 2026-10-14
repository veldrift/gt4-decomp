struct Obj { char p0[0x10]; char *f10; char p14[0x104 - 0x14]; };
struct Sub { char p0[0x490]; float f490; };
extern "C" int func_003F9870(Obj *self, char *p, int flag);
extern "C" void func_003F9D00(Obj *self, char *p);

extern "C" int func_003F77B8(Obj *self) {
    char *s0 = self->f10 + 0x1098;
    Sub *q = (Sub *)((char *)self + 0x104);
    func_003F9D00(self, s0);
    int a2 = 1;
    if (!(q->f490 < 0.1f)) {
        a2 = 0;
    }
    return func_003F9870(self, s0, a2);
}
