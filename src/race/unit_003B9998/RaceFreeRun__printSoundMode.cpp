typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj {
    char pad0[0x64];
    char *f64;
};

extern "C" void RaceDisplay__printReplayMode(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern "C" s32 *DisplayRText__rtext_ptrs_;

extern "C" void RaceFreeRun__printSoundMode(char *arg0) {
    char *s0 = arg0;
    Obj *o = (Obj *)arg0;
    s32 s1 = 0x1A;
    VEntry *e = (VEntry *)(o->f64 + 0x400);
    if (e->fn(s0 + e->delta) != 0) {
        s1 = 0x19;
    } else {
        s32 v = *(s32 *)(s0 + 0x24698);
        s1 = (v != 0) ? 0x1C : 0x1A;
    }
    RaceDisplay__printReplayMode((s32)(s0 + 0x1F308), DisplayRText__rtext_ptrs_[s1], 0, 0);
}
