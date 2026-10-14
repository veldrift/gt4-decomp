/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Flags { s32 w[10]; };
struct Rec { s64 u0; s64 u8; s32 u10; s32 u14; s32 u18; void *u1C; };

struct VEntry { short delta; short index; void (*fn)(void *); };
struct VEntryI { short delta; short index; void (*fn)(void *, s32); };
struct VEntryRP { short delta; short index; s32 (*fn)(void *, s32 *); };

struct Car { char pad0[0x345C]; s32 f345C; };
struct P8 { Car *p0; };
struct P60 { char pad[8]; P8 *p8; };
struct Course {
    char pad0[0x60];
    P60 *p60;
    char pad64[0x70 - 0x64];
    void *p70;
    char pad74[0x88 - 0x74];
    Flags f88;
    char padB0[0x974 - 0xB0];
    char *vtbl;
};

struct Run {
    char pad0[0x64];
    char *vtbl;
    char pad68[4];
    Course *u6C;
    void *u70;
    char pad74[0xCE0 - 0x74];
    s32 fCE0;
    char padCE4[0xD60 - 0xCE4];
    s32 fD60;
    s32 fD64;
    char padD68[0xCF44 - 0xD68];
    f32 fCF44;
    char padCF48[0xE3AC - 0xCF48];
    char fE3AC[0xF050 - 0xE3AC];
    s32 fF050;
};

struct Hud {
    s32 f0;
    char pad4[0x46C - 4];
    s32 f46C;
    char pad470[4];
    s32 f474;
    char pad478[0x498 - 0x478];
    u32 f498;
    char pad49C[0x4B0 - 0x49C];
    s32 f4B0;
};

struct Game {
    char pad0[0x3D0];
    u8 f3D0;
    char pad3D1[0x3A368 - 0x3D1];
    char f3A368[4];
};

struct Info { char b[0x2C0]; };

extern Game *D_00622F4C;

extern "C" void GranTurismo4__LoadingMode(const char *);
extern "C" void func_0010AF40(int);
extern "C" void func_0010F770(Course *);
extern "C" void func_0010F880(Course *);
extern "C" void func_0010FE40(const char *);
extern "C" void func_0010FEE8(Hud *, Run *);
extern "C" s32 SettingSerialize__structor_0(Run *, s32);
extern "C" void func_001103C8(void *);
extern "C" void func_001103E0(void *, s32);
extern "C" void func_00110460(void *);
extern "C" void func_001105A8(Run *, s32 *, u32 *);
extern "C" void func_00110800(Run *, s32 *, u32 *);
extern "C" void func_0011D0F8(Info *);
extern "C" void func_0011D1B8(Run *);
extern "C" void func_0011D340(Hud *, Run *);
extern "C" void func_001242B8(Hud *);
extern "C" void func_00127E60(Hud *);
extern "C" void func_00127F70(Hud *, int);
extern "C" Rec *func_001D3A60(void);
extern "C" void func_001D3AD0(Rec *);
extern "C" u32 DynamicsConductor__CurrentTotalTime(void *);
extern "C" void func_00387EF0(Run *, int, int);
extern "C" void RaceEntryBase__sortByRank(P60 *);
extern "C" Course *func_003B7850(Info *);
extern "C" void RaceLicense__structor_0(Run *);
extern "C" void RaceMachineTestInformation__structor_0(Info *);
extern "C" void RaceMachineTestInformation__structor_1(Info *, s32);
extern "C" void func_003BFFE8(Course *);
extern "C" void func_003C0008(Course *);
extern "C" void func_003C08C0(Course *, int, int);
extern "C" void func_003C0B30(Course *);
extern "C" void func_0042FC98(char *, const char *);
extern "C" s64 func_004454C0(char *);
extern "C" s32 SPEC_DATABASE__RaceSpec__getRaceLabel(void *);
extern "C" s64 SPEC_DATABASE__RaceSpec__getCourseCode(void *);
extern "C" void func_0044CA98(int, int, int, int);
extern "C" void func_0044CB10(void);
extern "C" void *exception__structor_0(u32);

struct Guard {
    char pad[0x10];
    Guard() { func_001103C8(this); }
    ~Guard() { func_001103E0(this, 2); }
};

struct InfoObj {
    Info i;
    InfoObj() { RaceMachineTestInformation__structor_0(&i); }
    ~InfoObj() { RaceMachineTestInformation__structor_1(&i, 2); }
};

#define CAR(c) ((c)->p60->p8->p0)

#define VCALL(r, off) { VEntry *e = (VEntry *)((r)->vtbl + (off)); e->fn((char *)(r) + e->delta); }
#define VCALLI(r, off, arg) { VEntryI *e = (VEntryI *)((r)->vtbl + (off)); e->fn((char *)(r) + e->delta, (arg)); }

