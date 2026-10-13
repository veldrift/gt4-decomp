typedef int s32;
typedef float f32;

union F32I {
    f32 f;
    s32 i;
};

struct mBlinkActor {
    char pad0[0x14];
    char *unk14;
    F32I unk18;
    char pad1C[4];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
};

struct VE {
    short delta;
    short index;
    void (*fn)(void *, f32);
};

static inline void vcall(char *o, s32 off, f32 f) {
    VE *e = (VE *)(*(char **)(o + 4) + off);
    e->fn(o + e->delta, f);
}

extern "C" void func_00279908(void *arg0) {
    mBlinkActor *self = (mBlinkActor *)arg0;
    f32 zero = 0.0f;
    f32 f2 = self->unk18.f;
    f32 f1 = self->unk30;
    f32 f3;
    f32 f12;
    f32 f0;
    s32 v0;

    f2 = f2 + f1;
    self->unk18.f = f2;
    if (zero < f1) {
        f3 = self->unk34;
        v0 = f3 <= f2;
    } else {
        f3 = self->unk34;
        v0 = f2 <= f3;
    }
    if (v0 != 0) {
        if (self->unk24 != 0) {
            self->unk18.i = 0;
            self->unk20 = self->unk20 + 1;
        } else {
            self->unk18.f = f3;
        }
    }

    f12 = self->unk18.f;
    if (self->unk28 == 0) {
        f12 = f3 - f12;
    }
    if (self->unk2C == 0) {
        f1 = self->unk38;
    } else {
        if (self->unk20 & 1) {
            f12 = f3 - f12;
        }
        f1 = self->unk38;
    }

    f32 z2 = 0.0f;
    if (f1 != z2) {
        f12 = (f12 * (f3 - f1)) / f3 + f1;
    }

    f0 = self->unk3C;
    if (f0 != z2) {
        f32 one = 1.0f;
        if (f0 <= one) {
            if (f3 * f0 < f12) {
                f12 = f3;
            } else {
                f12 = z2;
            }
        } else {
            f0 = f0 - one;
            f12 = f12 / f0;
            if (f3 <= f12) {
                f12 = f3;
            }
        }
    }

    vcall((char *)self->unk14, 0x1D0, f12);
}
