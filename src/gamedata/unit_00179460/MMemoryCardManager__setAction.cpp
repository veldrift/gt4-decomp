struct VEntry { short delta; short index; int (*fn)(void *); };
struct Obj { int unk0; VEntry *vt; };
extern "C" int *func_001D3AF8();
extern "C" void MMemoryCardManager__setAction(void *, void *, Obj **arg2) {
    int *p = func_001D3AF8();
    Obj *o = *arg2;
    VEntry *e = (VEntry *)((char *)o->vt + 0x58);
    *p = e->fn((char *)o + e->delta) != 0;
}
