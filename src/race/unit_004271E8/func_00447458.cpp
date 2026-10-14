typedef long long s64;
struct O { char pad[0xA8]; char *tab; };
extern "C" int SPEC_DATABASE__RaceSpec__getEnemyCount(void *);
extern "C" s64 func_00447458(O *self, int i) {
    int ok = i < SPEC_DATABASE__RaceSpec__getEnemyCount(self);
    i = i * 2 + 2;
    s64 r = -1;
    if (!ok) return r;
    r = *(s64 *)((i * 8) + self->tab);
    return r;
}
