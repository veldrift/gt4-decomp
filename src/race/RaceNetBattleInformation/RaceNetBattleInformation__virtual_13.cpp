/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Obj { char pad[0x3444]; s32 f3444; };
struct Info { s32 count; s32 pad4; Obj **arr; };
struct VEntry { s16 delta; s16 index; void (*fn)(void *, void *, void *, s32); };
struct Arg1 { char pad[0x60]; Info *info; };
struct Self {
    char pad0[0x118];
    s32 f118;
    char pad11C[0x12C - 0x11C];
    char *vt;
    char pad130[0xA90 - 0x130];
    char fA90[0x18];
    s32 fAA8;
};

extern s32 D_00646450;
extern "C" void RaceOrganization__defaultPosition(void *);

extern "C" void RaceNetBattleInformation__virtual_13(Self *self, Arg1 *arg1) {
    Info *info = arg1->info;
    VEntry *e = (VEntry *)(self->vt + 0x78);
    e->fn((char *)self + e->delta, arg1, self->fA90, self->fAA8);
    RaceOrganization__defaultPosition(arg1);
    s32 n = info->count;
    s32 a1 = self->f118;
    s32 t0 = 0;
    s32 *tmp = (s32 *)__builtin_alloca(n * 4);
    s32 i = 0;
    if (info->count > 0) {
        s32 lim = D_00646450;
        do {
            s32 v;
            if (i < lim) {
                v = t0++;
            } else {
                v = a1++;
            }
            tmp[i] = v;
            i++;
        } while (i < info->count);
    }
    for (i = 0; i < info->count; i++) {
        arg1->info->arr[i]->f3444 = tmp[i];
    }
}
