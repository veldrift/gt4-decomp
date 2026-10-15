enum ByteValue { ByteValue_min = 0, ByteValue_max = 255 };
struct Entry { unsigned char value; char unknown[15]; };
struct Header { char unknown[16]; Entry entries[1]; };
struct Table { void *unknown0, *unknown4; Header *header; };
extern "C" ByteValue func_00449F80(Table *table, int index) {
    return (ByteValue)table->header->entries[index].value;
}
