/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *); };
struct Obj { char pad[0x64]; VEntry *vtbl; };
extern "C" int AutomobileControlRecord__Manager__copyNormal(void *, void *);
extern "C" void func_003EA768(void *);
extern "C" void RaceSolitaire__updateToLogger(Obj *self) {
    char *ghost = (char *)self + 0xe84c;
    VEntry *e = (VEntry *)((char *)self->vtbl + 0x4d0);
    e->fn((char *)self + e->delta);
    AutomobileControlRecord__Manager__copyNormal((char *)self + 0xe920, (char *)self + 0xe560);
    *(int *)(ghost + 0x1d0) = 0;
    func_003EA768(self);
}
