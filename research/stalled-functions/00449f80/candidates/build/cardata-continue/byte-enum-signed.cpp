struct Entry { unsigned char value; char unknown[15]; }; struct Header { char unknown[16]; Entry entries[1]; }; struct Table { void *unknown0,*unknown4; Header *header; };
extern "C" long func_00449F80(Table *table, int index) { enum Value { Minimum=-1, Maximum=255 }; return (Value)table->header->entries[index].value; }
