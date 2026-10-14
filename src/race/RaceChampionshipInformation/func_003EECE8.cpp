/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *, void *, int, int); };
struct Self { char pad[0x12c]; VEntry *vt; char pad130[0x48]; int f178; };
struct List { int count; int pad; char **items; };
struct Other { char pad[0x60]; List *list; };
extern "C" void func_004452F8(void *, void *);
extern "C" void func_003EECE8(Self *self, Other *other) {
    int i = 1;
    VEntry *e = &self->vt[16];
    int n = other->list->count;
    e->fn((char *)self + e->delta, other, 1, n);
    if (i < n) {
        char *cur = (char *)self + 0x308;
        do {
            func_004452F8(cur, other->list->items[i] + 0x20);
            cur += 0x188;
            i++;
        } while (i < n);
    }
    self->f178 = 1;
}
