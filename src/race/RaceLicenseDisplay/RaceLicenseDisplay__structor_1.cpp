typedef int s32;
extern char RaceLicenseDisplay__vtable[];
extern char RaceValueDisplayBase__vtable[];
extern "C" void RaceABMonitor__structor_0(void *, s32);
extern "C" void RaceTexturePanel__structor_1(void *, s32);
extern "C" void RaceDisplayObjectBase__structor_1(void *, s32);
extern "C" void func_005C1628(void *) throw();
struct VEntry_vcall_0 { short delta; short index; void (*fn)(void *, s32); };
static inline void vcall_0(char *o, s32 a0) {
    VEntry_vcall_0 *e = (VEntry_vcall_0 *)(*(char **)(o + 0x14) + 0x8);
    e->fn(o + e->delta, a0);
}
struct Lic { char pad[0x4360]; char s4360[0x1C]; };
extern "C" void RaceLicenseDisplay__structor_1(char *arg0, s32 arg1) {
    *(char **)arg0 = RaceLicenseDisplay__vtable;
    RaceTexturePanel__structor_1(arg0 + 0x4360, 2);
    char *v = arg0 + 0x42C8;
    *(char **)(v + 0x14) = RaceValueDisplayBase__vtable;
    RaceDisplayObjectBase__structor_1(v, 0);
    if (arg0 + 0x4080 != 0) {
        char *p0 = arg0 + 0x423C;
        while (arg0 + 0x4080 != p0) {
            p0 -= 0x94;
            vcall_0(p0, 2);
        }
    }
    if (arg0 + 0x3F30 != 0) {
        char *p1 = arg0 + 0x4080;
        while (arg0 + 0x3F30 != p1) {
            p1 -= 0x70;
            vcall_0(p1, 2);
        }
    }
    RaceABMonitor__structor_0(arg0, 0);
    if ((arg1 & 1) != 0) {
        return func_005C1628(arg0);
    }
}
