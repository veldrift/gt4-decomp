/* compiler: ee-gcc2.9-991111 */
struct Entry { unsigned char value; char unknown[15]; };
struct Header { char unknown[16]; Entry entries[1]; };
struct Table { void *unknown0, *unknown4; Header *header; };
extern "C" long func_00449F80(Table *table, int index) {
    Header *header = table->header;
    Entry *entry = &header->entries[index];
    return entry->value;
}
