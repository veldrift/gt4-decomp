/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Rec { s64 u0; s64 u8; s32 u10; s32 u14; s32 u18; void *u1C; };

struct VEntry { short delta; short index; void (*fn)(void *); };
struct VEntryI { short delta; short index; void (*fn)(void *, s32); };

struct Car { char pad0[0x18]; void *f18; char pad1C[0x345C - 0x1C]; s32 f345C; };
struct P8 { Car *p0; };
struct P60 { char pad[8]; P8 *p8; };
struct Course {
    char pad0[0x60];
    P60 *p60;
    char pad64[0x974 - 0x64];
    char *vtbl;
};

struct Run {
    char pad0[0x64];
    char *vtbl;
    char pad68[4];
    Course *u6C;
    char pad70[0xD60 - 0x70];
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
};

struct Stats { char pad[0x70]; s64 f70; s64 f78; };
struct Game {
    char pad0[4];
    char f4[0x348 - 4];
    Stats f348;
    char pad3C8[0x3D0 - 0x3C8];
    u8 f3D0;
    char pad3D1[0x568 - 0x3D1];
    char f568[0x3A368 - 0x568];
    char f3A368[4];
};

struct Info { char b[0x2C0]; };

extern Game *D_00622F4C;

extern "C" void GranTurismo4__LoadingMode(const char *);
extern "C" void func_0010AF40(int);
extern "C" void func_0010F770(Course *);
extern "C" void func_0010F848(Course *);
extern "C" void func_0010F948(Course *);
extern "C" void func_0010FA58(Course *, u32 *, u32 *);
extern "C" void func_0010FE40(const char *);
extern "C" void func_001103C8(void *);
extern "C" void func_001103E0(void *, s32);
extern "C" void func_00110460(void *);
extern "C" void func_00110938(Course *);
extern "C" void func_00110D18(Course *);
extern "C" void func_00118540(Info *);
extern "C" void func_00118670(Run *);
extern "C" void func_001186F8(Hud *, Run *);
extern "C" void func_001242B8(Hud *);
extern "C" void func_00127E60(Hud *);
extern "C" void func_00127F70(Hud *, int);
extern "C" Rec *func_001D3A60(void);
extern "C" Course *func_003B7850(Info *);
extern "C" void RaceFreePractice__structor_0(Run *);
extern "C" void func_003BFFE8(Course *);
extern "C" void func_003C0008(Course *);
extern "C" void RaceSinglePlayerInformation__structor_0(Info *);
extern "C" void RaceSinglePlayerInformation__structor_1(Info *, s32);
extern "C" void func_0042F448(char *, char *, int, unsigned char, unsigned char, int);
extern "C" void func_0042FC98(char *, const char *);
extern "C" void func_0044CA98(int, int, int, int);
extern "C" void func_0044CB10(void);
extern "C" void *exception__structor_0(u32);

struct Guard {
    char pad[4];
    u32 a;
    u32 b;
    Guard() { func_001103C8(this); a = 0; b = 0; }
    ~Guard() { func_001103E0(this, 2); }
};

struct InfoObj {
    Info i;
    InfoObj() { RaceSinglePlayerInformation__structor_0(&i); }
    ~InfoObj() { RaceSinglePlayerInformation__structor_1(&i, 2); }
};

#define CAR(c) ((c)->p60->p8->p0)

#define VCALL(r, off) { VEntry *e = (VEntry *)((r)->vtbl + (off)); e->fn((char *)(r) + e->delta); }
#define VCALLI(r, off, arg) { VEntryI *e = (VEntryI *)((r)->vtbl + (off)); e->fn((char *)(r) + e->delta, (arg)); }

extern "C" void func_001181C8(void) {
    func_0010AF40(0);
    Guard guard;
    func_0044CA98(0x30000, 2, 6, 0xBC8000);
    InfoObj info;
    func_00118540(&info.i);
    Hud *hud = (Hud *)exception__structor_0(0x4F8);
    func_00127E60(hud);
    func_001242B8(hud);
    Hud *mode = hud;
    Course *course = func_003B7850(&info.i);
    CAR(course)->f345C = D_00622F4C->f3D0;
    Run *run = (Run *)exception__structor_0(0x23AC0);
    RaceFreePractice__structor_0(run);
    run->u6C = course;
    run->fD60 = 0x21;
    run->fCF44 = 0.5f;
    run->fD64 = 0x22;
    func_00110938(course);
    func_001186F8(hud, run);
    func_00110D18(course);
    s32 running = 1;
    s32 flag = 0;
    do {
        func_00118670(run);
        switch (mode->f0) {
        case 1:
            func_0010F948(course);
            func_0010F770(course);
            func_0010F848(course);
            if (flag) {
                flag = 0;
                VCALL(run, 0x168)
            }
            VCALLI(run, 0x328, 0)
            func_0010FA58(course, &guard.a, &guard.b);
            hud->f46C = 1;
            break;
        case 3:
            VCALLI(run, 0x328, 2)
            break;
        case 15:
            flag = 1;
            func_003C0008(course);
            func_0010FE40("setting");
            func_003BFFE8(course);
            break;
        case 22:
            func_003C0008(course);
            func_0010FE40("option");
            func_003BFFE8(course);
            func_00110460(&guard);
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
    GranTurismo4__LoadingMode("race-end");
    if (run) {
        VCALLI(run, 8, 3)
    }
    func_001242B8(0);
    if (hud) {
        func_00127F70(hud, 3);
    }
    func_0044CB10();
    func_0042F448(D_00622F4C->f568, D_00622F4C->f4, 3, 0xF, 0xE, 0x157529FF);
    {
        Stats *s = &D_00622F4C->f348;
        s->f70 += guard.a;
    }
}
