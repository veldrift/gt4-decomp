/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VEntry {
    s16 delta;
    s16 pad;
    void (*fn)(void *, s32, s32 *, s32);
};
struct VTbl {
    char pad[0x78];
    VEntry e;
};
struct Obj12C {
    char pad0[0x12C];
    VTbl *vt;
};
extern "C" void RaceInformation__randomEnemyPickup_2(char *self, s32 arg1, s32 start, s32 end) {
    s32 n = end - start;
    if (n > 0) {
        s32 *arr = (s32 *)__builtin_alloca(n * 4);
        for (s32 i = 0; i < n; i++) {
            arr[i] = i + start;
        }
        VEntry *e = &((Obj12C *)self)->vt->e;
        e->fn(self + e->delta, arg1, arr, n);
    }
}
