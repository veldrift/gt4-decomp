struct VEntry { short delta; short index; int (*fn)(void *, int *); };
struct Obj { void *f0; };
struct RT {
    char pad0[0x64];
    char *f64;
    char pad68[0xCC8 - 0x68];
    int fCC8;
};
extern "C" void RaceTrainingBase__initialize(RT *) throw();
extern "C" void func_0038B8D8(RT *, char *);
extern "C" void func_003E0940(char *, int, int, int);
extern "C" void func_003E09D8(char *, RT *);
extern "C" void RaceDisplay__virtual_06(char *, int);

extern "C" void RaceTraining__initialize(RT *self) {
    int sp0;
    RaceTrainingBase__initialize(self);
    if ((unsigned)(self->fCC8 - 2) < 2)
        func_0038B8D8(self, 0);
    else
        func_0038B8D8(self, ((char *)self + 0x23938));
    VEntry *e = (VEntry *)(self->f64 + 0x300);
    int r = e->fn((char *)self + e->delta, &sp0);
    func_003E0940(((char *)self + 0x23938), r, sp0, 0);
    func_003E09D8(((char *)self + 0x23938), self);
    RaceDisplay__virtual_06((char *)self + 0x23F5C, 3);
}
