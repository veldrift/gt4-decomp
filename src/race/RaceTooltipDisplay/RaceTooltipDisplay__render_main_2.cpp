/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned int u32;
typedef float f32;

struct Sub { char pad[0xC]; f32 fC; };
struct Self {
    char pad0[4];
    s16 s4;
    s16 s6;
    s16 s8;
    s16 sA;
    f32 fC;
    char pad10[0x1C - 0x10];
    f32 f1C;
    f32 f20;
};

extern "C" void RaceMessageDisplay__render_main(void *) throw();
extern "C" void RaceEventDisplay__render_main(void *) throw();
extern "C" void RaceDisplayObjectBase__setLocation(void *, s32, s32);
extern "C" void RaceMiniMap__virtual_07(void *, s32, s32);
extern "C" void RaceDisplayUtil__fillRectangle(f32, f32, f32, f32);
extern "C" s32 func_003AFEC8(u32, f32);
extern "C" void func_004AA168(s32);

extern "C" void RaceTooltipDisplay__render_main_2(Self *self) {
    s32 ok = self->f1C > 0.0f;
    if (ok) {
        f32 f = self->fC;
        if (!(f <= 0.0f)) {
            Sub *s1 = (Sub *)((char *)self + 0x3C);
            Sub *s2 = (Sub *)((char *)self + 0x18C);
            func_004AA168(func_003AFEC8(0x80000000, f));
            f32 y = (f32)self->s6;
            f32 y2 = y - self->f1C * (f32)self->sA;
            RaceDisplayUtil__fillRectangle((f32)self->s4, y, (f32)self->s8, y2);
            f32 a = self->f20;
            s32 s0 = (s32)y2 + 0x16;
            f32 b = self->fC;
            s1->fC = b * a;
            RaceDisplayObjectBase__setLocation(s1, self->s4 + (self->s8 >> 1), s0);
            RaceMiniMap__virtual_07(s1, (self->s8 * 15) >> 4, 0);
            RaceMessageDisplay__render_main(s1);
            s2->fC = self->fC;
            RaceDisplayObjectBase__setLocation(s2, self->s4 + (self->s8 >> 1), s0);
            RaceMiniMap__virtual_07(s2, (self->s8 * 15) >> 4, 0);
            RaceEventDisplay__render_main(s2);
        }
    }
}
