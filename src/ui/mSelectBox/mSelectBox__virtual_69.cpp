/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct mSelectBox {
    char pad0[0xBC];
    s32 unkBC;
    char padC0[0x10];
    f32 unkD0;
    f32 unkD4;
    char padD8[0xC];
    f32 unkE4;
    f32 unkE8;
    f32 unkEC;
};
extern "C" s32 func_00206868(void *);
extern "C" void mWidget__getWindowSize(void *, f32 *, f32 *);
extern "C" void func_0025B4C8(void *, f32, f32);
extern "C" void *func_0025C300(void *);
extern "C" void mColorChipFace__virtual_69(mSelectBox *, s32, s32);
extern "C" f32 func_002DA2B0(mSelectBox *) throw();

extern "C" void mSelectBox__virtual_69(mSelectBox *self, s32 arg1) {
    f32 sp[2];
    s32 i;
    void *w;
    f32 a, b;
    mColorChipFace__virtual_69(self, arg1, 0);
    if (self->unkD4 != 1.0f) {
        i = 0;
        w = (void *)func_00206868(self);
        if (w != 0) {
            s32 *pBC = &self->unkBC;
            do {
                a = self->unkE4;
                b = self->unkE8;
                if (i == *pBC) {
                    a *= self->unkD4;
                    b *= self->unkD4;
                }
                i++;
                mWidget__getWindowSize(w, &sp[0], &sp[1]);
                f32 r = self->unkD0;
                func_0025B4C8(w, sp[0] + (a - sp[0]) * r, sp[1] + (b - sp[1]) * r);
                w = func_0025C300(w);
            } while (w != 0);
        }
    }
    f32 t = func_002DA2B0(self);
    f32 d = t - self->unkEC;
    d *= self->unkD0;
    if (d >= -0.1f && d <= 0.1f) {
        self->unkEC = t;
    } else {
        f32 r;
        if (d < -self->unkE8) r = t - self->unkE8;
        else if (self->unkE8 < d) r = t + self->unkE8;
        else r = self->unkEC + d;
        self->unkEC = r;
    }
}
