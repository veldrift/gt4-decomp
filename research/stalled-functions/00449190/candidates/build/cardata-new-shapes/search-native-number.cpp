/* compiler: ee-gcc2.96-nogcse */
typedef unsigned int u32;
struct Entry { u32 number; int offset; };
struct TableData { int magic; unsigned short flags; unsigned short version; int count; int unknownC; Entry entries[1]; };
struct Table {
    TableData *data;
    int row_count() const { return data->count; }
    long row_number(int index) const {
        TableData *table = data;
        Entry *entries = table->entries;
        long value = -1;
        if (index >= 0 && index < table->count) value = (int)entries[index].number;
        return value;
    }
};
extern "C" int SPEC_DATABASE__DatabaseTable__searchNumber(Table *self, unsigned long number) {
    int low = -1;
    int high = self->row_count();
    if (high <= 0) return -1;
    do {
        int middle = (low + high) >> 1;
        long value = self->row_number(middle);
        if (value == number) return middle;
        if ((unsigned long)value < number) low = middle;
        else high = middle;
    } while (low + 1 != high);
    return -1;
}

