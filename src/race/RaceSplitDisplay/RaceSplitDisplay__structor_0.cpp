/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Display { char pad[0x2D]; signed char index; char tail[0x3F30-0x2E]; };
struct Self { void *vt; int field4; Display displays[2]; };
extern char RaceSplitDisplay__vtable[];
extern "C" int RaceSplitDisplayBase__structor_0(Self *) throw();
extern "C" int RaceDisplay__structor_0(Display *);
extern "C" void RaceSplitDisplay__structor_0(Self *self) {
    RaceSplitDisplayBase__structor_0(self);
    self->vt = RaceSplitDisplay__vtable;
    RaceDisplay__structor_0(&self->displays[0]);
    RaceDisplay__structor_0(&self->displays[1]);
    for (int i = 1; i >= 0; i--) self->displays[i].index = i;
}
