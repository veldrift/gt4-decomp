typedef int s32;

struct VEntryFloat {
    short delta;
    short index;
    void (*fn)(void *, void *, float);
};
struct VEntryVoid { short delta; short index; void (*fn)(void *, void *); };

extern "C" void func_004AB040(s32);
extern "C" void func_004A1638(s32);
extern void *D_00618840;
struct Target { char pad[0x1C]; float width; float height; };
extern Target *PDISTD__global_font_manager;
extern char D_0061850C[];

extern "C" void func_0012BFE0(void) {
    func_004AB040(0x12);
    char *base = D_0061850C;
    s32 index = *(s32 *)(base + 0x78);
    s32 entryOffset = index << 4;
    entryOffset -= index;
    entryOffset <<= 2;
    char *entryData = base + entryOffset;
    void *global = &D_00618840;
    void *obj = *(void **)global;
    VEntryFloat *entry = (VEntryFloat *)((char *)*(void **)((char *)obj + 0x64) + 0x348);
    entry->fn((char *)obj + entry->delta, entryData, 0.0f);
    obj = *(void **)global;
    VEntryVoid *entry2 = (VEntryVoid *)((char *)*(void **)((char *)obj + 0x64) + 0x358);
    entry2->fn((char *)obj + entry2->delta, entryData);
    obj = *(void **)global;
    VEntryVoid *entry3 = (VEntryVoid *)((char *)*(void **)((char *)obj + 0x64) + 0x360);
    entry3->fn((char *)obj + entry3->delta, entryData);
    PDISTD__global_font_manager->width = 640.0f;
    PDISTD__global_font_manager->height = 480.0f;
    func_004A1638(0x12);
}
