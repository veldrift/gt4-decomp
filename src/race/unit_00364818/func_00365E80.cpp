/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef float f32;

struct Ctx {
    char pad0[0xCCC8];
    u8 b[6][6];
    f32 f[6][6];
    char padCD7C[0xF8A0 - 0xCD7C];
    int n;
};

extern "C" char *func_0034C190(Ctx *, int);
extern "C" void DynamicsConductor__ComputeDifference(Ctx *, void *, void *, int *, f32 *) throw();

extern "C" void func_00365E80(Ctx *ctx) {
    int i, j;
    int n = ctx->n;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                int v;
                f32 d;
                char *pj = func_0034C190(ctx, j) + 0x104;
                char *pi = func_0034C190(ctx, i) + 0x104;
                DynamicsConductor__ComputeDifference(ctx, pj, pi, &v, &d);
                if (v >= 0x80)
                    v = 0x7F;
                else if (v < -0x7F)
                    v = -0x7F;
                ctx->b[i][j] = (u8)v;
                ctx->f[i][j] = d;
            }
        }
    }
}
