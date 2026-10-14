/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

extern char RaceArcade__vtable[];
extern char DynamicsConductorSinglePlayer__vtable[];

struct Slot { char b[8]; };
struct Res { char b[0x4F8]; };
struct Obj {
    char pad0[0x64];
    char *vt;
    char pad1[0x125C0 - 0x68];
    char blk[0x22708 - 0x125C0];
    Slot slots[6];
    Res res;
    char pad2[0x22C38 - 0x22738 - 0x4F8];
    char pause[0x38];
    char meter[0x23FB0 - 0x22C70];
};

extern "C" void DynamicsConductor__structor_1(void *, s32);
extern "C" void func_00393738(void *, int);
extern "C" void RacePause__structor_1(void *, int);
extern "C" void RaceSinglePlayer__structor_1(void *, s32);
extern "C" void RaceFuelMeter__structor_2(void *, int);
extern "C" void func_003DCA80(void *, int);
extern "C" void RaceResultBase__structor_0(void *, int);
extern "C" void func_005C1628(void *) throw();

extern "C" void DynamicsConductorSinglePlayer__structor_2(Obj *self, s32 flags) {
    Slot *arr = self->slots;
    self->vt = RaceArcade__vtable;
    func_003DCA80((char *)self + 0x23FB0, 2);
    RaceFuelMeter__structor_2((char *)self + 0x22C70, 2);
    RacePause__structor_1((char *)self + 0x22C38, 2);
    RaceResultBase__structor_0((char *)self + 0x22738, 2);
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
    *(char **)(q + 0x10140) = DynamicsConductorSinglePlayer__vtable;
    DynamicsConductor__structor_1(q, 0);
    RaceSinglePlayer__structor_1(self, 0);
    if ((flags & 1) == 0) return;
    return func_005C1628(self);
}
