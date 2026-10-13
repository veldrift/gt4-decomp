typedef int s32;
typedef unsigned char u8;

struct RacePS2Sub {
    char pad0[0xDC];
    s32 flag;
};

struct RacePS2Base {
    char pad0[0x64];
    char *vtbl;
    char pad1[0x4];
    RacePS2Sub *sub;
    char pad2[0xCD4 - 0x70];
    s32 f_cd4;
    char pad3[0xD80 - 0xCD8];
    s32 f_d80;
    char pad4[0xD8C - 0xD84];
    void (*f_d8c)(void *, s32);
    s32 f_d90;
    char pad5[0xCF5A - 0xD94];
    u8 f_cf5a;
    u8 f_cf5b;
    char pad6[0xCF60 - 0xCF5C];
    void *f_cf60;
};

struct VEntry2 {
    short delta;
    short index;
    void (*fn)(void *, void *);
};

struct VEntry3 {
    short delta;
    short index;
    void (*fn)(void *, void *, float);
};

extern "C" void func_00342400(void *arg);

extern "C" void func_0033D970(void *arg0, void *arg1) {
    RacePS2Base *self = (RacePS2Base *)arg0;
    void *a1 = arg1;
    RacePS2Sub *sub = self->sub;
    if (self->f_cd4 != 0 && sub->flag == 0) {
        if (self->f_d80 != 0) {
            s32 t = self->f_cf5b;
            if (t != 0) {
                if (t >= 0) {
                    if (t < 3) {
                        return func_00342400(self->f_cf60);
                    }
                }
            }
        }
        void (*fn)(void *, s32) = self->f_d8c;
        if (fn != 0) {
            fn(a1, self->f_d90);
        } else {
            VEntry3 *e0 = (VEntry3 *)(self->vtbl + 0x348);
            e0->fn((char *)self + e0->delta, a1, 0.0f);

            VEntry2 *e1 = (VEntry2 *)(self->vtbl + 0x350);
            e1->fn((char *)self + e1->delta, a1);

            self->f_cf5a = (u8)((self->f_cf5a << 1) | 1);
            VEntry2 *e2 = (VEntry2 *)(self->vtbl + 0x358);
            e2->fn((char *)self + e2->delta, a1);

            VEntry2 *e3 = (VEntry2 *)(self->vtbl + 0x360);
            e3->fn((char *)self + e3->delta, a1);
        }
    }
}
