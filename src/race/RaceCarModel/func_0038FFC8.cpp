struct VEntry { short delta; short index; void *(*fn)(void *); };
struct Obj { char pad0[8]; VEntry *vtbl; char padC[0x1660]; int field166C; };
extern "C" void func_00458238(void *);
extern "C" void func_00452FA0(void *, void *, void *);

extern "C" void func_0038FFC8(Obj *arg0, void *arg1) {
    if (arg1 != 0) func_00458238(arg1);
    VEntry *entry = (VEntry *)((char *)arg0->vtbl + 0x38);
    void *geometry = entry->fn((char *)arg0 + entry->delta);
    func_00452FA0((char *)arg0 + 0x18, geometry, arg1);
    arg0->field166C = 1;
}