extern "C" s32 func_0011CB38(void) {
    func_0010AF40(0);
    s32 result = 0;
    Guard guard;
    func_0044CA98(0x30000, 2, 6, 0xBC8000);
    s64 carCode;
    s64 courseCode;
    InfoObj info;
    func_0011D0F8(&info.i);
    Hud *hud = (Hud *)exception__structor_0(0x4F8);
    func_00127E60(hud);
    func_001242B8(hud);
    Course *course = func_003B7850(&info.i);
    CAR(course)->f345C = D_00622F4C->f3D0;
    Run *run = (Run *)exception__structor_0(0x24F00);
    RaceLicense__structor_0(run);
    run->u6C = course;
    run->fCF44 = 0.5f;
    s32 tmp;
    {
        VEntryRP *e = (VEntryRP *)(run->vtbl + 0x300);
        if (e->fn((char *)run + e->delta, &tmp) == 9) {
            run->fD60 = 0x1F;
            run->fD64 = 0x20;
        } else {
            run->fD60 = 0x13;
            run->fD64 = 0x14;
        }
    }
    s32 state = 0;
    func_00387EF0(run, 0, 1);
    VCALL(run, 0x2C0)
    run->fF050 = 1;
    func_0011D340(hud, run);
    carCode = func_004454C0((char *)CAR(course) + 0x20);
    courseCode = SPEC_DATABASE__RaceSpec__getCourseCode(course->p70);
    s32 label = SPEC_DATABASE__RaceSpec__getRaceLabel(course->p70);
    SettingSerialize__structor_0(run, label);
    Flags fl;
    u32 best = 0x157529FF;
    s32 x = 0xD;
    s32 running = 1;
    do {
        s32 mode;
        if (state == 4) {
            mode = 1;
        } else {
            state = 0;
            func_0011D1B8(run);
            mode = hud->f0;
        }
        switch (mode) {
        case 1: {
            func_0010F770(course);
            func_0010F880(course);
            VCALLI(run, 0x328, 0)
            state = run->fCE0;
            func_001105A8(run, &x, &best);
            hud->f498 = best;
            RaceEntryBase__sortByRank(run->u6C->p60);
            fl = run->u6C->f88;
            if (fl.w[4]) {
                func_003C0B30(course);
                hud->f474 = 1;
                hud->f4B0 = 1;
            }
            if (fl.w[3]) {
                func_003C08C0(run->u6C, 0, 0);
            }
            if (DynamicsConductor__CurrentTotalTime(run->u70) < 0x7D1) {
                SettingSerialize__structor_0(run, label);
                hud->f46C = 0;
            } else {
                hud->f46C = 1;
            }
            break;
        }
        case 3:
            GranTurismo4__LoadingMode("black fade in");
            VCALLI(run, 0x328, 2)
            break;
        case 4:
            SettingSerialize__structor_0(run, label);
            GranTurismo4__LoadingMode("black fade in");
            VCALLI(run, 0x328, 2)
            hud->f46C = 0;
            break;
        case 21:
            func_0010FEE8(hud, run);
            break;
        case 10: {
            func_0042FC98(D_00622F4C->f3A368, "MODE_LOAD_BESTLAP_REPLAY");
            Rec *r = func_001D3A60();
            s32 y = -1;
            func_001D3AD0(r);
            r->u0 = carCode;
            r->u8 = courseCode;
            VEntryRP *e = (VEntryRP *)(run->vtbl + 0x300);
            s32 id = e->fn((char *)run + e->delta, &y);
            r->u10 = id;
            r->u14 = y;
            r->u1C = run;
            r->u18 = 0;
            func_003C0008(course);
            func_0010FE40("labomode");
            func_003BFFE8(course);
            break;
        }
        case 11: {
            Rec *r = func_001D3A60();
            r->u1C = run->fE3AC;
            func_0042FC98(D_00622F4C->f3A368, "MODE_SAVE_BESTLAP_REPLAY");
            func_003C0008(course);
            func_0010FE40("labomode");
            func_003BFFE8(course);
            break;
        }
        case 9: {
            Rec *r = func_001D3A60();
            r->u1C = run->fE3AC;
            func_0042FC98(D_00622F4C->f3A368, "MODE_SAVE_FULL_REPLAY");
            func_003C0008(course);
            func_0010FE40("labomode");
            func_003BFFE8(course);
            break;
        }
        case 22:
            func_003C0008(course);
            func_0010FE40("option");
            func_003BFFE8(course);
            func_00110460(&guard);
            break;
        case 13:
            break;
        case 18:
            result = 1;
        case 2:
            running = 0;
            break;
        default:
            running = 0;
            break;
        }
    } while (running);
    func_00110800(run, &x, &best);
    if (course) {
        VEntryI *e = (VEntryI *)(course->vtbl + 8);
        e->fn((char *)course + e->delta, 3);
    }
    if (run) {
        VCALLI(run, 8, 3)
    }
    func_001242B8(0);
    if (hud) {
        func_00127F70(hud, 3);
    }
    func_0044CB10();
    return result;
}
