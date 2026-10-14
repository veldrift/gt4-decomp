/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    char pad0[0x64];
    void *vt;
    char pad68[8];
    void *conductor;
    char pad74[0x22C38 - 0x74];
    int f22C38, f22C3C;
};
extern "C" char RaceNetRallyBattle__vtable[];
extern "C" void *RaceNetSinglePlayer__structor_0(void *);
extern "C" void DynamicsConductorSinglePlayer__structor_1(void *);
extern "C" int func_00393700(void *);
extern "C" void ResultArcade__structor_0(void *);
extern "C" int func_003DF898(void *, void *);
extern "C" int RaceNetRallyBattle__structor_0(Obj *o) {
    RaceNetSinglePlayer__structor_0(o);
    o->vt = RaceNetRallyBattle__vtable;
    DynamicsConductorSinglePlayer__structor_1((char *)o + 0x125C0);
    char *p = (char *)o + 0x22708;
    for (int i = 5; i != -1; i--) {
        func_00393700(p);
        p += 8;
    }
    p = (char *)o + 0x22738;
    ResultArcade__structor_0(p);
    o->f22C38 = 0;
    o->f22C3C = 0;
    o->conductor = (char *)o + 0x125C0;
    return func_003DF898(p, (char *)o + 0xE350);
}
