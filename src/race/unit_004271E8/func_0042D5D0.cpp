/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry {
    char *name;
    char pad[12];
};

struct Table {
    char pad[0x16];
    unsigned short count;
    char pad2[0x1C - 0x18];
    Entry *entries;
};

extern "C" int func_0057F238(const char *a, const char *b) throw();
extern "C" float func_0042D8C0(Entry *e, float lo, float hi);

extern "C" float func_0042D5D0(Table *t, const char *name, float lo, float hi)
{
    int i = 0;
    if (i < t->count) {
        do {
            Entry *p_entries = &t->entries[i];
            if (!func_0057F238(p_entries->name, name))
                return func_0042D8C0(t->entries + i, lo, hi);
            i++;
        } while (i < t->count);
    }
    return 0.0f;
}
