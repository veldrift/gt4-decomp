typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Vec2 { f32 x, y; };
struct Face {
    char pad0[0xCC];
    Vec2 texcoord[4];
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

    f32 u0 = inv_w * (f32)self->ee;
    f32 v0 = inv_h * (f32)self->ef;
    f32 v1 = inv_h * (f32)(self->ef + 1);
    f32 u1 = inv_w * (f32)(self->ee + 1);
    self->texcoord[0].x = u0;
    self->texcoord[0].y = v0;
    self->texcoord[3].x = u0;
    self->texcoord[3].y = v1;
    self->texcoord[1].x = u1;
    self->texcoord[1].y = v0;
    self->texcoord[2].x = u1;
    self->texcoord[2].y = v1;
    func_00576A28(D_00836D58);
}
