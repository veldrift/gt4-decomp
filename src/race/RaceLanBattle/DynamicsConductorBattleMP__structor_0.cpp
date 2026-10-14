/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry { s16 delta; s16 index; void (*fn)(void *, s32); };
struct Elem8 { char pad[8]; };
struct ElemV { char pad[0xD0]; char *vtbl; char pad2[0x214 - 0xD4]; };

extern char RaceLanBattle__vtable[];
extern char ResultLinkBattle__vtable[];
extern char DynamicsConductorBattleMP__vtable[];

extern "C" void RaceLanControlManager__structor_1(void *, s32) throw();
extern "C" void DynamicsConductor__structor_1(void *, s32);
extern "C" void func_00393738(void *, s32);
extern "C" void RaceABMonitor__structor_0(void *, s32);
extern "C" void RacePause__structor_1(void *, s32);
extern "C" void PauseBase__structor_1(void *, s32);
extern "C" void RaceResultBase__structor_0(void *, s32);
extern "C" void RaceInput__structor_2(void *, s32);
extern "C" void func_005C1628(void *) throw();
extern "C" void func_005F3210(void *, s32);

extern "C" void DynamicsConductorBattleMP__structor_0(char *self, s32 flags) {
    Elem8 *arr = (Elem8 *)(self + 0x1F4D8);
    *(char **)(self + 0x64) = RaceLanBattle__vtable;
    PauseBase__structor_1(self + 0x2397C, 2);
    RaceABMonitor__structor_0(self + 0x1FA4C, 2);
    RacePause__structor_1(self + 0x1FA14, 2);
    char *sub = self + 0x1F508;
    *(char **)(sub + 0xC) = ResultLinkBattle__vtable;
    RaceResultBase__structor_0(sub, 0);
    if (arr != 0) {
        Elem8 *q = arr + 6;
        while (arr != q) {
            --q;
            func_00393738(q, 2);
        }
    }
    char *dyn = self + 0xF390;
    *(char **)(dyn + 0x10140) = DynamicsConductorBattleMP__vtable;
    ElemV *s0 = (ElemV *)(self + 0xF184);
    DynamicsConductor__structor_1(dyn, 0);
    RaceInput__structor_2(s0, 2);
    if (self + 0xE50C != 0) {
        if (((ElemV *)(self + 0xE50C)) != s0) {
            ElemV *q = s0;
            do {
                arr = (Elem8 *)((ElemV *)(self + 0xE50C));
                --q;
                VEntry *e = (VEntry *)(q->vtbl + 8);
                e->fn((char *)q + e->delta, 2);
            } while ((ElemV *)arr != q);
        }
    }
    RaceLanControlManager__structor_1(self + 0xE488, 2);
    func_005F3210(self, 0);
    if (flags & 1) return func_005C1628(self);
}
