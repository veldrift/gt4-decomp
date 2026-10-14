/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
struct Disp { char p[0x24]; f32 f24; f32 f28; };
struct Obj {
    char p0[0x2B8]; int i2B8; f32 f2BC; char p1[0x2D4 - 0x2C0]; f32 f2D4, f2D8, f2DC, f2E0, f2E4;
    char p2[0x2F4 - 0x2E8]; f32 f2F4;
};
extern Disp *PDISTD__global_font_manager;
extern char D_0068DD58[], D_0068DD60[], D_0068DD68[];
extern "C" {
void func_00490290(Disp *, char *);
void func_00490518(Disp *, f32, f32, f32, f32);
f32 func_00490860(Disp *);
void func_00490890(Disp *, f32, f32);
int func_00490950(Disp *, char *, ...);
void func_004A7288(f32, f32, f32, f32, f32, f32);
int func_004AB2E8(f32, f32, f32);
}
extern "C" void func_00121340(Obj *a, f32 fparg0) {
    f32 s = a->f2BC * 4.0f;
    f32 f24 = a->f2D4;
    f32 f29 = a->f2E0;
    int s5 = (int)(a->f2DC / s) + 1;
    int s0 = (int)(f24 / s);
    f32 f28 = a->f2D8;
    func_00490290(PDISTD__global_font_manager, D_0068DD58);
    Disp *disp = PDISTD__global_font_manager;
    disp->f28 = 0.5f;
    disp->f24 = 0.5f;
    s0 -= 1;
    f32 f0 = func_00490860(PDISTD__global_font_manager) - 1.0f;
    int i = s0;
    if (s5 >= i) {
        f32 f26 = fparg0 - f0;
        do {
            int pos = (int)((f32)i * a->f2BC * 4.0f);
            func_004AB2E8(0.5f, 0.5f, 0.5f);
            f32 f20 = (f32)pos;
            func_004A7288(f20, f29, 0.0f, f20, f28, 0.0f);
            f20 -= f24;
            f20 *= a->f2E4;
            f32 f21 = a->f2F4;
            f21 -= f26;
            func_00490518(PDISTD__global_font_manager, 1.0f, 1.0f, 1.0f, 1.0f);
            func_00490890(PDISTD__global_font_manager, f20, f21);
            if (a->i2B8 != 0) {
                func_00490950(PDISTD__global_font_manager, D_0068DD60, pos);
            } else if ((i & 0xF) == 0) {
                func_00490950(PDISTD__global_font_manager, D_0068DD68, pos / 1600);
            }
            i++;
        } while (s5 >= i);
    }
}
