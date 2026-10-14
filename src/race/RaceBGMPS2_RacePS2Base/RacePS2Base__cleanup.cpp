typedef int s32;
typedef short s16;

struct VEntry_340 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

extern "C" void UnloadSphereMapperModel(void);
extern "C" void Pitmen__clear_2(void *);
extern "C" void RaceBase__cleanup(void *);
extern "C" void CourseEnvPtr__cleanup(void *);

extern "C" void RacePS2Base__cleanup(char *arg0) {
    char *tmp;
    VEntry_340 *e;

    UnloadSphereMapperModel();
    Pitmen__clear_2(arg0 + 0x3628);
    RaceBase__cleanup(arg0);
    tmp = *(char **)(*(char **)(*(char **)(arg0 + 0x6C) + 0x80) + 4);
    if (tmp != 0) {
        CourseEnvPtr__cleanup(*(char **)(tmp + 0x80));
    }
    e = (VEntry_340 *)(*(char **)(arg0 + 0x64) + 0x340);
    e->fn(arg0 + e->delta);
}
