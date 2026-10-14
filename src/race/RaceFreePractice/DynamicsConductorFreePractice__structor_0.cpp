/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

extern char RaceFreePractice__vtable[];
extern char DynamicsConductorFreePractice__vtable[];

struct Slot { char b[8]; };
struct Res { char b[0x4F8]; };
struct Obj {
    char pad0[0x64];
    char *vt;
    char pad1[0x125C0 - 0x68];
    char blk[0x22708 - 0x125C0];
    Slot slots[6];
    Res res;

};

extern "C" void DynamicsConductor__structor_1(void *, s32);
extern "C" void func_00393738(void *, int);
extern "C" void RacePause__structor_1(void *, int);
extern "C" void RaceSinglePlayer__structor_1(void *, s32);
extern "C" void RaceFuelMeter__structor_2(void *, int);
extern "C" void func_005C1628(void *) throw();

extern "C" void DynamicsConductorFreePractice__structor_0(Obj *self, s32 flags) {
    Slot *arr = self->slots;
    self->vt = RaceFreePractice__vtable;
    RaceFuelMeter__structor_2((char *)self + 0x22770, 2);
    RacePause__structor_1((char *)self + 0x22738, 2);
    if (arr != 0) {
        Slot *p = arr + 6;
        if (arr != p) {
            do {
                p--;
                func_00393738(p, 2);
            } while (arr != p);
        }
    }
    char *q = (char *)self + 0x125C0;
    *(char **)(q + 0x10140) = DynamicsConductorFreePractice__vtable;
    DynamicsConductor__structor_1(q, 0);
    RaceSinglePlayer__structor_1(self, 0);
    if ((flags & 1) == 0) return;
    return func_005C1628(self);
}
