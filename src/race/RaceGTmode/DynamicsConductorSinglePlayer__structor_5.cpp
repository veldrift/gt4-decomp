/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj {
    char pad0[0x64]; void *vt;
};
struct E { char b[8]; };
extern char RaceGTmode__vtable[];
extern char DynamicsConductorSinglePlayer__vtable[];
extern "C" void RaceResultBase__structor_0(void *, s32);
extern "C" void func_003DCA80(void *, s32);
extern "C" void RaceFuelMeter__structor_2(void *, s32);
extern "C" void RacePause__structor_1(void *, s32);
extern "C" void func_00393738(void *, s32);
extern "C" void DynamicsConductor__structor_1(void *, s32);
extern "C" void RaceSinglePlayer__structor_1(void *, s32);
extern "C" void func_005C1628(void *);
extern "C" void DynamicsConductorSinglePlayer__structor_5(Obj *self, s32 flags) {
    self->vt = RaceGTmode__vtable;
    RaceResultBase__structor_0((char *)self + 0x23BCC, 2);
    func_003DCA80((char *)self + 0x23AB0, 2);
    RaceFuelMeter__structor_2((char *)self + 0x22770, 2);
    RacePause__structor_1((char *)self + 0x22738, 2);
    E *arr = (E *)((char *)self + 0x22708);
    if (arr) {
        E *p = arr + 6;
        while (arr != p) {
            --p;
            func_00393738(p, 2);
        }
    }
    char *q = (char *)self + 0x125C0;
    *(char **)(q + 0x10140) = DynamicsConductorSinglePlayer__vtable;
    DynamicsConductor__structor_1(q, 0);
    RaceSinglePlayer__structor_1(self, 0);
    if (flags & 1) return func_005C1628(self);
}
