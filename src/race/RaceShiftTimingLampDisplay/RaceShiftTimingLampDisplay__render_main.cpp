typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef short s16;
struct VEntry { s16 delta; s16 index; void (*fn)(void *); };
struct Lamp {
    char pad0[1];
    u8 b1;
    u8 b2;
    char pad3;
    s16 s4;
    s16 s6;
    char pad8[4];
    float fC;
    void *p10;
    char *vtbl;
    char pad18[4];
    float f1C;
};
extern "C" s32 RaceDisplayUtil__getScaledColor(u32, float, float);
extern "C" void func_004AA168(s32);
extern "C" void func_003AEF18(void *, float, float, u32, u32);
extern "C" void RaceShiftTimingLampDisplay__render_main(struct Lamp *self) {
    if (self->p10 == 0) {
        VEntry *e = (VEntry *)(self->vtbl + 0x50);
        e->fn((char *)self + e->delta);
    }
    func_004AA168(RaceDisplayUtil__getScaledColor(0x800000FF, self->f1C * 1.5f, self->fC));
    func_003AEF18(self->p10, (float)self->s4, (float)self->s6, self->b1, self->b2);
}
