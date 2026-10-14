/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Rec { s64 u0; s64 u8; s32 u10; s32 u14; s32 u18; void *u1C; };

struct VEntry { short delta; short index; void (*fn)(void *); };
struct VEntryI { short delta; short index; void (*fn)(void *, s32); };
struct VEntryR { short delta; short index; s32 (*fn)(void *); };

struct Drv {
    char pad0[0x5B6];
    u8 f5B6;
    char pad5B7[0x6CC - 0x5B7];
    f32 f6CC;
};
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
    char pad70[0xCE0 - 0x70];
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
    char pad470[0x498 - 0x470];
    u32 f498;
    s32 f49C;
};

struct Stats { char pad[0x70]; s64 f70; s64 f78; };
struct Game {
    char pad0[0x348];
    Stats f348;
    char pad3C8[0x3D0 - 0x3C8];
    u8 f3D0;
    char pad3D1[0x568 - 0x3D1];
    char f568[0x3A368 - 0x568];
    char f3A368[4];
};

struct Info { char b[0x2C0]; };

extern Game *D_00622F4C;

extern "C" void func_0010AF40(int);
extern "C" void func_0010F770(Course *);
extern "C" void func_0010F848(Course *);
extern "C" void func_0010F948(Course *);
extern "C" void func_0010FA58(Course *, u32 *, u32 *);
extern "C" void func_0010FE40(const char *);
extern "C" void func_001103C8(void *);
extern "C" void func_001103E0(void *, s32);
extern "C" void func_00110460(void *);
extern "C" void func_00115F58(Info *);
extern "C" void func_00115FE8(Run *);
extern "C" void func_00116070(Hud *, Run *);
extern "C" void func_001161A0(Hud *, Run *);
extern "C" void func_001242B8(Hud *);
extern "C" void func_00127E60(Hud *);
extern "C" void func_00127F70(Hud *, int);
extern "C" Rec *func_001D3A60(void);
extern "C" u32 func_0035E3F0(Drv *);
extern "C" void func_00387EF0(Run *, int, int);
extern "C" Course *func_003B7850(Info *);
extern "C" void RaceMachineTestInformation__structor_0(Info *);
extern "C" void RaceMachineTestInformation__structor_1(Info *, s32);
extern "C" void RaceMachineTest__structor_0(Run *);
extern "C" void func_003BE128(Run *);
extern "C" void func_003BFFE8(Course *);
extern "C" void func_003C0008(Course *);
extern "C" void func_0042F448(char *, char *, int, u8, u8, int);
extern "C" void func_0042FC98(char *, const char *);
extern "C" s64 func_004454C0(char *);
extern "C" char *func_004472A0(void *);
extern "C" s64 SPEC_DATABASE__RaceSpec__getCourseCode(void *);
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
    InfoObj() { RaceMachineTestInformation__structor_0(&i); }
    ~InfoObj() { RaceMachineTestInformation__structor_1(&i, 2); }
};

#define CAR(c) ((c)->p60->p8->p0)

#define VCALL(r, off) { VEntry *e = (VEntry *)((r)->vtbl + (off)); e->fn((char *)(r) + e->delta); }
#define VCALLI(r, off, arg) { VEntryI *e = (VEntryI *)((r)->vtbl + (off)); e->fn((char *)(r) + e->delta, (arg)); }

extern "C" void func_00115A90(void) {
    func_0010AF40(0);
    Guard guard;
    func_0044CA98(0x30000, 2, 6, 0xBC8000);
    u32 best = 0x157529FF;
    s32 flag = 0;
    InfoObj info;
    func_00115F58(&info.i);
    Hud *hud = (Hud *)exception__structor_0(0x4F8);
    func_00127E60(hud);
    func_001242B8(hud);
    Course *course = func_003B7850(&info.i);
    CAR(course)->f345C = D_00622F4C->f3D0;
    Run *run = (Run *)exception__structor_0(0x23740);
    RaceMachineTest__structor_0(run);
    run->u6C = course;
    func_003BE128(run);
    run->fCF44 = 0.5f;
    run->fD60 = 0x1D;
    run->fD64 = 0x1E;
    s32 state = 0;
    func_00387EF0(run, 0, 1);
    VCALL(run, 0x2C0)
    run->fF050 = 0;
    func_00116070(hud, run);
    func_004454C0((char *)CAR(course) + 0x20);
    SPEC_DATABASE__RaceSpec__getCourseCode(course->p70);
    s32 running = 1;
    s32 top = 0;
    do {
        s32 mode;
        if (state == 4) {
            mode = 1;
        } else {
            state = 0;
            func_00115FE8(run);
            mode = hud->f0;
        }
        switch (mode) {
        case 1:
            func_0010F948(course);
            func_0010F770(course);
            func_0010F848(course);
            if (flag) {
                flag = 0;
                VCALL(run, 0x168)
            }
            VCALLI(run, 0x328, 0)
            state = run->fCE0;
            func_0010FA58(course, &guard.a, &guard.b);
            if (CAR(course)->f18->f5B6) {
                VEntryR *e = (VEntryR *)(run->vtbl + 0x2F8);
                if (e->fn((char *)run + e->delta) == 0x12) {
                    s32 v = (s32)((CAR(course)->f18->f6CC * 60.0f * 60.0f + 5.0f) / 10.0f);
                    if (top < v) {
                        top = v;
                    }
                } else {
                    u32 t = func_0035E3F0(CAR(course)->f18);
                    if (t < best) {
                        best = t;
                    }
                }
                hud->f498 = best;
                hud->f49C = top;
                func_001161A0(hud, run);
            }
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
    char *rec = D_00622F4C->f568;
    func_0042F448(rec, func_004472A0(course->p70), 6, 0xF, 0xE, 0x157529FF);
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
    {
        Stats *s = &D_00622F4C->f348;
        s->f70 += guard.a;
    }
}
