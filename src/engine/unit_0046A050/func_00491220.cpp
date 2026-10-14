typedef float f32;
struct Obj {
    char p0[0x30]; f32 f30, f34, f38, f3C; char p1[0x54 - 0x40]; f32 f54; char p2[4]; f32 f5C; char p3[4]; int f64;
    char p4[0x78 - 0x68]; int f78;
};
extern "C" {
void func_00492ED0();
void func_00492EA8();
void func_00493C70(Obj *, void *, int, int, int);
void func_004940E8(Obj *, void *, int, int);
}
extern "C" void func_00491220(Obj *self, int a1, int a2, int flag, int t0, f32 add) {
    self->f30 = 0.0f;
    f32 f0 = self->f38;
    f32 f1 = self->f30;
    int saved = self->f78;
    f32 f2;
    if (f0 <= f1) {
        if (flag != 0) func_00493C70(self, (void *)func_00492ED0, 0, a1, a2);
        else func_004940E8(self, (void *)func_00492ED0, 1, a1);
        f2 = self->f30;
    } else {
        self->f38 = f1;
        f2 = f0;
    }
    int m = self->f64 & 3;
    self->f78 = saved;
    f32 w = self->f5C - self->f54;
    self->f3C = f2;
    if (m == 1) {
        self->f30 = (w - f2) * 0.5f;
    } else if (m == 2) {
        self->f30 = w - f2;
    }
    if (t0 == 0) {
        if (flag != 0) func_00493C70(self, (void *)func_00492EA8, 0, a1, a2);
        else func_004940E8(self, (void *)func_00492EA8, 0, a1);
    }
    self->f34 = self->f34 + add;
}
