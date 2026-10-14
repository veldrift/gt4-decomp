/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x64]; void *vt; };
extern char RaceChampionship__vtable[];
extern char ResultChampionship__vtable[];
extern char DynamicsConductorSinglePlayer__vtable[];
extern "C" void func_003DCA80(void *, int);
extern "C" void RaceFuelMeter__structor_2(void *, int);
extern "C" void RacePause__structor_1(void *, int);
extern "C" void RaceResultBase__structor_0(void *, int);
extern "C" void func_00393738(void *, int);
extern "C" void DynamicsConductor__structor_1(void *, int);
extern "C" void RaceSinglePlayer__structor_1(void *, int);
extern "C" void func_005C1628(void *) throw();
extern "C" void DynamicsConductorSinglePlayer__structor_6(Obj *o, int flags) {
    char *begin = (char *)o + 0x22708;
    o->vt = RaceChampionship__vtable;
    func_003DCA80((char *)o + 0x24018, 2);
    RaceFuelMeter__structor_2((char *)o + 0x22CD4, 2);
    RacePause__structor_1((char *)o + 0x22C9C, 2);
    char *e = (char *)o + 0x22738;
    *(void **)(e + 0xC) = ResultChampionship__vtable;
    RaceResultBase__structor_0(e, 0);
    if (begin) {
        char *p = begin + 0x30;
        if (begin != p) {
            do {
                p -= 8;
                func_00393738(p, 2);
            } while (begin != p);
        }
    }
    char *q = (char *)o + 0x125C0;
    *(void **)(q + 0x10140) = DynamicsConductorSinglePlayer__vtable;
    DynamicsConductor__structor_1(q, 0);
    RaceSinglePlayer__structor_1(o, 0);
    if (flags & 1) return func_005C1628(o);
}
