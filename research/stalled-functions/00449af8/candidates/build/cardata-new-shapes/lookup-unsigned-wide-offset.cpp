/* compiler: ee-gcc2.96-nogcse */
struct Entry { int offset, key; };
struct Header { int unknown, count, unknown8, unknownC; Entry entries[1]; };
struct Table {
    Header *header;
    int rowKey(int index) const {
        Header *data = header;
        Entry *entries = data->entries;
        int result = -1;
        if (index >= 0 && index < data->count) {
            unsigned int offset = (unsigned long)(unsigned int)index * 8;
            result = ((Entry *)((char *)entries + offset))->key;
        }
        return result;
    }
    char *rowValue(int index) const {
        Header *data = header;
        Entry *entries = data->entries;
        return (char *)(entries + data->count) + entries[index].offset + 2;
    }
};
extern "C" char *func_00449AF8(Table *self, int wanted) {
    int count = self->header->count;
    if (count <= 0) return 0;
    for (int i = 0; i < count; ++i) {
        if (wanted == self->rowKey(i)) return self->rowValue(i);
    }
    return 0;
}
