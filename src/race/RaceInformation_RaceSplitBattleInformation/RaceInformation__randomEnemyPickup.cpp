/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Sub {
    char pad0[8];
    char **tab;
};

struct Info {
    char pad0[0x60];
    Sub *sub;
};

extern char RaceInformation__random[];

extern "C" s32 SPEC_DATABASE__RaceSpec__getEnemyCount(void *);
extern "C" s32 SPEC_DATABASE__RaceSpec__getEnemyCode(void *, s32);
extern "C" s32 SPEC_DATABASE__RaceSpec__getEnemy(void *, s32, void *);
extern "C" s32 SPEC_DATABASE__IsDisabledCar(s32);
extern "C" f32 func_00578598(void *);
extern "C" void func_0040AA48(Info *, void *);

static inline s32 *next(s32 *p) { return p + 1; }

extern "C" void RaceInformation__randomEnemyPickup(void *spec, Info *info, s32 *enemies, s32 count) {
    s32 n = SPEC_DATABASE__RaceSpec__getEnemyCount(spec);
    if (count > 0) {
        s32 *used = (s32 *)__builtin_alloca(n * 4);
        s32 remaining = n;
        s32 i;
        for (i = 0; i < n; i++) {
            s32 d = SPEC_DATABASE__IsDisabledCar(SPEC_DATABASE__RaceSpec__getEnemyCode(spec, i));
            used[i] = d;
            if (d != 0) remaining--;
        }
        if (count > 0) {
            f32 fn = (f32)n;
            s32 *e = enemies;
            for (i = count; i != 0; i--) {
                char *p = info->sub->tab[*e] + 0x20;
                s32 idx = (s32)(func_00578598(RaceInformation__random) * fn);
                if (remaining != 0) {
                    while (used[idx] != 0) {
                        idx = (idx + 1) % n;
                    }
                    used[idx] = 1;
                    remaining--;
                }
                SPEC_DATABASE__RaceSpec__getEnemy(spec, idx, p);
                e = next(e);
            }
        }
        func_0040AA48(info, RaceInformation__random);
    }
}
