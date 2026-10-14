/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef long s64;

struct Sub { char pad[0x58]; u32 f58; u32 f5C; };
struct Self {
    char pad0[0x6C];
    void *f6C;
    char pad70[0xE460 - 0x70];
    s64 fE460;
    s32 fE468;
    char padE46C[0xE488 - 0xE46C];
    Sub sub;
    char pad2[0xF374 - 0xE488 - sizeof(Sub)];
    s32 fF374;
    char padF378[4];
    s32 fF37C;
    char padF380[0x1FA4C - 0xF380];
    char fFA4C[4];
};

extern char D_00645570[];
extern s32 D_0064652C;

extern "C" s32 RacePS2Base__updateCommon(void *);
extern "C" void func_004FAF28(void *);
extern "C" void RacePS2Base__raceEnd(void *);
extern "C" void RaceDisplay__update(void *, float);
extern "C" void RaceOrganization__raceRealTimeUpdate(void *, float);
extern "C" s32 RaceLanControlManager__virtual_04(void *) throw();
extern "C" s64 func_00578560(void);
extern "C" void func_00337260(void *) throw();

static inline Sub *subp(Self *self) { return (Sub *)((char *)self + 0xE488); }

extern "C" s32 RaceLanBattle__virtual_72(Self *self) {
    if (!RacePS2Base__updateCommon(self)) return 0;
    if (self->fF37C != 0 && !(subp(self)->f58 < subp(self)->f5C)) {
        func_004FAF28(D_00645570);
        RacePS2Base__raceEnd(self);
        return 0;
    }
    if (self->fE468 != 0) {
        float f = 0x1.111110p-6f;
        RaceDisplay__update((char *)self + 0x1FA4C, f);
        RaceOrganization__raceRealTimeUpdate(self->f6C, f);
        return 0;
    }
    if (RaceLanControlManager__virtual_04(subp(self)) == 0) {
        if ((func_00578560() - self->fE460) > 0x4C4B3F || D_0064652C != 0) {
            func_00337260(self);
        }
        return 0;
    } else {
        self->fF374 = 1;
        self->fE460 = func_00578560();
        return 1;
    }
}
