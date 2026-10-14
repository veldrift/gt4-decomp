/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    char pad0[0x58];
    void *f58;
    char pad5c[8];
    void *vt;
    char pad68[8];
    void *f70;
};
struct VE { short delta; short idx; int (*fn)(void *, int); };
struct VObj { VE *vtbl; };
extern "C" char RaceNetBattle__vtable[];
extern "C" char ResultLinkBattle__vtable[];
extern "C" char *D_0064C6F0;
extern "C" char *D_00622F4C;
extern "C" int func_005F31E0(void *);
extern "C" void func_0055F9F8(void *);
extern "C" void RaceInput__structor_0(void *);
extern "C" void DynamicsConductorBattleMP__structor_2(void *);
extern "C" int func_00393700(void *);
extern "C" int ResultArcade__structor_0(void *);
extern "C" void RacePause__structor_0(void *);
extern "C" void RaceDisplay__structor_0(void *);
extern "C" void func_0038BB50(void *, void *);
extern "C" int func_0055F420(char *);
extern "C" void func_00109A28(void *, void *);
extern "C" void func_00346808(void *, int);
extern "C" int func_003DF898(void *, void *);

extern "C" int RaceNetBattle__structor_0(Obj *o) {
    int i;
    char *p;
    char *s2;
    char *s1;
    char *s0;
    i = 5;
    func_005F31E0(o);
    p = (char *)o + 0x1E7A8;
    o->vt = RaceNetBattle__vtable;
    func_0055F9F8((char *)o + 0xE440);
    RaceInput__structor_0((char *)o + 0xE480);
    DynamicsConductorBattleMP__structor_2((char *)o + 0xE660);
    for (; i != -1; i--) {
        func_00393700(p);
        p += 8;
    }
    s2 = (char *)o + 0x1E7D8;
    s1 = (char *)o + 0x1ED1C;
    s0 = (char *)o + 0xE480;
    ResultArcade__structor_0(s2);
    *(void **)(s2 + 0xC) = ResultLinkBattle__vtable;
    RacePause__structor_0((char *)o + 0x1ECE4);
    RaceDisplay__structor_0(s1);
    *(int *)((char *)o + 0x22C4C) = 0;
    *(int *)((char *)o + 0x22C50) = 0;
    o->f70 = (char *)o + 0xE660;
    func_0038BB50(o, s1);
    *(int *)s0 = func_0055F420(D_0064C6F0);
    {
        VObj *a = (VObj *)(D_00622F4C + 0x39E80);
        VE *e = (VE *)((char *)a->vtbl + 0x40);
        *(int *)(s0 + 0x194) = e->fn((char *)a + e->delta, 0);
    }
    o->f58 = (char *)o + 0xE440;
    func_00109A28(o, s0);
    {
        char *q = (char *)o + 0xE554;
        *(int *)(q + 4) = 0;
        func_00346808(q, 0);
    }
    return func_003DF898(s2, (char *)o + 0xE350);
}
