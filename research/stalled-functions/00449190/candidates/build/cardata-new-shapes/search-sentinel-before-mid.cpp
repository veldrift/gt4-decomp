/* compiler: ee-gcc2.96-nogcse */
typedef unsigned int u32;
struct Entry { u32 number; int offset; };
struct TableData { int magic; unsigned short flags, version; int count, reserved; Entry entries[1]; };
struct Table { TableData *data; };
extern "C" int SPEC_DATABASE__DatabaseTable__searchNumber(Table *self, u32 number) {
    int low = -1;
    int high = self->data->count;
    if (high <= 0) return -1;
    do {
        u32 value = (u32)-1;
        int middle = (low + high) >> 1;
        TableData *table = self->data;
        Entry *entries = table->entries;
        if (middle >= 0 && middle < table->count) value = entries[middle].number;
        if (value == number) return middle;
        if (value < number) low = middle;
        else high = middle;
    } while (low + 1 != high);
    return -1;
}
