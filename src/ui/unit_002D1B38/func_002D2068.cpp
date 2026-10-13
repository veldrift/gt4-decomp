typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef float f32;

struct C {
    char pad0[4];
    s32 unk4;
    char pad8[4];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    void *unk20;
    void *unk24;
    void *unk28;
    void *unk2C;
    void *unk30;
};

extern "C" void func_0025B460(void *c, f32 x, f32 y);
extern "C" void func_0025B498(void *arg0, f32 *arg1, f32 *arg2);
extern "C" void func_0025B538(void *c, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);

extern "C" void func_002D2068(C *self, f32 *arg1, f32 fparg0, f32 fparg1) {
    f32 sz[2];

    if (self->unk20 != 0) {
        func_0025B498(self->unk20, sz, sz + 1);
        if (self->unk4 != 0) {
            void *t24 = self->unk24;
            self->unkC = fparg0;
            self->unk10 = arg1[2];
            self->unk14 = -arg1[0];
            if (t24 != 0) {
                func_0025B460(t24, 0.0f, 0.0f);
            }
            void *t28 = self->unk28;
            if (t28 != 0) {
                func_0025B460(t28, sz[0] - self->unk1C, 0.0f);
            }
            void *t2C = self->unk2C;
            if (t2C != 0) {
                func_0025B538(t2C, self->unk1C, 0.0f, sz[0] - (self->unk1C + self->unk1C), self->unk18);
            }
            void *t30 = self->unk30;
            if (t30 != 0) {
                func_0025B460(t30, self->unk1C, 0.0f);
            }
        } else {
            void *t24 = self->unk24;
            self->unkC = fparg1;
            self->unk10 = arg1[3];
            self->unk14 = -arg1[1];
            if (t24 != 0) {
                func_0025B460(t24, 0.0f, 0.0f);
            }
            void *t28 = self->unk28;
            if (t28 != 0) {
                func_0025B460(t28, 0.0f, sz[1] - self->unk1C);
            }
            void *t2C = self->unk2C;
            if (t2C != 0) {
                func_0025B538(t2C, 0.0f, self->unk1C, self->unk18, sz[1] - (self->unk1C + self->unk1C));
            }
            void *t30 = self->unk30;
            if (t30 != 0) {
                func_0025B460(t30, 0.0f, self->unk1C);
            }
        }
    }
}
