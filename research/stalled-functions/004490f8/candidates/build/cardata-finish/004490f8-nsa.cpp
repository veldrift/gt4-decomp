/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Header {
    unsigned int unknown0;
    unsigned short flags, unknown6;
    unsigned int count, unknownC;
};
struct Table {
    Header *header;
    int unknown4;
    char *entries, *records, *first, *second, *relative, *relativeData, *end;
    void initialize(Header *source) {
        header = source;
        entries = (char *)(source + 1);
        char *base = entries + source->count * 8;
        unsigned short flags = source->flags & 1;
        char *firstData = base + 8;
        char *secondData = base + 0x208;
        if (flags) {
            records = base;
            first = firstData;
            second = secondData;
            char *relativeBase = base + *(int *)base;
            relative = relativeBase;
            relativeData = relativeBase + 8;
            end = relativeBase + *(int *)relativeBase;
        } else end = base;
    }
};
extern "C" void func_004490F8(Table *table, Header *source) {
    table->initialize(source);
}
