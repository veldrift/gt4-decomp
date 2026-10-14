/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Cfg { char p0[0x3C]; float f3C; char p1[0x2C8 - 0x40]; float f2C8; };
struct Info { char p0[9]; unsigned char b09; char p1[3]; unsigned char b0D; char p2[0x24 - 0xE]; unsigned char t24[1]; };
struct Pt { char p0[0x10]; float f10; float f14; char p1[0x68 - 0x18]; float f68; };
struct Sub { char p0[0x5C]; float f5C; char p1[0x578 - 0x60]; float f578; };
struct Self {
    char p0[0x10];
    Cfg *cfg;
    char p1[0x104 - 0x14];
    Sub sub;
};
struct Self2 { char p0[0x160]; float f160; };
extern "C" float func_00344888(Self *, float);
extern "C" float func_00344B40(Self *, int, float);
extern "C" Info *func_00359538(Self *) throw();
extern "C" Pt *func_00359F50(Self *) throw();
extern "C" float func_0057D118(float, float);
extern "C" float func_0057D1F0(float);

extern "C" float func_0035A0C0(Self *self, float x) {
    Sub *sub = (Sub *)((char *)self + 0x104);
    Info *info = func_00359538(self);
    unsigned idx = info->b0D;
    float a = func_00344B40(self, idx, x);
    Pt *pt = func_00359F50(self);
    if (info->b09 == 2) {
        a += func_00344B40(self, info->t24[idx], x);
        a *= 0.5f;
        Cfg *c = self->cfg;
        a = c->f2C8 - a;
        float d = func_0057D1F0(func_00344888(self, 0.0f) - sub->f578);
        a /= d;
        a += (c->f2C8 - pt->f10) - c->f3C;
        a *= sub->f5C;
        float r1 = func_0057D118(a - c->f2C8, pt->f14);
        return r1 + func_0057D118(pt->f10, pt->f14);
    } else {
        Cfg *c = self->cfg;
        float t = -(c->f2C8 - c->f3C) * ((Self2 *)self)->f160;
        return -func_0057D118(a + t, pt->f68);
    }
}
