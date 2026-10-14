/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VE { s16 delta; s16 idx; void (*fn)(void *, s32); };

extern char RacePhotoDevelop__vtable[];
extern char SceneCameraBase__vtable[];
extern char DevelopCamera__vtable[];
extern char DynamicsConductorSinglePlayer__vtable[];

extern "C" void CameraBase__structor_1(void *, s32);
extern "C" void SceneCameraBase__structor_0(void *, s32);
extern "C" void DynamicsConductor__structor_1(void *, s32);
extern "C" void RaceSinglePlayer__structor_1(void *, s32);
extern "C" void func_005C1628(void *) throw();

extern "C" void DevelopCamera__structor_1(char *self, s32 flags) {
    *(char **)(self + 0x64) = RacePhotoDevelop__vtable;
    if (self != (char *)0xFFFDCBAC) {
        char *p = self + 0x245AC;
        if (self + 0x23454 != p) {
            char *start;
            do {
                start = self + 0x23454;
                p -= 0x2E4;
                VE *e = (VE *)(*(char **)p + 8);
                e->fn(p + e->delta, 2);
            } while (start != p);
        }
    }
    char *a = self + 0x233C0;
    *(char **)a = SceneCameraBase__vtable;
    CameraBase__structor_1(a, 0);
    char *b = self + 0x22740;
    *(char **)b = DevelopCamera__vtable;
    SceneCameraBase__structor_0(b, 0);
    char *c = self + 0x125C0;
    *(char **)(c + 0x10140) = DynamicsConductorSinglePlayer__vtable;
    DynamicsConductor__structor_1(c, 0);
    RaceSinglePlayer__structor_1(self, 0);
    if (flags & 1) {
        return func_005C1628(self);
    }
}
