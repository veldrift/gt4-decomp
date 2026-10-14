/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Inner { char pad[0xBC]; s32 bc; };
struct Disp { char pad[0x18]; f32 f18; f32 f1c; unsigned color; };
struct RD {
    char pad0[4];
    Inner *p4;
    char pad8[8];
    s32 p10;
    char pad14[0x2F - 0x14];
    signed char id2F;
    char pad30[0xBC - 0x30];
    f32 bc;
    char padC0[0x252C - 0xC0];
    Disp d;
};

extern "C" s32 RaceDisplay__is_play_mode(RD *);
extern "C" s32 DynamicsConductor__GetCountDown(s32, s32);
extern "C" void func_0057DA20(char *, const char *, ...);
extern "C" char *RaceDisplay__get_race_signal_font(RD *);
extern "C" void RaceMessageDisplay__setMessage(Disp *, char *, f32, f32);
extern "C" void RaceMessageDisplay__setFont(Disp *, char *, s32);
extern char D_006A0620[];

static inline f32 zero() { return 0.0f; }

extern "C" void func_0039D390(RD *self) {
    char buf[16];
    if (RaceDisplay__is_play_mode(self)) {
        Inner *in = self->p4;
        s32 v = DynamicsConductor__GetCountDown(self->p10, self->id2F);
        s32 changed = v != in->bc;
        s32 rem = v % 60;
        s32 secs = v / 60;
        if (rem == 1 && secs > 0) {
            func_0057DA20(buf, D_006A0620, secs);
            char *font = RaceDisplay__get_race_signal_font(self);
            if (secs < 4) {
                f32 z = zero();
                Disp *d = &self->d;
                d->f18 = z;
                d->f1c = 0x1.333332p-3f;
                RaceMessageDisplay__setMessage(d, buf, 0x1.999998p-1f, z);
                d->color = 0x80C8C8C8;
                RaceMessageDisplay__setFont(d, font, 0);
            } else if (changed && self->bc >= 1.0f) {
                f32 z = zero();
                Disp *d = &self->d;
                d->f18 = z;
                d->f1c = z;
                RaceMessageDisplay__setMessage(d, buf, 1.0f, z);
                d->color = 0x80C8C8C8;
                RaceMessageDisplay__setFont(d, font, 0);
            }
        }
    }
}
