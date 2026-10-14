/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef long s64;
typedef float f32;

struct VEntryI { short delta; short index; void (*fn)(void *, s32); };

struct Course {
    char pad0[0x974];
    char *vtbl;
};

struct Run {
    char pad0[0x64];
    char *vtbl;
    char pad68[4];
    Course *u6C;
    char pad70[0xCE0 - 0x70];
    s32 fCE0;
    char padCE4[0xCF44 - 0xCE4];
    f32 fCF44;
};

struct Ent {
    char pad0[0x50];
    s32 f50;
    char pad54[0x5C - 0x54];
    s32 f5C;
    char pad60[0x68 - 0x60];
};

struct Opt {
    char pad0[0x10FC];
    s32 f10FC;
    char pad1100[0x112C - 0x1100];
    s32 f112C;
    s32 f1130;
    s32 f1134;
    s32 f1138;
};

struct Game {
    char pad0[4];
    char f4[0x44 - 4];
    char f44[0xD8 - 0x44];
    Ent ent[2];
    char pad1A8[0x38CB0 - 0x1A8];
    Opt opt;
    char pad39DEC[0x3A440 - 0x39DEC];
    char f3A440[0x3A900 - 0x3A440];
    char f3A900[4];
};

struct Info {
    char pad0[0xB0];
    s32 fB0;
    char padB4[0x460 - 0xB4];
};

extern Game *D_00622F4C;

extern "C" Info *RaceSplitBattleInformation__structor_0(Info *);
extern "C" void RaceSplitBattleInformation__structor_1(Info *, s32);
extern "C" void RaceSplitBattle__structor_0(Run *);
extern "C" Course *func_003B7850(Info *);
extern "C" void func_003BB440(Info *, char *);
extern "C" void RaceInformation__setCourseCode(Info *, s32);
extern "C" void RaceInformation__setEntryCars(Info *, s32);
extern "C" s64 *func_00441248(char *);
extern "C" s64 func_004454C0(s64 *);
extern "C" s32 func_00447C78(char *);
extern "C" void func_0044CA98(int, int, int, int);
extern "C" void func_0044CB10(void);
extern "C" void *exception__structor_0(u32);
extern "C" void func_005C2990(Info *, s32, Ent *);
extern "C" void func_005C29D0(Info *, s32, Ent *, s64 *);

#define VCALLI(r, off, arg) { VEntryI *e = (VEntryI *)((r)->vtbl + (off)); e->fn((char *)(r) + e->delta, (arg)); }

static inline bool isRetry(const s32 &s) { return s == 4; }

extern "C" void func_0010C0E8(void) {
    Info info;
    s32 state;
    s32 i;

    func_0044CA98(0x30000, 2, 6, 0xBC8000);
    RaceSplitBattleInformation__structor_0(&info);
    Opt *opt = &D_00622F4C->opt;
    char *gd = D_00622F4C->f4;
    func_003BB440(&info, D_00622F4C->f44);
    RaceInformation__setCourseCode(&info, func_00447C78(gd));
    info.fB0 = opt->f10FC;
    RaceInformation__setEntryCars(&info, 2);
    for (i = 0; i < 2; i++) {
        Ent *e = &D_00622F4C->ent[i];
        e->f50 = (i == 0) ? opt->f112C : opt->f1130;
        e->f5C = (i == 0) ? opt->f1134 : opt->f1138;
        char *car;
        if (i == 0) {
            car = D_00622F4C->f3A440;
        } else {
            car = D_00622F4C->f3A900;
        }
        if (func_004454C0(func_00441248(car)) == -1) {
            func_005C2990(&info, i, e);
        } else {
            func_005C29D0(&info, i, e, func_00441248(car));
        }
    }
    Course *course = func_003B7850(&info);
    Run *run = (Run *)exception__structor_0(0x2EC00);
    RaceSplitBattle__structor_0(run);
    run->u6C = course;
    run->fCF44 = 1.0f;
    state = 0;
    for (;;) {
        do {
            VCALLI(run, 0x328, 0)
            state = run->fCE0;
        } while (isRetry(state));
        VCALLI(run, 0x328, 2)
        state = run->fCE0;
        if (!isRetry(state)) {
            break;
        }
        state = 0;
    }
    if (run) {
        VCALLI(run, 8, 3)
    }
    if (course) {
        VEntryI *e = (VEntryI *)(course->vtbl + 8);
        e->fn((char *)course + e->delta, 3);
    }
    RaceSplitBattleInformation__structor_1(&info, 2);
    func_0044CB10();
}
