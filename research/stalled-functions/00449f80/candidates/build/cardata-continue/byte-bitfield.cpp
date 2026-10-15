struct Entry { unsigned int value:8; unsigned int remaining:24; char unknown[12]; }; struct Header { char unknown[16]; Entry entries[1]; }; struct Table { void *unknown0,*unknown4; Header *header; };
extern "C" long func_00449F80(Table *table, int index) { return table->header->entries[index].value; }
