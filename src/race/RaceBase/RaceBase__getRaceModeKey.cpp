/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; int (*fn)(void *, int *); };
struct Obj { char pad[0x64]; VEntry *vtbl; };
extern "C" int RaceBase__getRaceModeKeyString(int);
extern "C" int RaceBase__getRaceModeKey(Obj *self, int *mode) {
    *mode = -1;
    VEntry *e = (VEntry *)((char *)self->vtbl + 0x2F8);
    return RaceBase__getRaceModeKeyString(e->fn((char *)self + e->delta, mode));
}
