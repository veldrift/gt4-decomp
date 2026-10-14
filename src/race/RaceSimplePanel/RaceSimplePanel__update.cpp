typedef signed char s8;
typedef unsigned char u8;
struct Panel {
    char pad0[0x18];
    u8 u18;
    char pad19[5];
    s8 s1E;
    char pad1F;
    s8 s20;
    char pad21;
    s8 s22;
    char pad23;
    float f24;
    float f28;
};
struct Sub { char pad[0x18]; float f18; float f1C; };
struct Ind { char pad[0x40]; s8 s40; };
static inline void put(Ind *p, int v) { p->s40 = v; }
extern "C" void RaceDisplayObjectBase__update(void *);
extern "C" void RaceIndicator__virtual_09(void *, float) throw();
extern "C" void RaceShiftPositionDisplay__update(void *, float) throw();
extern "C" void RaceSuggestedGearDisplay__virtual_10(void *, float) throw();
extern "C" void RaceShiftTimingLampDisplay__update(void *, float) throw();
extern "C" void RaceABMonitor__update(void *) throw();
extern "C" void RaceSimplePanel__update(struct Panel *self, float dt) {
    RaceDisplayObjectBase__update((char *)self + 0xD0);
    if (self->u18 == 0) {
        Ind *a = (Ind *)((char *)self + 0x2BC);
        put(a, self->s1E);
        RaceIndicator__virtual_09(a, dt);
        Ind *b = (Ind *)((char *)self + 0x300);
        put(b, self->s22);
        RaceIndicator__virtual_09(b, dt);
        Ind *c = (Ind *)((char *)self + 0x344);
        put(c, self->s20);
        RaceIndicator__virtual_09(c, dt);
        RaceShiftPositionDisplay__update((char *)self + 0x124, dt);
        RaceSuggestedGearDisplay__virtual_10((char *)self + 0x17C, dt);
        RaceShiftTimingLampDisplay__update((char *)self + 0x1D4, dt);
        Sub *d = (Sub *)((char *)self + 0x210);
        d->f18 = self->f24;
        d->f1C = self->f28;
        RaceABMonitor__update(d);
    }
}
