/* compiler: ee-gcc2.96-no-strict-aliasing */
struct B { char p[0x18]; char *buf; };
struct S { char p[0x1C]; B *b; };
struct G {
    char p0[0x2C];
    int idx;
    char p1[0x54 - 0x30];
    float ox;
    float oy;
    char p2[0x80 - 0x5C];
    int mode;
};
extern int D_006D618C;
extern B *D_006D6184;
extern G *PDISTD__global_font_manager;
extern float D_0062498C;
extern float D_00624990;
extern "C" int func_00499728(B *);
extern "C" void func_0049CC48(char *);
extern "C" void func_0049FE28(void);
extern "C" void func_00499948(float, float, float, float, float, float, float, float);
extern "C" void func_004A6668(float, float, float, float, float, float, float, float);

extern "C" void func_00491FC0(S *self, int a, int b, int c, int d, float f0, float f1, float f2, float f3)
{
    if (D_006D618C != 1) {
        B *bb = self->b;
        if (D_006D6184 != bb) {
            D_006D6184 = bb;
            func_00499728(bb);
        }
        func_0049CC48(bb->buf + PDISTD__global_font_manager->idx * 0x28);
        func_0049FE28();
        D_006D618C = 1;
    }
    float fa = (float)a;
    float fb = (float)b;
    float fc = (float)c;
    float fd = (float)d;
    G *g = PDISTD__global_font_manager;
    if (g->mode != 0) {
        func_00499948(f0, f1, f2, f3, fa, fb, fc, fd);
        return;
    }
    func_004A6668((f0 + g->ox) * D_0062498C, (f1 + g->oy) * D_00624990,
                  (f2 + g->ox) * D_0062498C, (f3 + g->oy) * D_00624990, fa, fb, fc, fd);
}
