/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { float f0, f4; int count; float v0[4], v1[4], v2[4], v3[4]; float pad; };
struct Ctx { char p[0x38]; float f38; char p3C[0xEF0 - 0x3C]; float mat[1]; };
extern "C" void func_00398210(void *, float, float);
extern "C" void func_0040A1A0(float *, float *, float) throw();
extern "C" void func_004A1638(int);
extern "C" void func_004A5BF8(int, int, void *);
extern "C" void func_004A5CC0(int, void *);
extern "C" void func_004AB040(int);

extern "C" void func_0040A1D0(char *self, Ctx *ctx) {
    float m[4];
    float inv = 1.0f / ctx->f38;
    func_0040A1A0(m, ctx->mat, inv);
    func_004A5CC0(0, m);
    Entry *e = (Entry *)self;
    int count = e->count;
    if (count > 0) {
        int id = 0x65;
        int i;
        for (i = 0; i < e->count; i++, id++) {
            func_004A1638(id);
            func_004A5BF8(id, 0xD, e[i].v0);
            func_0040A1A0(m, e[i].v1, inv);
            func_004A5BF8(id, 0, m);
            func_0040A1A0(m, e[i].v2, inv);
            func_004A5BF8(id, 1, m);
            func_0040A1A0(m, e[i].v3, inv);
            func_004A5BF8(id, 4, m);
        }
        for (; i < 8; i++) func_004AB040(id++);
    } else {
        func_00398210(ctx, *(float *)self, *(float *)(self + 4));
    }
}
