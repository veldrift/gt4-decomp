/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
typedef long long s64;

struct Src { char pad[0x10]; s32 m10; };
struct Obj {
    char pad00[8];
    f32 m8;
    f32 mC;
    char pad0[0xE8 - 0x10];
    s32 mE8;
    char pad1[0x148 - 0xEC];
    s32 m148;
    char pad2[0x168 - 0x14C];
    s64 m168;
    char pad3[0x184 - 0x170];
    f32 m184;
    f32 m188;
    s32 m18C;
    char pad4[0x234 - 0x190];
    s32 m234;
    char pad5[0x260 - 0x238];
    s64 m260;
    s64 m268;
    s32 m270;
    s32 m274;
    s32 m278;
    s32 m27C;
};

extern "C" void func_00378CB8(void *) throw();
extern "C" void func_0037BC20(void *, s32);
extern "C" void func_00384A60(void *);
extern "C" void func_00384B60(void *, float, float);
extern "C" void func_00385058(void *, f32, f32, f32, f32, f32, f32, f32);
extern "C" void func_00385390(void *, float, float);

#define B8(k) (0xFFLL << (k))

extern "C" void func_00379CE0(Obj *self, Src *src, s32 arg2) {
    func_00378CB8(self);
    s64 t0 = self->m260;
    s64 t1 = t0 & ~B8(32);
    s64 t = t1 & ~B8(40);
    self->m260 = t;
    s64 w0 = self->m268;
    s64 w1 = w0 & ~B8(0);
    s64 w2 = w1 & ~B8(8);
    s64 w3 = w2 & ~B8(16);
    s64 w4 = w3 | (1LL << 16);
    s64 w5 = w4 & ~B8(24);
    s64 w6 = w5 & ~B8(32);
    s64 w7 = w6 & ~B8(40);
    s64 w = w7 | (0x8000LL << 25);
    self->m148 = 1;
    self->m268 = w;
    self->m270 = 0;
    self->m274 = 0;
    self->m278 = 0;
    self->m234 = 0;
    self->m18C = src->m10;
    self->m8 = 100.0f;
    self->mC = self->m184;
    s64 u = *(volatile s64 *)&self->m260;
    u = u & ~B8(48);
    u = u & ~B8(56);
    self->m260 = u;
    self->m188 = 60.0f;
    func_0037BC20(self, arg2);
    self->m168 = self->m168 & ~B8(24);
    self->mE8 = 1;
    self->m27C = 0;
    func_00385058((char *)self + 0x190, 0.0f, 60.0f, -20.0f, 1.0f, 8.0f, 35.0f, 35.0f);
    func_00384A60((char *)self + 0x1B8);
    func_00384A60((char *)self + 0x1C4);
    func_00384B60((char *)self + 0x1D0, 0.0f, 0.0f);
    func_00384B60((char *)self + 0x1DC, 0.0f, 0.0f);
    func_00385390((char *)self + 0x20C, 0.0f, 0.0f);
    func_00385390((char *)self + 0x218, 0.0f, 0.0f);
    func_00385390((char *)self + 0x224, 0.0f, 0.0f);
    func_00385390((char *)self + 0x1E8, 0.0f, 0.0f);
    func_00385390((char *)self + 0x1F4, 0.0f, 0.0f);
    func_00385390((char *)self + 0x200, 0.0f, 0.0f);
}
