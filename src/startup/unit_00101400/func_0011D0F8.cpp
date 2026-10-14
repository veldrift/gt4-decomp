typedef int s32;
typedef long long s64;

struct V { short delta; short index; void *fn; };
struct S { char pad[0x12C]; V *table; };

extern "C" char *D_00622F4C;
extern "C" void func_003BB440(S *arg0, char *arg1);
extern "C" void func_00444190(void *arg0);
extern "C" void SPEC_DATABASE__CarEquipments__setVariationOrder(void *arg0, s32 arg1);
extern "C" void func_00444440(void *arg0, s32 arg1);
extern "C" void func_004452F8(void *arg0, void *arg1);
extern "C" s32 SPEC_DATABASE__RaceSpec__getEnemyCode(void *arg0, s32 arg1);
extern "C" s32 func_00447458(void *arg0, s32 arg1);

static inline void *vcall(S *o) {
    V *e = (V *)((char *)o->table + 0x98);
    return ((void *(*)(void *))e->fn)((char *)o + e->delta);
}

extern "C" void func_0011D0F8(S *arg0) {
    s64 buf[48];
    func_003BB440(arg0, D_00622F4C + 0x44);
    vcall(arg0);
    func_00444190(buf);
    V *e2 = (V *)((char *)arg0->table + 0x98);
    void *r = ((void *(*)(void *))e2->fn)((char *)arg0 + e2->delta);
    s32 s2 = SPEC_DATABASE__RaceSpec__getEnemyCode(r, 0);
    func_00447458(r, 0);
    func_00444440(buf, s2);
    func_004452F8((char *)arg0 + 0x130, buf);
    SPEC_DATABASE__CarEquipments__setVariationOrder(buf, 2);
}
