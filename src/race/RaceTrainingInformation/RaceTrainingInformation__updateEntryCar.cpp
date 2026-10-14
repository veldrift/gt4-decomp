/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef signed char s8;

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct Target {
    char pad0[4];
    char *vtbl;
};

struct Self {
    char pad0[0x12C];
    Target *t12C;
    char car[4];
};

struct Dest {
    char pad0[0x14];
    s32 unk14;
    char pad18[8];
    char entry[0x178 + 4];
};

extern "C" int func_00444190(void *);
extern "C" void SPEC_DATABASE__CarEquipments__setVariationOrder(void *, s32);
extern "C" void func_004452F8(void *, void *);
extern "C" int func_00445880(void *, s32);
extern "C" s8 SPEC_DATABASE__CarEquipments__getVariationOrder(void *);
extern "C" s32 SPEC_DATABASE__RaceSpec__getEnemyCount(void *);
extern "C" int SPEC_DATABASE__RaceSpec__getEnemy(void *, s32, void *);

typedef void *(*Fn)(void *);

static inline void *getobj(Self *self) {
    VEntry *e = (VEntry *)((char *)self->t12C + 0x98);
    return ((Fn)e->fn)((char *)self + e->delta);
}

extern "C" void RaceTrainingInformation__updateEntryCar(Self *self, Dest *dst) {
    char buf[0x180];
    s32 idx = dst->unk14;
    if (idx == 0) {
        char *e = dst->entry;
        func_004452F8(e, self->car);
        *(s32 *)(e + 0x178 - 0x0) = 0x100;
        return;
    }
    func_00444190(buf);
    {
        s32 n = SPEC_DATABASE__RaceSpec__getEnemyCount(getobj(self)) - 1;
        if (n < idx) idx = n;
        SPEC_DATABASE__RaceSpec__getEnemy(getobj(self), idx, buf);
    }
    if (SPEC_DATABASE__CarEquipments__getVariationOrder(buf) == -1) {
        func_00445880(buf, 0);
    }
    char *e = dst->entry;
    func_004452F8(e, buf);
    e[0x166] = 1;
    SPEC_DATABASE__CarEquipments__setVariationOrder(buf, 2);
}
