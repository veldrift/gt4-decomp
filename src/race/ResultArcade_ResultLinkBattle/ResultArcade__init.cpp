/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned int u32;

struct Obj10 { char pad[0x10]; s32 f10; };
struct VEnt { s16 delta; s16 pad; s32 (*fn)(void *); };
struct VT { char pad[0x70]; VEnt e70; VEnt e78; };
struct Ent { char pad[0xC0]; };
struct Cnt { s32 n; };
struct Sub { char pad[0x70]; void *f70; };
struct Org { char pad[0x60]; Cnt *f60; char pad64[0x20]; Sub *f84; };
struct Self {
    char pad0[0xC]; VT *vt;
    s32 f10;
    s32 a14[6];
    s32 a2C[6];
    s32 f44; s32 f48; char pad4C[4];
    s32 f50; s32 f54; s32 f58; Obj10 *f5C;
    char pad60[8];
    Ent ent[6];
    char padEnd[0x4F0 - 0x68 - 6 * 0xC0];
    s32 f4F0; s32 f4F4; Org *f4F8; s32 f4FC;
};

extern "C" void func_003E0530(void *);
extern "C" void RaceResultBase__init(void *, void *, u32);
extern "C" s32 DynamicsConductor__getLimitTime(void *);
extern "C" void func_00474F38(void *, s32, s32, s32);
extern "C" void func_00475D78(void *, s32, void *);
extern "C" void func_00475D88(void *, s32, void *);
extern "C" void *exception__structor_0(s32);

extern "C" void ResultArcade__init(Self *self, Org *org, u32 mode) {
    RaceResultBase__init(self, org, mode);
    self->f4F8 = org;
    self->f4F0 = 0;
    self->f4F4 = org->f60->n;
    self->f10 = mode < 2;
    self->f4FC = 0;
    self->f50 = 0;
    if (DynamicsConductor__getLimitTime(org->f84->f70) != 0) {
        self->f50 = 1;
    }
    for (s32 i = 0; i < self->f4F4; i++) {
        self->a14[i] = 0;
        self->a2C[i] = 0;
        func_003E0530(&self->ent[i]);
    }
    self->f44 = 0;
    self->f48 = 0;
    if (self->f58 != 0) {
        void *o = exception__structor_0(0x19C);
        func_00474F38(o, self->f58, 0, self->f54);
        self->f5C = (Obj10 *)o;
        VEnt *e = &self->vt->e70;
        func_00475D78(self->f5C, e->fn((char *)self + e->delta), self);
        VEnt *e2 = &self->vt->e78;
        func_00475D88(self->f5C, e2->fn((char *)self + e2->delta), self);
        self->f5C->f10 = 1;
    }
}
