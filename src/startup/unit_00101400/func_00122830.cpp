/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
struct Disp { char p0[0x1C]; f32 f1C, f20, f24, f28; char p1[0x4C - 0x2C]; int f4C; char p2[0x64 - 0x50]; int f64; };
struct Obj {
    char p0[0x2B8]; int i2B8; char p1[0x2C0 - 0x2BC]; f32 f2C0; char p2[0x2E8 - 0x2C4]; f32 f2E8, f2EC;
    char p3[0x2F4 - 0x2F0]; f32 f2F4; char p4[0x308 - 0x2F8]; f32 f308; int i30C;
};
extern Disp *PDISTD__global_font_manager;
#define DD PDISTD__global_font_manager
extern char D_0068DD58[], D_0068DDB0[], D_0068DDB8[];
extern "C" {
f32 func_00490830(Disp *);
void func_00490290(Disp *, char *);
void func_00490518(Disp *, f32, f32, f32, f32);
void func_00490700(Disp *, int, int, int, int);
void func_004906F8(Disp *, int);
void func_00490950(Disp *, char *, ...);
}
extern "C" void func_00122830(Obj *a, f32 fparg0) {
    int s2 = 0;
    f32 f20 = a->f2EC - 16.0f;
    f32 f21 = func_00490830(DD);
    func_00490290(DD, D_0068DD58);
    int s4 = (int)f21;
    func_00490518(DD, 1.0f, 1.0f, 1.0f, 1.0f);
    Disp *d = DD;
    d->f64 = 10;
    f20 -= 128.0f;
    d->f4C = 1;
    f32 fs = (f32)s2;
    int s0 = (int)f20;
    Disp *scale = DD;
    scale->f28 = 0.7f;
    scale->f24 = 0.7f;
    do {
        f32 y = a->f2F4 - (fparg0 + a->f308 * fs / (f32)a->i30C / a->f2E8 * a->f2C0) - f21;
        func_00490700(DD, s0, (int)y, 0x80, s4);
        if (a->i2B8 != 0) func_00490950(DD, D_0068DDB0, s2);
        else func_00490950(DD, D_0068DDB8, s2);
        s2 += 0x64;
        fs = (f32)s2;
    } while (fs <= 800.0f);
    func_00490700(DD, 0, 0, (int)DD->f1C, (int)DD->f20);
    func_004906F8(DD, 0);
}
