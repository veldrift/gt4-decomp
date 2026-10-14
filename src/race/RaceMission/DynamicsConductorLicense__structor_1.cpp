/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    char pad0[0x64];
    void *vt;
};
extern char RaceMission__vtable[];
extern char DynamicsConductorLicense__vtable[];
extern "C" void RaceResultBase__structor_0(void *, int);
extern "C" void func_00393738(void *, int);
extern "C" void DynamicsConductor__structor_1(void *, int);
extern "C" void RaceTrainingBase__structor_1(void *, int);
extern "C" int func_005C1628(void *) throw();

extern "C" int DynamicsConductorLicense__structor_1(Obj *o, int flags) {
    char *begin = (char *)o + 0x22748;
    o->vt = RaceMission__vtable;
    RaceResultBase__structor_0((char *)o + 0x22778, 2);
    if (begin) {
        char *p = begin + 0x30;
        if (begin != p) {
            do {
                p -= 8;
                func_00393738(p, 2);
            } while (begin != p);
        }
    }
    char *q = (char *)o + 0x12600;
    *(void **)(q + 0x10140) = DynamicsConductorLicense__vtable;
    DynamicsConductor__structor_1(q, 0);
    RaceTrainingBase__structor_1(o, 0);
    if (flags & 1)
        return func_005C1628(o);
}
