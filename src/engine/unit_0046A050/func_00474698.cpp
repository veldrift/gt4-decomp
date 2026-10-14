struct Dev { int f0; int f4; };
struct Obj { char pad0[0x6E14]; Dev *dev; char pad1[0x6E30 - 0x6E18]; int counter; int flag; };
extern "C" void func_004745E8(Obj *self, int a1, int a2, int a3, int a4);
extern "C" void func_004735E8(Dev *d);
extern "C" void func_00473538(Dev *d, int a, int b, int c, int e);
extern "C" void func_00473608(Dev *d, int a, int b, int c);
extern "C" void func_00473620(Dev *d, int a, int b, int c);
extern "C" void func_00474698(Obj *self) {
    int *p = &self->counter;
    int t = (*p)++;
    if (t != 0) {
        func_004745E8(self, 0, 4, 2, 0);
        func_00473620(self->dev, 3, 3, 3);
    } else {
        func_004735E8(self->dev);
        func_00473620(self->dev, 2, 2, 2);
    }
    func_00473608(self->dev, 1, 0x80, 0xFF);
    func_00473538(self->dev, 0, 0, 0, 0);
    self->flag = 1;
}
