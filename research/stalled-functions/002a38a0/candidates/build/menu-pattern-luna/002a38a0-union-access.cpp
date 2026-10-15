typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

union AnyWord { f32 f; s32 i; u32 u; };
struct Face {
    char pad0[0xCC];
    f32 cc, d0, d4, d8, dc, e0, e4, e8;
    u8 ec, ed, ee, ef;
};

extern "C" void func_005769F0(void *);
extern "C" void func_00576A28(void *);
extern char D_00836D58[];

extern "C" void func_002A38A0(Face *self) {
    u8 w = self->ec;
    if ((s32)(w - 1) < (s32)(u32)self->ee) self->ee = w - 1;
    u8 h = self->ed;
    if ((s32)(h - 1) < (s32)(u32)self->ef) self->ef = h - 1;
    f32 inv_h = 1.0f / (f32)h;
    f32 inv_w = 1.0f / (f32)w;
    func_005769F0(D_00836D58);

    f32 x0 = inv_w * (f32)self->ee;
    f32 y0 = inv_h * (f32)self->ef;
    f32 y1 = inv_h * (f32)(self->ef + 1);
    f32 x1 = inv_w * (f32)(self->ee + 1);
    AnyWord *out = (AnyWord *)&self->cc;
    out[0].f = x0;
    out[1].f = y0;
    out[6].f = x0;
    out[7].f = y1;
    out[2].f = x1;
    out[3].f = y0;
    out[4].f = x1;
    out[5].f = y1;
    func_00576A28(D_00836D58);
}
