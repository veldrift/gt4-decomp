/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Pt { char pad[8]; f32 f8; };

struct Slider {
    char pad0[0xC4];
    Slider *unkC4;
    char padC8[4];
    s32 unkCC;
    char padD0[0xE0 - 0xD0];
    s32 unkE0;
    s32 unkE4;
    char padE8[4];
    Pt unkEC;
    s32 unkF8;
    Slider *unkFC;
    Slider *unk100;
    s32 unk104;
    char pad108[4];
    s32 unk10C;
};

extern "C" void mWidget__virtual_70(void *, s32, s32);
extern "C" s32 func_00265DC8(void *);
extern "C" f32 mWidget__getWindowW(void *);
extern "C" f32 mWidget__getWindowH(void *);
extern "C" void mWidget__setWindowX(void *, f32);
extern "C" void mWidget__setWindowY(void *, f32);
extern "C" void func_0057B0F8(void *, f32, f32);

extern "C" void mSliderBar__virtual_70(Slider *self, s32 a1, s32 a2) {
    mWidget__virtual_70(self, a1, 0);
    if (a2 != 0 && func_00265DC8(self) != 0 && self->unkFC != 0) {
        Slider *a = self;
        if (self->unk10C != 0) {
            Slider *t = self->unkC4;
            a = t ? t : self;
        }
        f32 fa, fb;
        if (self->unk104 == 0) {
            fa = mWidget__getWindowW(a);
            fb = mWidget__getWindowW(self->unkFC);
        } else {
            fa = mWidget__getWindowH(a);
            fb = mWidget__getWindowH(self->unkFC);
        }
        s32 base = self->unkE0;
        Pt *p = &self->unkEC;
        s32 n = self->unkE4 - base;
        func_0057B0F8(p, (f32)self->unkCC, 0x1.999998p-2f);
        f32 pf = p->f8;
        f32 pos = 0.0f;
        if (n > 0)
            pos += ((fa - fb) / (f32)n) * (pf - (f32)base);
        if (self->unk104 == 0)
            mWidget__setWindowX(self->unkFC, pos);
        else
            mWidget__setWindowY(self->unkFC, pos);
        Slider *o = self->unk100;
        if (o != 0) {
            f32 pos2 = 0.0f;
            if (n >= 2)
                pos2 += ((fa - fb) / (f32)(n - 1)) * (f32)(self->unkF8 - base);
            if (self->unk104 == 0)
                return mWidget__setWindowX(o, pos2);
            mWidget__setWindowY(o, pos2);
        }
    }
}
