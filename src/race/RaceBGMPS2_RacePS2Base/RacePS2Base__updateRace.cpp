typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct List { s32 count; s32 pad; s32 *items; };
struct Car;
struct Obj;

extern "C" void RaceBase__updateRace(void *);
extern "C" void RacePS2Base__updateVolume(void *);
extern "C" void RaceEntryCar__update(s32);
extern "C" void func_004A7454(void);
extern "C" void pglMatrixMode(void *, void *, s32);
extern "C" void func_003B5E10(void *);
extern "C" void RaceCourseSound__playUpdate(void *, void *);

typedef char *(*GetFn)(char *, s32);
typedef void (*VoidFn)(char *, float);
typedef void (*RFn)(char *, char *, float);

struct Race6C { char pad[0x60]; List *list; };

extern "C" void RacePS2Base__updateRace(char *arg0) {
    RaceBase__updateRace(arg0);
    RacePS2Base__updateVolume(arg0);
    Race6C *s6 = *(Race6C **)(arg0 + 0x6C);
    VEntry *e1 = (VEntry *)(*(char **)(arg0 + 0x64) + 0xD0);
    char *s5 = ((GetFn)e1->fn)(arg0 + e1->delta, 0);
    if (*(s32 *)(arg0 + 0xCD0) == 0) {
        RaceEntryCar__update(0);
        func_004A7454();
        VEntry *e2 = (VEntry *)(*(char **)s5 + 0x18);
        ((VoidFn)e2->fn)(s5 + e2->delta, 0.0f);
    }
    s32 i = 0;
    s32 n = s6->list->count;
    s32 f = *(s32 *)(arg0 + 0xD44) == 0;
    if (n > 0) {
        do {
            char *c = (char *)s6->list->items[i];
            i++;
            if (*(s32 *)(arg0 + 0xCD0) == 0 && f) {
                pglMatrixMode(c, s5, *(s32 *)(arg0 + 0xCC8) != 0);
            }
            if (*(s32 *)(c + 0x2888) != 0) {
                char *a2 = *(char **)(c + 0x2880);
                VEntry *e3 = (VEntry *)(*(char **)(a2 + 8) + 0x110);
                ((RFn)e3->fn)(a2 + e3->delta, arg0 + 0x3238, 0.0f);
                func_003B5E10(c);
            }
        } while (i < n);
    }
    if (*(s32 *)(arg0 + 0xCD0) == 0 && f) {
        RaceCourseSound__playUpdate(arg0 + 0xE170, s6);
    }
}
