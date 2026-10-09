struct Entry {short delta;short index;void (*fn)(void *);};
struct Inner {char pad[0xA8];Entry *table;};
struct Obj {char pad[0xE8];Inner *inner;char gap[0x1D8-0xEC];int busy;};
extern "C" void func_00578B10(int);
extern "C" void func_001565F8(Obj *self) {
    Inner *inner=self->inner;
    if(!inner) return;
    Entry *entry=(Entry *)((char *)inner->table+0x20);
    entry->fn((char *)inner+entry->delta);
while(self->busy) func_00578B10(0x3E80);}
