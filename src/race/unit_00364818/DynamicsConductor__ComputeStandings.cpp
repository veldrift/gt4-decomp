typedef int s32; typedef float f32; typedef signed char s8;

struct Car { char pad0[0x104]; char pad[0x4AF]; s8 rank; };
struct VEntry { short delta; short index; void *(*fn)(void *); };
struct Mgr { char pad0[0x128]; VEntry ve; };
struct Cond {
    char pad0[0xF8A0];
    s32 count;
    s32 order[1];
    char padF8A8[0x10140 - 0xF8A8];
    Mgr *mgr;
};

extern "C" char *func_0034C190(Cond *, s32);
extern "C" f32 DynamicsConductor__GetCourseLength(Cond *);
extern "C" s32 func_003659E8(Cond *, void *, void *, void *, f32);

extern "C" void DynamicsConductor__ComputeStandings(Cond *self) {
    s32 i, j;
    for (i = 1; i < self->count; i++) {
        s32 key = self->order[i];
        for (j = i - 1; j >= 0; j--) {
            void *a = func_0034C190(self, self->order[j]) + 0x104;
            void *b = func_0034C190(self, key) + 0x104;
            VEntry *ve = &self->mgr->ve;
            void *c = ve->fn((char *)self + ve->delta);
            if (func_003659E8(self, a, b, c, DynamicsConductor__GetCourseLength(self)) >= 0) break;
            self->order[j + 1] = self->order[j];
        }
        self->order[j + 1] = key;
    }
    for (i = 0; i < self->count; i++) {
        Car *car = (Car *)func_0034C190(self, self->order[i]);
        car->rank = i + 1;
    }
}
