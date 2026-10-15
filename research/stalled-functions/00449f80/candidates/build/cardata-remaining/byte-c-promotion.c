struct Entry { unsigned char value; char unknown[15]; };
struct Header { char unknown[16]; struct Entry entries[1]; };
struct Table { void *unknown0, *unknown4; struct Header *header; };
long long func_00449F80(struct Table *table, int index) {
    struct Header *header = table->header;
    struct Entry *entry = &header->entries[index];
    return (int)entry->value;
}
