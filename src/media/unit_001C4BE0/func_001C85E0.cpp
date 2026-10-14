/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct G { char pad0[4]; char f4[0xDC]; char fE0[0x40]; s32 f120; };
struct Obj { char pad0[0x64]; void *f64; char pad1[0xA4 - 0x68]; void *fA4; void *fA8; char fAC[0x218 - 0xAC]; s32 f218; };
struct Item { char pad[0x6C]; void *f6C; };
struct Sing { char pad[0x1C]; void *f1C; };
extern G *D_00622F4C;
extern char D_00660DE8[];
extern "C" void *func_00109A78(void *);
extern "C" Sing *func_001D3A60(void);
extern "C" void func_001D3AD0(void *);
extern "C" void func_00333400(void *);
extern "C" void func_003335F0(void *, void *);
extern "C" void func_00387EF0(void *, s32, s32);
extern "C" void *func_003B7850(void *);
extern "C" void func_003BB440(void *, void *);
extern "C" void RaceInformation__setCourseCode(void *, s32);
extern "C" void RaceInformation__setEntryCars(void *, s32);
extern "C" s32 RaceMachineTestInformation__structor_0(void *);
extern "C" void RaceMachineTestInformation__structor_1(void *, s32);
extern "C" void RacePhotoMode__structor_0(void *);
extern "C" void *func_00441248(void *);
extern "C" s32 func_00444190(void *);
extern "C" void SPEC_DATABASE__CarEquipments__setVariationOrder(void *, s32);
extern "C" s32 func_004443A8(void *, void *);
extern "C" void func_004452F8(void *, void *);
extern "C" void func_00445880(void *, s32);
extern "C" s32 func_00447C78(void *);
extern "C" void *exception__structor_0(s32);
extern "C" void func_001C85E0(Obj *o) {
    char sp[0x180];
    char sp180[0x130];
    char sp2B0[0x190];
    void *s1;
    G **pg = &D_00622F4C;
    void **pa = &o->fA4;
    char *ac = o->fAC;
    func_00109A78(o);
    o->f64 = D_00660DE8;
    void *n = exception__structor_0(0x1F640);
    RacePhotoMode__structor_0(n);
    *pa = n;
    o->fA8 = n;
    func_00333400(ac);
    o->f218 = 0;
    G *g = *pg;
    char *s0 = g->fE0;
    char *s5 = g->f4;
    func_00444190(sp);
    if (func_004443A8(sp, s0)) {
        func_00445880(sp, (*pg)->f120);
        s1 = sp;
    } else {
        s1 = func_00441248((char *)*pg + 0x13938);
    }
    RaceMachineTestInformation__structor_0(sp180);
    func_003BB440(sp180, (char *)D_00622F4C + 0x44);
    RaceInformation__setEntryCars(sp180, 1);
    func_004452F8(sp2B0, s1);
    RaceInformation__setCourseCode(sp180, func_00447C78(s5));
    Item *it = (Item *)o->fA8;
    it->f6C = func_003B7850(sp180);
    func_00387EF0(o->fA8, 2, 1);
    func_003335F0(ac, o->fA8);
    func_001D3AD0(func_001D3A60());
    func_001D3A60()->f1C = ac;
    RaceMachineTestInformation__structor_1(sp180, 2);
    SPEC_DATABASE__CarEquipments__setVariationOrder(sp, 2);
}
