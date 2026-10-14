/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef long s64;
typedef float f32;

struct Mat4 { f32 m[16]; };
struct Rec { s64 u0; s64 u8; s32 u10; s32 u14; s32 u18; void *u1C; };

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
    char pad70[0xCF44 - 0x70];
    f32 fCF44;
    char padCF48[0xE3AC - 0xCF48];
    char fE3AC[4];
};

struct Hud {
    s32 f0;
    char pad4[0x46C - 4];
    s32 f46C;
};

struct Game {
    char pad0[4];
    char f4[0x3A368 - 4];
    char f3A368[0x3A43C - 0x3A368];
    u32 f3A43C;
};

struct Info { char b[0x2C0]; };

extern Game *D_00622F4C;

extern "C" void GranTurismo4__LoadingMode(const char *);
extern "C" void func_0010AF40(int);
extern "C" void func_0010F770(Course *);
extern "C" void func_0010F7D8(Course *);
extern "C" void func_0010FE40(const char *);
extern "C" void func_001103C8(void *);
extern "C" void func_001103E0(void *, s32);
extern "C" void func_00110460(void *);
extern "C" void func_00110938(Course *);
extern "C" f32 func_00110A18(Course *);
extern "C" void func_00110AE8(Course *, const Mat4 *);
extern "C" void func_001118B8(Info *);
extern "C" void func_001119A0(Run *);
extern "C" void func_00111A40(Hud *, Run *);
extern "C" void func_00111B50(Hud *, Run *);
extern "C" void func_00111DC0(Hud *, Run *);
extern "C" s32 func_00111E98(Run *);
extern "C" void func_001242B8(Hud *);
extern "C" void func_00127E60(Hud *);
extern "C" void func_00127F70(Hud *, int);
extern "C" Rec *func_001D3A60(void);
extern "C" s16 Automobile__GetImplicitCurrentLap(void *);
extern "C" void RaceArcadeInformation__structor_0(Info *);
extern "C" void RaceArcadeInformation__structor_1(Info *, s32);
extern "C" void RaceArcadeSingle__structor_0(Run *);
extern "C" Course *func_003B7850(Info *);
extern "C" void func_003BFFE8(Course *);
extern "C" void func_003C0008(Course *);
extern "C" void func_0042FC98(char *, const char *);
extern "C" void func_0044CA98(int, int, int, int);
extern "C" void func_0044CB10(void);
extern "C" void func_00468710(Mat4 *, char *, f32);
extern "C" void *exception__structor_0(u32);

struct Guard {
    char pad[0x10];
    Guard() { func_001103C8(this); }
    ~Guard() { func_001103E0(this, 2); }
};

struct InfoObj {
    Info i;
    InfoObj() { RaceArcadeInformation__structor_0(&i); }
    ~InfoObj() { RaceArcadeInformation__structor_1(&i, 2); }
};

#define CAR(c) ((c)->p60->p8->p0)

#define VCALLI(r, off, arg) { VEntryI *e = (VEntryI *)((r)->vtbl + (off)); e->fn((char *)(r) + e->delta, (arg)); }

extern "C" void func_00111498(void) {
    func_0010AF40(0);
    Guard guard;
    D_00622F4C->f3A43C = 0x157529FF;
    func_0044CA98(0x30000, 2, 6, 0xBC8000);
    InfoObj info;
    func_001118B8(&info.i);
    Hud *hud = (Hud *)exception__structor_0(0x4F8);
    func_00127E60(hud);
    func_001242B8(hud);
    Hud *mode = hud;
    Course *course = func_003B7850(&info.i);
    CAR(course)->f345C = 2;
    Run *run = (Run *)exception__structor_0(0x24100);
    RaceArcadeSingle__structor_0(run);
    run->u6C = course;
    run->fCF44 = 0.5f;
    func_00110938(course);
    func_00111A40(hud, run);
    func_00111B50(hud, run);
    char *view = D_00622F4C->f4;
    f32 dt = func_00110A18(course);
    Mat4 m;
    s32 running = 1;
    do {
        func_001119A0(run);
        switch (mode->f0) {
        case 1:
            func_0010F770(course);
            func_0010F7D8(course);
            func_00111DC0(hud, run);
            func_00468710(&m, view, dt);
            func_00110AE8(course, &m);
            VCALLI(run, 0x328, 0)
            func_00111E98(run);
            GranTurismo4__LoadingMode("black");
            func_0010AF40(500);
            if (Automobile__GetImplicitCurrentLap(CAR(run->u6C)->f18) >= 2) {
                VCALLI(run, 0x328, 2)
            }
            GranTurismo4__LoadingMode("race-end");
            hud->f46C = 1;
            break;
        case 14:
            func_0010F770(course);
            func_0010F7D8(course);
            func_00111DC0(hud, run);
            func_00468710(&m, view, dt);
            func_00110AE8(course, &m);
            VCALLI(run, 0x328, 1)
            hud->f46C = 2;
            break;
        case 22:
            func_003C0008(course);
            func_0010FE40("option");
            func_003BFFE8(course);
            func_00110460(&guard);
            break;
        case 3:
            if (hud->f46C == 1) {
                VCALLI(run, 0x328, 2)
            } else {
                VCALLI(run, 0x328, 3)
            }
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
    if (run) {
        VCALLI(run, 8, 3)
    }
    func_001242B8(0);
    if (hud) {
        func_00127F70(hud, 3);
    }
    func_0044CB10();
    GranTurismo4__LoadingMode("race-end");
}
