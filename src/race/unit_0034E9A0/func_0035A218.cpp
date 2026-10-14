/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Cfg { char p0[0x3C]; float f3C; char p1[0x2C8 - 0x40]; float f2C8; };
struct Info { char p0[8]; unsigned char b08; char p1[3]; unsigned char b0C; char p2[0x24-0xD]; unsigned char t24[1]; };
struct Pt { char p0[0x10]; float f10; char p1[0x30 - 0x14]; float f30; char p2[0x38 - 0x34]; float f38; char p3[0x6C - 0x3C]; float f6C; };
struct Sub { char p0[0x5C]; float f5C; char p1[0x578 - 0x60]; float f578; };
struct Self {
    char p0[0x10];
    Cfg *cfg;
};
extern "C" float func_00344888(Self *, float);
extern "C" float func_00344B40(Self *, int, float) throw();
extern "C" Info *func_00359538(Self *) throw();
extern "C" Pt *func_00359F50(Self *) throw();
extern "C" float func_0057D1F0(float);

extern "C" float func_0035A218(Self *self, int k, float x) {
    Pt *pt = func_00359F50(self);
    if (k == 0) {
        Info *info = func_00359538(self);
        unsigned char *tp = &info->b08;
        unsigned idx = info->b0C;
        float f22 = func_0057D1F0(pt->f30);
        float a = func_00344B40(self, idx, x);
        if (*tp == 2) {
            a += func_00344B40(self, info->t24[idx], x);
            a *= 0.5f;
        }
        Cfg *c = self->cfg;
        a = a - ((c->f2C8 - pt->f10) - c->f3C);
        if (*tp == 2) {
            float v = func_00344888(self, 0.0f);
            Sub *sub = (Sub *)((char *)self + 0x104);
            a /= func_0057D1F0(v - sub->f578);
            a *= sub->f5C;
        }
        return ((a - pt->f6C) / f22) - pt->f38;
    }
    return pt->f10;
}
