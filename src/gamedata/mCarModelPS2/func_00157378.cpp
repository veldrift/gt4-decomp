/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Child {
    char pad0[0x38];
    void *p38;
    void *p3C;
    f32 f40;
    f32 f44;
    f32 f48;
    f32 f4C;
    f32 f50;
    f32 f54;
    f32 f58;
    char pad5C[0x1AC - 0x5C];
    f32 f1AC;
};

struct Tgt {
    char pad0[0xC];
    f32 fC;
};

struct Obj {
    char pad0[0x2C];
    f32 f2C;
    f32 f30;
    f32 f34;
    f32 f38;
    char pad3C[0x44 - 0x3C];
    f32 f44;
    f32 f48;
    f32 f4C;
    char pad50[0x164 - 0x50];
    char f164[0x178 - 0x164];
    char f178[0x10];
    s32 f188;
    char f18C[0x14];
    char f1A0[0x14];
    char pad1B4[0x2A4 - 0x1B4];
    char f2A4[0x860 - 0x2A4];
    s32 f860;
    char pad864[0x864 - 0x864];
    char f864[0x870 - 0x864];
    Tgt *f870;
    char pad874[0x8AC - 0x874];
    Child f8AC;
};

extern "C" void func_00154BB8(void *) throw();
extern "C" void func_00154CA8(void *, s32) throw();
extern "C" s32 func_00156660(Obj *) throw();
extern "C" void func_001574E8(Obj *);
extern "C" void func_001D5B88(void *, f32);
extern "C" void func_001D5C00(void *, s32);

static inline void setPosition(Child *p, float x, float y, float z) { p->f40=x; p->f44=y; p->f48=z; }
static inline void setRotation(Child *p, float x, float y, float z) { p->f4C=x; p->f50=y; p->f54=z; }

extern "C" void func_00157378(Obj *self, s32 unused, s32 arg2) {
    Child *c = &self->f8AC;
    func_001D5B88(c, 0x1.111110p-6f);
    if (func_00156660(self) != 0) {
        f32 v = 0.0f;
        c->p38 = self->f2A4;
        c->p3C = self->f864;
        setPosition(c, self->f2C, self->f30, -self->f34);
        setRotation(c, self->f38, self->f44 + 180.0f, self->f48);
        c->f58 = self->f4C;
        if (self->f870 != 0) {
            v = self->f870->fC;
        }
        c->f1AC = v;
    } else {
        c->p38 = 0;
        c->p3C = 0;
    }
    func_001D5C00(c, arg2);
    if (func_00156660(self) != 0) {
        func_00154CA8(self->f164, 0);
        if (self->f188 != 0) {
            func_00154CA8(self->f178, 1);
        } else {
            func_00154BB8(self->f178);
        }
        if (self->f860 != 0) {
            func_00154CA8(self->f18C, 1);
        } else {
            func_00154BB8(self->f18C);
        }
        func_00154CA8(self->f1A0, 1);
        return;
    }
    func_001574E8(self);
}
