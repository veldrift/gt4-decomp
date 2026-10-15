/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Header { unsigned int magic; unsigned short flags, version; unsigned int count, reserved; };
struct SectionEnd { char *value; SectionEnd(char *p):value(p){} };
struct Table {
    Header *header; int reserved;
    char *entries, *records, *first, *second, *relative, *relativeData, *end;
    SectionEnd initializeRecords(char *base, unsigned short flags) {
        char *firstData = base + 8;
        char *secondData = base + 0x208;
        if (flags) {
            records = base; first = firstData; second = secondData;
            char *relativeBase = base + *(int *)base;
            relative = relativeBase;
            relativeData = relativeBase + 8;
            return relativeBase + *(int *)relativeBase;
        }
        return base;
    }
};
extern "C" void func_004490F8(Table *table, Header *source) {
    table->header = source;
    unsigned int count = source->count;
    char *data = (char *)(source + 1);
    table->entries = data;
    char *base = data + count * 8;
    unsigned short flags = source->flags & 1;
    table->end = table->initializeRecords(base, flags).value;
}
