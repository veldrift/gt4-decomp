/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    char pad0[0x64];
    void *vt;
};
extern "C" char RaceNetBattle__vtable[];
extern "C" char ResultLinkBattle__vtable[];
extern "C" char DynamicsConductorBattleMP__vtable[];
extern "C" void RaceABMonitor__structor_0(void *, int);
extern "C" void RacePause__structor_1(void *, int);
extern "C" void RaceResultBase__structor_0(void *, int);
extern "C" void func_00393738(void *, int);
extern "C" void DynamicsConductor__structor_1(void *, int);
extern "C" void RaceInput__structor_2(void *, int);
extern "C" void func_0055FA30(void *, int);
extern "C" void func_005F3210(void *, int);
extern "C" int func_005C1628(void *);

extern "C" int DynamicsConductorBattleMP__structor_1(Obj *o, int flags) {
    char *begin = (char *)o + 0x1E7A8;
    o->vt = RaceNetBattle__vtable;
    RaceABMonitor__structor_0((char *)o + 0x1ED1C, 2);
    RacePause__structor_1((char *)o + 0x1ECE4, 2);
    char *e = (char *)o + 0x1E7D8;
    *(void **)(e + 0xC) = ResultLinkBattle__vtable;
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
    char *q = (char *)o + 0xE660;
    *(void **)(q + 0x10140) = DynamicsConductorBattleMP__vtable;
    DynamicsConductor__structor_1(q, 0);
    RaceInput__structor_2((char *)o + 0xE480, 2);
    func_0055FA30((char *)o + 0xE440, 2);
    func_005F3210(o, 0);
    if (flags & 1)
        return func_005C1628(o);
}
