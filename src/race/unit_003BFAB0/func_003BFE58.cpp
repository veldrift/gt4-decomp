/* compiler: ee-gcc2.96-nsa-nosib */
struct List { int count; int pad4; void **items; };
struct Obj { char pad[0x60]; List *list; };
extern "C" void RaceEntryCar__clear(void *, int);
extern "C" void func_003BFE58(Obj *self, int index) {
    int n = self->list->count;
    if (index < n) {
        if (index >= 0) {
            RaceEntryCar__clear(self->list->items[index], 1);
            return;
        }
        for (int i = 0; i < n; i++)
            RaceEntryCar__clear(self->list->items[i], 1);
    }
}
