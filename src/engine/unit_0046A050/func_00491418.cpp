typedef float f32;
typedef unsigned char u8;

struct Font {
    char p0[0xD];
    u8 fD;
    signed char fE;
};
struct Obj {
    char p0[0x14];
    Font *font;
    char p18[0x24 - 0x18];
    f32 f24;
    f32 f28;
    char p2C[0x30 - 0x2C];
    f32 f30;
    f32 f34;
    char p38[0x3C - 0x38];
    f32 f3C;
    f32 f40;
    int f44;
    char p48[0x4C - 0x48];
    int f4C;
    int f50;
    f32 f54;
    f32 f58;
    f32 f5C;
    f32 f60;
    int f64;
    int f68;
    char p6C[0x78 - 0x6C];
    int f78;
    int f7C;
};

extern int D_00624988;
extern "C" int func_00490BF8(const char *) throw();
extern "C" void func_00490D08(Obj *, int, int) throw();
extern "C" void func_00491028(Obj *, int, int, int, int, int, f32) throw();
extern "C" void func_00491220(Obj *, int, int, int, int, f32) throw();
extern "C" void func_00491380(Obj *, int, int, int, int) throw();
extern "C" int func_00491AC0(Font *) throw();
extern "C" void func_00491EB0(void);
extern "C" void func_00491F98(void);
extern "C" void func_004924B8(void);

extern "C" void func_00491418(Obj *self, int a1, int a2, int a3, int t0)
{
    self->f3C = 0.0f;
    int saved = self->f44;
    self->f40 = 0.0f;
    int cur = saved;
    int s5 = self->f7C;
    if (t0 == 0) {
        if (s5 == 0) {
            func_00491EB0();
            cur = self->f44;
        }
    }
    D_00624988 = cur;
    func_00491F98();
    if (self->f4C != 0) {
        int cnt = self->f68 == 0 ? 1 : func_00490BF8((const char *)a1);
        Font *fn = self->font;
        f32 fcnt = (f32)cnt;
        f32 sc = self->f28;
        f32 cw = (f32)fn->fD * sc;
        f32 ch = (f32)fn->fE * sc;
        int fl = self->f64;
        f32 tw = cw * fcnt;
        self->f40 = tw;
        if ((fl & 0xC) != 0) {
            f32 w = self->f60 - self->f58;
            int al = (fl >> 2) & 3;
            if (al == 1) {
                self->f34 = ch + (w - tw) * 0.5f;
            } else if (al == 2) {
                self->f34 = ch + (w - tw);
            }
        } else {
            self->f34 = ch;
        }
        if ((fl & 3) != 0) {
            if (self->f68 != 0)
                func_00491028(self, a1, a2, cnt, a3, t0, cw);
            else
                func_00491220(self, a1, a2, a3, t0, cw);
        } else {
            self->f30 = 0.0f;
            func_00491380(self, a1, a2, a3, t0);
            int h = func_00491AC0(self->font);
            self->f3C = self->f30 - (f32)(h / 2) * self->f24;
        }
    } else if (self->f50 != 0) {
        if (a3 == 0)
            func_00490D08(self, a1, t0);
    } else {
        f32 old = self->f34;
        func_00491380(self, a1, a2, a3, t0);
        self->f40 = self->f34 - old;
        self->f3C = self->f5C - self->f54;
    }
    if (t0 == 0) {
        if (s5 == 0)
            func_004924B8();
    }
    self->f78 = 0;
    if (t0 == 0)
        self->f44 = saved;
}
