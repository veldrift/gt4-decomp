/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Item { char pad[0x20]; };
struct List { s32 count; s32 pad4; Item **items; };
struct B { char pad[0x60]; List *list; };
struct Slot { char b[0x188]; };
struct A { char pad[0x178]; s32 f178; s32 pad17c; Slot slots[1]; };
extern "C" void RaceOrganization__defaultPosition(void *);
extern "C" void RaceOrganization__movePosition(void *, s32, s32);
extern "C" void func_003EE9F8(void *, void *);
extern "C" void func_003EECE8(void *, void *);
extern "C" void func_004452F8(void *, void *);
extern "C" void RaceChampionshipInformation__finishEntryCar_FirstSession(A *self, B *arg) {
    s32 n = arg->list->count;
    if (self->f178) {
        s32 i;
        for (i = 1; i < n; i++)
            func_004452F8((char *)arg->list->items[i] + 0x20, &self->slots[i]);
        RaceOrganization__defaultPosition(arg);
        func_003EE9F8(self, arg);
        for (i = 0; i < n; i++) { }
    } else {
        func_003EECE8(self, arg);
        RaceOrganization__defaultPosition(arg);
        RaceOrganization__movePosition(arg, 0, n - 1);
    }
}
