/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blk { int w[24]; };
struct Src { char pad[0x50]; Blk b; };
struct Rep {
    char pad0[0xB0];
    Blk b;
    char pad1[0x130 - 0xB0 - 0x60 - 4];
    void *f12C;
    Src *f130;
};
extern char RaceReplayInformation__vtable[];
extern "C" int RaceInformation__structor_0(Rep *);
extern "C" void func_003BB478(Rep *, long);
extern "C" long RaceReplayInformation__getRaceCode(Rep *);

extern "C" void RaceReplayInformation__structor_0(Rep *self, Src *src) {
    RaceInformation__structor_0(self);
    self->f12C = RaceReplayInformation__vtable;
    self->f130 = src;
    func_003BB478(self, RaceReplayInformation__getRaceCode(self));
    self->b = src->b;
}
