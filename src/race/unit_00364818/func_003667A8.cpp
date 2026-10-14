/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef float f32;

struct Slot {
    f32 f0;
    char pad4[0x1C];
    f32 f20;
    char pad24[4];
    f32 f28;
    char pad2C[0xC];
    f32 f38;
    char pad3C[0x4D];
    u8 b89;
    char pad8A[0x32];
    f32 fBC;
    char padC0[0x2C];
};
struct R {
    char pad0[0x14];
    f32 f14;
    char pad18[0x1B];
    u8 b33;
};
struct T { f32 f[13]; };
struct Win {
    char pad0[0x440];
    u8 b440;
    char pad441[0x12F];
    f32 f570;
};
struct Car {
    char pad0[8];
    void *obj;
};
struct Vec3 { f32 x, y, z; };
struct Frame {
    int idx;
    int b;
    f32 x;
    T t;
};

extern "C" void func_00395C70(void *, void *, int);
extern "C" void func_00395C98(void *, void *, Vec3 *);

extern "C" void func_003667A8(Car *self, int idx, Vec3 *pos, Vec3 *arg3) {
    Frame fr;
    Slot *slot = (Slot *)((char *)self + 0x164) + idx;
    Win *w = (Win *)((char *)self + 0x104);
    R *r = (R *)((char *)self + 0x7B8 + idx * 0x34);
    T *src = (T *)((char *)self + 0x7C4 + idx * 0x34);
    fr.idx = idx;
    fr.b = slot->b89;
    fr.t.f[3] = r->f14;
    fr.t.f[8] = slot->fBC;
    fr.t.f[2] = w->f570 + slot->f0;
    fr.x = pos->x;
    fr.t.f[0] = pos->y;
    fr.t.f[1] = pos->z;
    T *dst = &fr.t;
    for (int i = 0; i < 4; i++)
        dst->f[i + 4] = src->f[i + 4];
    fr.t.f[9] = slot->f38;
    fr.t.f[10] = slot->f28;
    fr.t.f[11] = slot->f20;
    fr.t.f[7] = fr.t.f[7] - fr.t.f[5] * 0.05f;
    func_00395C70(self->obj, &fr, w->b440);
    if (r->b33 & 0x20)
        func_00395C98(self->obj, &fr, arg3);
}
