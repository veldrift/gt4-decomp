struct VEntry { short delta; short index; void (*fn)(void *); };
struct Inner { VEntry *vtbl; };
struct Obj {
    Inner *inner;
    int field4;
    VEntry *vtbl;
    char padC[0x1654];
    void *field1660;
    void *field1664;
};
extern "C" char D_00844368[];
extern "C" void func_00450CB8(void *, void *);

extern "C" void RaceCarModel__virtual_15(Obj *arg0) {
    arg0->field1660 = D_00844368;
    arg0->field1664 = D_00844368;
    Inner *inner = arg0->inner;
    VEntry *entry = (VEntry *)((char *)inner->vtbl + 0x10);
    entry->fn((char *)inner + entry->delta);
    func_00450CB8((char *)arg0 + 0x18, arg0->inner);
    VEntry *last = (VEntry *)((char *)arg0->vtbl + 0x18);
    last->fn((char *)arg0 + last->delta);
}
