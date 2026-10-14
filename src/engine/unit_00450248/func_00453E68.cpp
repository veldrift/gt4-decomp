/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Inner {
    char pad0[0x20];
    s32 f20;
};
struct Item { f32 v; char pad[0x34]; };
struct Ctx {
    Inner *p0;
    char pad4[0xB8 - 4];
    Item items[1];
};
struct Ctx2 {
    char pad[0x5B8];
    s32 f5B8;
};
struct Obj10 {
    char pad[8];
    s32 f8;
};
struct Obj {
    s32 f0;
    Ctx *ctx;
    s32 mode;
    s32 *pC;
    Obj10 *p10;
    s32 *p14;
    s32 f18;
    s32 f1C;
    f32 f20;
    s32 idx;
};

extern "C" void GSBuffer__getTexture(s32 *, void *);
extern "C" void func_00107BE8(void *, void *);
extern "C" void func_00453BB0(s32 *, s32, s32, f32) throw();
extern "C" s32 func_00454EF8(s32, s32, s32);
extern "C" void ModelSet2__registerExternalTexSet(s32, s32);
extern "C" void func_0057D9C0(const char *, ...);

static inline s32 getTex(Ctx *c) {
    Inner *p = c->p0;
    if (p == 0) return 0;
    s32 t = ((Ctx2 *)c)->f5B8;
    if (t != 0) return t;
    return p->f20;
}

extern "C" s32 func_00453E68(Obj *self, s32 arg1) {
    Ctx *c = self->ctx;
    s32 a0 = getTex(c);
    if (a0 == 0) return 0;
    {
        char *entry = (char *)c + self->idx * 0x38;
        f32 ang = (*(f32 *)(entry + 0xB8) * 0x1.921fb4p+1f) / 180.0f;
        if (ang < 0.0f) {
            ang = -ang;
        }
        s32 mode = self->mode;
        s32 v = arg1;
        if (mode == 1) {
            if (ang > 0x1.657182p-4f) {
                v += 1;
            }
            mode = 0;
        }
        s32 r = func_00454EF8(a0, v, 0);
        if (r == 0) {
            func_0057D9C0("no texture. tag = %d, blurLevel = %d, texnum = %d", arg1, mode, v);
        } else {
            s32 old = self->f1C;
            if (mode == 0) {
                if (old != r || self->f18 == 1) {
                    func_00107BE8(self->p10, (void *)r);
                }
                ModelSet2__registerExternalTexSet(2, self->p10->f8);
                self->f18 = 0;
            } else {
                if (old != r || ang != self->f20 || self->f18 == 0) {
                    self->f20 = ang;
                    func_00453BB0(self->pC, r, mode, ang);
                }
                GSBuffer__getTexture(self->pC, self->p14);
                ModelSet2__registerExternalTexSet(2, (s32)self->p14);
                self->f18 = 1;
            }
            self->f1C = r;
        }
    }
    return 0;
}
