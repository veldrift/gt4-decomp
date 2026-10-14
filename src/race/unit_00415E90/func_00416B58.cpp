/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct V3 { f32 x, y, z; void set(f32 v) { x = v; y = v; z = v; } };
struct Obj {
    char pad0[0x210];
    f32 f210, f214, f218, f21C;
    f32 f220, f224, f228, f22C;
    s32 a230[2]; s32 b238[2]; s32 c240[2]; s32 d248[2]; s32 e250[2];
    char pad258[0x268 - 0x258];
    f32 f268, f26C, f270;
    char pad274[0x280 - 0x274];
    V3 v280; char p28C[4];
    V3 v290; char p29C[4];
    f32 f2A0, f2A4, f2A8, f2AC;
    V3 v2B0; char p2BC[4];
    V3 v2C0; char p2CC[4];
    f32 f2D0; s32 i2D4, i2D8; s32 f2DC[2]; s32 i2E4; char p2E8[8];
    V3 v2F0; char p2FC[4];
    V3 v300; char p30C[4];
    V3 v310; char p31C[4];
    f32 f320, f324, f328, f32C, f330, f334;
    char p338[8];
    V3 v340; char p34C[4];
    f32 f350;
};
extern "C" {
void func_00418EE0(void *);
void func_00416B58(Obj *o) {
    int i;
    func_00418EE0(o);
    o->f210 = 0.0f;
    f32 z = o->f210;
    o->f26C = 0x1.921fb4p-1f;
    o->f270 = -0x1.921fb4p-1f;
    o->f214 = z;
    o->f218 = z;
    o->f21C = z;
    o->f268 = z;
    o->v280.set(z);
    o->v290.set(z);
    o->f2A0 = z; o->f2A4 = z; o->f2A8 = z; o->f2AC = z;
    o->v2B0.set(z);
    o->v2C0.set(z);
    o->f2D0 = z;
    o->i2D4 = 0; o->i2D8 = 0; o->i2E4 = 0;
    o->v2F0.set(z);
    o->v300.set(z);
    o->v310.set(z);
    o->f320 = z; o->f324 = z; o->f328 = z; o->f32C = z; o->f330 = z; o->f334 = z;
    o->v340.set(z);
    o->f350 = z;
    o->f220 = -0x1.921fb4p+0f;
    o->f224 = 0x1.921fb4p+0f;
    o->f228 = -0x1.921fb4p+0f;
    o->f22C = 0x1.921fb4p+0f;
    for (i = 0; i < 2; i++) {
        o->a230[i] = 0;
        o->b238[i] = 0;
        o->c240[i] = 0;
        o->d248[i] = 0;
        o->e250[i] = 0;
        o->f2DC[i] = 0;
    }
}
}
