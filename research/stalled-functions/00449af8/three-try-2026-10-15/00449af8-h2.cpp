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
            unsigned int offset = (unsigned int)index << 3;
            result = *(int *)((unsigned int)entries + offset + 4);
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
    Header *header=self->header;
    int count=header->count;
    for(int i=0;i<count;++i) {
        int key=-1;
        Entry *entries=header->entries;
        if(i>=0 && i<header->count) key=entries[i].key;
        if(wanted==key) return (char *)(entries+header->count)+entries[i].offset+2;
    }
    return 0;
}
