/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry { s16 delta; s16 pad; void (*fn)(void *, s32); };

extern char RaceSplitBattleBase__vtable[];
extern char DynamicsConductorBattle2P__vtable[];

extern "C" void GranTurismo4__GameObjectBase__delControl(void *, void *);
extern "C" void RaceSplitDisplay__structor_1(void *, s32);
extern "C" void SimplePause__structor_1(void *, s32);
extern "C" void RacePause__structor_1(void *, s32);
extern "C" void RaceResultBase__structor_0(void *, s32);
extern "C" void func_00393738(void *, s32);
extern "C" void DynamicsConductor__structor_1(void *, s32);
extern "C" void func_0055FA30(void *, s32);
extern "C" void func_005F2A38(void *, s32);
extern "C" void func_005C1628(void *) throw();

struct Self {
    char pad0[0x64];
    void *vtbl;
};

extern "C" void DynamicsConductorBattle2P__structor_0(Self *self, s32 flags) {
    char *p = (char *)self + 0x1E5C8;
    s32 i = 1;
    self->vtbl = RaceSplitBattleBase__vtable;
    do {
        char *q = p;
        p += 0x1E0;
        i--;
        GranTurismo4__GameObjectBase__delControl(self, q);
    } while (i >= 0);
    RaceSplitDisplay__structor_1((char *)self + 0x1EEFC, 2);
    char *arr1 = (char *)self + 0x1E988;
    SimplePause__structor_1((char *)self + 0x1EEF0, 2);
    RacePause__structor_1((char *)self + 0x1EEB8, 2);
    RaceResultBase__structor_0((char *)self + 0x1E9B8, 2);
    if (arr1 != 0) {
        char *e = arr1 + 0x30;
        if (arr1 != e) {
            do {
                e -= 8;
                func_00393738(e, 2);
            } while (arr1 != e);
        }
    }
    if ((unsigned)self != 0xFFFE1A38u) {
        char *e = (char *)self + 0x1E988;
        if ((char *)self + 0x1E5C8 != e) {
            do {
                e -= 0x1E0;
                VEntry *v = (VEntry *)(*(char **)(e + 0xD0) + 8);
                v->fn(e + v->delta, 2);
            } while ((char *)self + 0x1E5C8 != e);
        }
    }
    char *b = (char *)self + 0xE480;
    *(char **)(b + 0x10140) = DynamicsConductorBattle2P__vtable;
    DynamicsConductor__structor_1(b, 0);
    func_0055FA30((char *)self + 0xE440, 2);
    func_005F2A38(self, 0);
    if (flags & 1)
        return func_005C1628(self);
}
