/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Sub { char pad[0xC]; f32 mC; };
struct E1 { short d; short i; void (*fn)(void *, s32); };
struct E0 { short d; short i; void (*fn)(void *); };
struct EP { short d; short i; void (*fn)(void *, Sub *); };
struct E4 { short d; short i; void (*fn)(void *, f32, f32, f32, f32); };
struct VT {
    char pad[0x198];
    EP e198;
    E4 e1A0;
    char pad2[0x1C0 - 0x1A8];
    E1 e1C0;
    char pad3[0x1D8 - 0x1C8];
    E0 e1D8;
};
struct Dev { s32 x; VT *vt; };
struct Self {
    char pad[0x18];
    s32 state;
    char pad1C[4];
    f32 m20;
    f32 m24;
    Sub sub;
};

extern "C" s32 func_0024D1B0(Self *);
extern "C" void func_0024D2D8(Self *);

extern "C" void mColorTransition__end(Self *self, Dev *dev) {
    if (func_0024D1B0(self) != 0) {
        switch (self->state) {
        case 0: {
            f32 f = self->m20 + self->m24;
            self->m20 = f;
            if (f > 1.0f) {
                self->m20 = 1.0f;
                func_0024D2D8(self);
            }
            break;
        }
        case 2: {
            f32 f = self->m20 - self->m24;
            self->m20 = f;
            if (f < 0.0f) {
                self->m20 = 0.0f;
                func_0024D2D8(self);
            }
            break;
        }
        case 1:
            break;
        case 3:
            return;
        default:
            break;
        }
        f32 cur = self->m20;
        f32 zero = 0.0f;
        if (cur > zero) {
            Sub *sub = &self->sub;
            sub->mC = cur;
            E1 *a = &dev->vt->e1C0;
            a->fn((char *)dev + a->d, 0);
            E0 *b = &dev->vt->e1D8;
            b->fn((char *)dev + b->d);
            EP *c = &dev->vt->e198;
            c->fn((char *)dev + c->d, sub);
            E4 *d = &dev->vt->e1A0;
            d->fn((char *)dev + d->d, zero, zero, 640.0f, 480.0f);
        }
    }
}
