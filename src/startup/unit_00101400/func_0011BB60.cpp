/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Rec { s64 u0; s64 u8; s32 u10; s32 u14; s32 u18; void *u1C; };

struct VEntryI { short delta; short index; void (*fn)(void *, s32); };

struct Drv { char pad0[0x5B6]; u8 f5B6; };
struct Car { char pad0[0x18]; Drv *f18; char pad1C[0x345C - 0x1C]; s32 f345C; };
struct P8 { Car *p0; };
struct P60 { char pad[8]; P8 *p8; };
struct Course {
    char pad0[0x60];
    P60 *p60;
    char pad64[0x70 - 0x64];
    void *p70;
    char pad74[0x974 - 0x74];
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
    char fE3AC[4];
};

struct Hud {
    s32 f0;
    char pad4[0x46C - 4];
    s32 f46C;
    char pad470[0x480 - 0x470];
    s32 f480;
};

struct Game {
    char pad0[0x3D0];
    u8 f3D0;
    char pad3D1[0x3A368 - 0x3D1];
    char f3A368[4];
};

struct Info { char b[0x2C0]; };

extern Game *D_00622F4C;

extern "C" void func_0010AF40(int);
extern "C" void func_0010F770(Course *);
extern "C" void func_0010F8E0(Course *);
extern "C" void func_0010FE40(const char *);
extern "C" void func_001103C8(void *);
extern "C" void func_001103E0(void *, s32);
extern "C" void func_00110460(void *);
extern "C" void func_0011BEC0(Info *);
extern "C" void func_0011BF60(Run *);
extern "C" void func_0011BFE8(Hud *, Run *);
extern "C" void func_0011C138(Run *);
extern "C" void func_0011C1D8(Hud *, Run *);
extern "C" void func_0011C2E0(Hud *, Run *);
extern "C" void func_0011C328(Hud *, Run *);
extern "C" void func_001242B8(Hud *);
extern "C" void func_00127E60(Hud *);
extern "C" void func_00127F70(Hud *, int);
extern "C" Rec *func_001D3A60(void);
extern "C" Course *func_003B7850(Info *);
extern "C" void DynamicsConductorMission__structor_0(Run *);
extern "C" void func_003BFFE8(Course *);
extern "C" void func_003C0008(Course *);
extern "C" void RaceTrainingInformation__structor_0(Info *);
extern "C" void RaceTrainingInformation__structor_1(Info *, s32);
extern "C" void func_0042FC98(char *, const char *);
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
    InfoObj() { RaceTrainingInformation__structor_0(&i); }
    ~InfoObj() { RaceTrainingInformation__structor_1(&i, 2); }
};

#define CAR(c) ((c)->p60->p8->p0)

#define VCALLI(r, off, arg) { VEntryI *e = (VEntryI *)((r)->vtbl + (off)); e->fn((char *)(r) + e->delta, (arg)); }

static inline bool notRetry(const s32 &s) { return s != 4; }

extern "C" void func_0011BB60(void) {
    func_0010AF40(0);
    Guard guard;
    func_0044CA98(0x30000, 2, 6, 0xBC8000);
    InfoObj info;
    func_0011BEC0(&info.i);
    Hud *hud = (Hud *)exception__structor_0(0x4F8);
    func_00127E60(hud);
    func_001242B8(hud);
    Course *course = func_003B7850(&info.i);
    CAR(course)->f345C = D_00622F4C->f3D0;
    Run *run = (Run *)exception__structor_0(0x22C80);
    DynamicsConductorMission__structor_0(run);
    run->u6C = course;
    run->fD60 = 0x13;
    run->fCF44 = 0.5f;
    run->fD64 = 0x14;
    func_0011C138(run);
    func_0011BFE8(hud, run);
    s32 running = 1;
    s32 state = 0;
    do {
        s32 mode;
        if (state == 4) {
            mode = 1;
        } else {
            func_0011BF60(run);
            mode = hud->f0;
            state = 0;
        }
        switch (mode) {
        case 1:
            if (hud->f480 == 1) {
                hud->f480 = 0;
                break;
            }
            func_0010F770(course);
            func_0010F8E0(course);
            VCALLI(run, 0x328, 0)
            state = run->fCE0;
            if (notRetry(state)) {
                if (CAR(course)->f18->f5B6) {
                    hud->f480 = 1;
                    func_0011C328(hud, run);
                    func_0011C1D8(hud, run);
                } else {
                    func_0011C2E0(hud, run);
                }
            }
            hud->f46C = 1;
            break;
        case 3:
            VCALLI(run, 0x328, 2)
            break;
        case 4:
            break;
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
        case 2:
            running = 0;
            break;
        default:
            running = 0;
            break;
        }
    } while (running);
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
}
