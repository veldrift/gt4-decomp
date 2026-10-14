struct Entry { void *value; int aux; };
struct Table { Entry entries[8]; int capacity, count; };
extern "C" void func_0052D8B0(int, void *);
extern "C" void func_0052B488(int ctx, Table *table) {
    int i = 0;
    if (table->count > 0) {
        Entry *p = table->entries;
        do {
            if (p->value != 0) {
                func_0052D8B0(ctx, p->value);
                p->value = 0;
            }
            ++i;
            ++p;
        } while (i < table->count);
    }
    table->count = 0;
    table->capacity = 0;
}
