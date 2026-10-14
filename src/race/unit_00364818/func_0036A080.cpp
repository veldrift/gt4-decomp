typedef int s32; typedef float f32; typedef unsigned char u8;

struct Rec { char pad0[1]; u8 n; char pad2[0x12]; u8 a[0x18]; };
struct Tbl { char pad0[4]; s32 x; };
struct Car { char pad0[0x8C]; f32 f8C, f90; char pad94[0xC8 - 0x94]; f32 fC8; char padCC[0xEC - 0xCC]; };
struct S { char pad0[0x5C]; f32 f5C; };
struct Obj {
    char pad0[0x10];
    Tbl *tbl;
    char pad14[0x104 - 0x14];
    S s;
    char pad164[0x164 - 0x104 - sizeof(S)];
    Car car[1];
    char padCar[0x514 - 0x164 - sizeof(Car)];
    f32 out[1];
};

extern "C" Rec *func_00359510(Tbl *);
extern "C" f32 func_003696C8(Obj *, s32);
extern "C" f32 func_00369760(Obj *, s32, s32, f32);

static inline f32 difference(f32 sum, f32 h, f32 scale, f32 divisor) {
    sum = h - sum;
    sum *= scale;
    sum /= divisor;
    return sum;
}

extern "C" void func_0036A080(Obj *self) {
    s32 i;
    S *sp = &self->s;
    Tbl *t = self->tbl;
    Rec *r = func_00359510(t);
    for (i = 0; i < r->n; i++) {
        f32 g4 = func_003696C8(self, i);
        f32 h = func_00369760(self, i, 2, g4);
        Car *c = &self->car[i];
        f32 sum = c->f8C + c->f90;
        f32 d = difference(sum, h, sp->f5C, c->fC8);
        u8 idx = 0;
        if (i < r->n) idx = r->a[i];
        f32 *p4 = (f32 *)((char *)t + 4);
        char *p14 = (char *)t + 0x14;
        self->out[i] = d - p4[idx + 0xB0] + *(f32 *)(p14 + idx * 0x58 + 0x300) - g4;
    }
}
