typedef int s32;

extern char RaceMachineTest__vtable[];
extern char DynamicsConductorMachineTest__vtable[];

struct Slot { char b[8]; };
struct Obj {
    char pad0[0x64];
    char *vt;
    char pad1[0xF140 - 0x68];
    Slot slots[6];
};

extern "C" void DynamicsConductor__structor_1(void *, s32);
extern "C" void func_00393738(void *, int);
extern "C" void RaceABMonitor__structor_0(void *, int);
extern "C" void RacePause__structor_1(void *, int);
extern "C" void RaceResultBase__structor_0(void *, int);
extern "C" void RaceSolitaire__structor_1(void *, s32);
extern "C" void func_005C1628(void *) throw();

extern "C" void DynamicsConductorMachineTest__structor_0(Obj *self, s32 flags) {
    char *q = (char *)self + 0x135D8;
    Slot *arr = self->slots;
    self->vt = RaceMachineTest__vtable;
    *(char **)(q + 0x10140) = DynamicsConductorMachineTest__vtable;
    DynamicsConductor__structor_1(q, 0);
    RaceABMonitor__structor_0((char *)self + 0xF6A8, 2);
    RaceResultBase__structor_0((char *)self + 0xF1A8, 2);
    RacePause__structor_1((char *)self + 0xF170, 2);
    if (arr != 0) {
        Slot *p = arr + 6;
        if (arr != p) {
            do {
                p--;
                func_00393738(p, 2);
            } while (arr != p);
        }
    }
    RaceSolitaire__structor_1(self, 0);
    if ((flags & 1) == 0) return;
    return func_005C1628(self);
}
