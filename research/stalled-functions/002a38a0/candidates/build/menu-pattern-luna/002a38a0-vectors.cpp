typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Vec2 {
    f32 x, y;
    void set(f32 a, f32 b) { x = a; y = b; }
};

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
    func_005769F0(D_00836D58);
    f32 inv_w = 1.0f / (f32)w;
    Vec2 upper_left, lower_left, upper_right, lower_right;
    upper_left.set(inv_w * (f32)self->ee, inv_h * (f32)self->ef);
    lower_left.set(inv_w * (f32)(self->ee + 1), inv_h * (f32)self->ef);
    upper_right.set(inv_w * (f32)self->ee, inv_h * (f32)(self->ef + 1));
    lower_right.set(inv_w * (f32)(self->ee + 1), inv_h * (f32)(self->ef + 1));
    self->cc = upper_left.x;
    self->d0 = upper_left.y;
    self->d4 = lower_left.x;
    self->d8 = lower_left.y;
    self->dc = lower_right.x;
    self->e0 = lower_right.y;
    self->e4 = upper_right.x;
    self->e8 = upper_right.y;
    func_00576A28(D_00836D58);
}
