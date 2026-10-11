struct VEntry { short delta; short index; void (*fn)(void *, float); };
struct Obj { char pad[8]; VEntry *vtbl; };
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" float func_00452F70(void *);

extern "C" float RaceCarModel__virtual_39(Obj *arg0, float value) {
    func_004A53F8();
    VEntry *entry = (VEntry *)((char *)arg0->vtbl + 0x108);
    entry->fn((char *)arg0 + entry->delta, value);
    float result = func_00452F70((char *)arg0 + 0x18);
    func_004A5400();
    return result;
}
