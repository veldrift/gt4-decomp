/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern char RaceFreeRun__vtable[];
extern char DynamicsConductorFreeRun__vtable[];
extern "C" {
void func_00393738(void *, int);
static inline void destroyArr(char *base) {
    if (base != 0) {
        char *e = base + 0x30;
        if (base != e) {
            do {
                e -= 8;
                func_00393738(e, 2);
            } while (base != e);
        }
    }
}
void DynamicsConductor__structor_1(void *, s32);
void func_00393738(void *, int);
void RaceABMonitor__structor_0(void *, s32);
void RacePause__structor_1(void *, s32);
void RaceFuelMeter__structor_2(void *, s32);
void func_003DCA80(void *, s32);
void RaceSolitaire__structor_1(void *, s32);
void func_005C1628(void *) throw();
void DynamicsConductorFreeRun__structor_0(char *self, s32 flags) {
    char *base = self + 0x1F2A0;
    *(char **)(self + 0x64) = RaceFreeRun__vtable;
    func_003DCA80(self + 0x24578, 2);
    RaceFuelMeter__structor_2(self + 0x23238, 2);
    RaceABMonitor__structor_0(self + 0x1F308, 2);
    RacePause__structor_1(self + 0x1F2D0, 2);
    destroyArr(base);
    char *v = self + 0xF140;
    *(char **)(v + 0x10140) = DynamicsConductorFreeRun__vtable;
    DynamicsConductor__structor_1(v, 0);
    RaceSolitaire__structor_1(self, 0);
    if (flags & 1)
        return func_005C1628(self);
}
}
