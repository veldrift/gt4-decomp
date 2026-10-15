/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Header { unsigned int magic; unsigned short flags, version; unsigned int count, reserved; };
struct Table {
    Header *header; int reserved;
    char *entries, *records, *first, *second, *relative, *relativeData, *end;
    static void initializeRecords(char *base, unsigned short flags, Table *table) {
        char *firstData = base + 8;
        char *secondData = base + 0x208;
        if (flags) {
            table->records = base; table->first = firstData; table->second = secondData;
            char *relativeBase = base + *(int *)base;
            table->relative = relativeBase;
            table->relativeData = relativeBase + 8;
            table->end = relativeBase + *(int *)relativeBase;
            return;
        }
        table->end = base;
    }
};
extern "C" void func_004490F8(Table *table, Header *source) {
    table->header = source;
    unsigned int count = source->count;
    char *data = (char *)(source + 1);
    table->entries = data;
    char *base = data + count * 8;
    unsigned short flags = source->flags & 1;
    Table::initializeRecords(base, flags, table);
}
