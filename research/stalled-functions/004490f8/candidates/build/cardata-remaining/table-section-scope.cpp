/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Header { unsigned int magic; unsigned short flags, version; unsigned int count, reserved; };
struct Section {
    char *records, *first, *second, *relative, *relativeData;
    char *initialize(char *base, unsigned short flags) {
        char *firstData = base + 8;
        char *secondData = base + 0x208;
        if (flags) {
            records = base;
            first = firstData;
            second = secondData;
            char *relativeBase = base + *(int *)base;
            relative = relativeBase;
            relativeData = relativeBase + 8;
            return relativeBase + *(int *)relativeBase;
        }
        return base;
    }
};
struct Table { Header *header; int reserved; char *entries; Section section; char *end; };
extern "C" void func_004490F8(Table *table, Header *source) {
    table->header = source;
    unsigned int count = source->count;
    char *data = (char *)(source + 1);
    table->entries = data;
    table->end = table->section.initialize(data + count * 8, source->flags & 1);
}
