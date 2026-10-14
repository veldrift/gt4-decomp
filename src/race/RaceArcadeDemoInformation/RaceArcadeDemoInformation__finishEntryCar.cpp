/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef long long s64;
struct VEntry {
    s16 delta;
    s16 pad;
    void (*fn)(void *, void *, s32, s32);
};
struct VObj { char pad0[0x80]; };
struct Self {
    char pad0[0x12C];
    char *obj;
    char pad130[0x2C0 - 0x130];
    s64 unk2C0;
    s32 unk2C8;
};
struct Arg1 {
    char pad0[0x60];
    s32 *unk60;
};
extern "C" void RaceOrganization__defaultPosition(void *);
extern "C" void RaceOrganization__movePosition(void *, s32, s32);

extern "C" void RaceArcadeDemoInformation__finishEntryCar(Self *arg0, Arg1 *arg1) {
    char *o = arg0->obj;
    s32 *s2 = arg1->unk60;
    VEntry *e = (VEntry *)(o + 0x80);
    e->fn((char *)arg0 + e->delta, arg1, arg0->unk2C0 != 0, *s2);
    RaceOrganization__defaultPosition(arg1);
    s32 v = arg0->unk2C8;
    if (v != 0) {
        RaceOrganization__movePosition(arg1, 0, v - 1);
        return;
    }
    RaceOrganization__movePosition(arg1, 0, *s2 - 1);
}
