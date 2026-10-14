/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long long U64;
typedef unsigned char u8;
struct Entry { short delta, unknown; void (*call)(void *, int); };
struct Course { char unknown0[0x974]; Entry *table; };
struct Cfg { char pad0[0xC0]; int c0; int c4; };
struct Info {
    char unknown0[0x3E]; u8 u3E; char pad3F[4]; u8 u43; char pad44[0xB0 - 0x44]; int b0;
    char pad_b4[0x130 - 0xB4]; char sub130[0x2C0 - 0x130];
    Info() __asm__("func_00339318");
    ~Info() __asm__("func_00339348");
};
struct Battle {
    char unknown0[0x6C]; Course *course; char unknown70[0xCE0 - 0x70]; int state; char unknownCE4[0x22F00 - 0x2C0 - 0xCE4];
    Battle() __asm__("func_00339428");
    ~Battle() __asm__("func_003394F8");
};
extern "C" char D_00645570[];
extern "C" char D_0068D068[];
extern "C" char D_0068D180[];
extern "C" char *D_00622F4C;
extern "C" void func_0044CA98(int, int, int, int);
extern "C" void func_0044CB10();
extern "C" void func_003BB440(Info *, char *);
extern "C" U64 func_00447C78(char *);
extern "C" void RaceSinglePlayerInformation__setCourseCode(Info *, U64);
extern "C" void RaceInformation__setEntryCars(Info *, int);
extern "C" void func_003D63A8(void *, char *);
extern "C" Course *func_003B7850(Info *);
extern "C" void RacePS2Base__play(Battle *, int);
extern "C" void func_0010CEB8() throw();
extern "C" void func_004F6888(void *);
extern "C" void func_0042FC10(char *, char *);
inline void callEntry(void *p, Entry *entry, int arg) { entry->call((char *)p + entry->delta, arg); }

extern "C" void func_0010ED60() {
    func_0044CA98(0x30000, 2, 6, 0xBC8000);
    {
        Info info;
        Course *course;
        func_003BB440(&info, D_00622F4C + 0x44);
        RaceSinglePlayerInformation__setCourseCode(&info, func_00447C78(D_00622F4C + 4));
        Cfg *cfg = (Cfg *)(D_00622F4C + 4);
        int v = cfg->c4;
        info.b0 = (v < 0) ? info.u43 : v;
        int m = cfg->c0;
        RaceInformation__setEntryCars(&info, (info.u3E < m) ? info.u3E : m);
        func_003D63A8(info.sub130, D_00622F4C + 0xD8);
        course = func_003B7850(&info);
        {
            Battle battle;
            battle.course = course;
            RacePS2Base__play(&battle, 0);
            int state = battle.state;
            switch (state) {
            case 0:
            case 1:
                break;
            case 7:
                func_0010CEB8();
                func_0042FC10(D_00622F4C + 0x3A368, D_0068D068);
                break;
            default:
                func_004F6888(D_00645570);
                func_0042FC10(D_00622F4C + 0x3A368, D_0068D180);
                break;
            }
        }
        if (course) callEntry(course, course->table + 1, 3);
    }
    func_0044CB10();
}
