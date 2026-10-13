struct VEntry { short delta; short index; int (*fn)(void *); };
struct Obj { int unk0; VEntry *vt; };
extern "C" int D_00618A00;
extern "C" void MMemoryCardManager__setExistValidGameData(void *, void *, Obj **arg2) {
    Obj *o = *arg2;
    VEntry *e = (VEntry *)((char *)o->vt + 0x58);
    D_00618A00 = e->fn((char *)o + e->delta) != 0;
}
