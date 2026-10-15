/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Header {
    unsigned int unknown0;
    unsigned short flags, unknown6;
    unsigned int count, unknownC;
    char *entryData() { return (char *)(this + 1); }
    char *recordData(char *data, unsigned int n) { return data + n * 8; }
    unsigned short recordFlag() { return flags & 1; }

};
struct Table {
    Header *header;
    int unknown4;
    char *entries, *records, *first, *second, *relative, *relativeData, *end;
    void initialize(Header *source) {
        header = source;
        char *data = source->entryData();
        unsigned int count = source->count;
        entries = data;
        char *base = source->recordData(data,count);
        unsigned short flags = source->recordFlag();
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
