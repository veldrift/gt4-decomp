/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x3F44]; int count; int entries[1]; };
extern "C" char *func_004F9F18(Obj *, int);
extern "C" int func_0057F238(const char *, const char *) throw();
extern "C" int func_004F8348(Obj *self, const char *name) {
    int i = 0;
    if (self->count > 0) {
        int *p = self->entries;
        do {
            int id = *p++;
            char *v = func_004F9F18(self, id);
            if (v != 0 && func_0057F238(v + 4, name) == 0) return i;
            i++;
        } while (i < self->count);
    }
    return -1;
}
