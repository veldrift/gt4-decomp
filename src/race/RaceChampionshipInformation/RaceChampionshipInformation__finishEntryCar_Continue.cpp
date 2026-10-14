/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Item { char pad[0x3444]; s32 f3444; };
struct List { s32 count; char pad4[4]; Item **items; };
struct Obj { char pad[0x60]; List *list; };
extern "C" void RaceOrganization__defaultPosition(Obj *);
extern "C" void func_004452F8(void *, void *);

extern "C" void RaceChampionshipInformation__finishEntryCar_Continue(char *a, Obj *o) {
    s32 i = 1;
    s32 n = o->list->count;
    for (; i < n; i++) {
        func_004452F8((char *)o->list->items[i] + 0x20, a + i * 0x188 + 0x180);
    }
    i = 0;
    RaceOrganization__defaultPosition(o);
    for (; i < n; i++) {
        o->list->items[i]->f3444 = *(s32 *)(a + 0x2FC + i * 0x188);
    }
    for (i = 0; i < n; i++) {
    }
}
