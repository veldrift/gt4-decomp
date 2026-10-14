/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Entry { char pad[8]; };
struct Self {
    char pad0[0x64];
    char *vt;
    char pad68[8];
    char *unk70;
    char pad74[0x125C0 - 0x74];
    char sub125C0[0x22708 - 0x125C0];
    Entry arr[6];
    char pad22738[1];
};
extern char RaceFreePractice__vtable[];
extern "C" s32 RaceSinglePlayer__structor_0(void *);
extern "C" void DynamicsConductorFreePractice__structor_1(void *);
extern "C" void func_00393700(void *);
extern "C" s32 RacePause__structor_0(void *);
extern "C" s32 func_003D7700(void *);
extern "C" s32 func_0033CF48(void);
extern "C" void func_003C31C8(void *, void *);
extern "C" void func_003D8490(void *, void *);

extern "C" int RaceFreePractice__structor_0(char *arg0) {
    Entry *p;
    s32 i;
    RaceSinglePlayer__structor_0(arg0);
    p = (Entry *)(arg0 + 0x22708);
    *(char **)(arg0 + 0x64) = RaceFreePractice__vtable;
    DynamicsConductorFreePractice__structor_1(arg0 + 0x125C0);
    for (i = 5; i != -1; i--) {
        func_00393700(p);
        p++;
    }
    void *a = arg0 + 0x22738;
    void *b = arg0 + 0x22770;
    RacePause__structor_0(a);
    func_003D7700(b);
    *(char **)(arg0 + 0x70) = arg0 + 0x125C0;
    s32 v = 0xC;
    if (func_0033CF48() == 0) {
        char *c = arg0 + 0xE350;
        func_003C31C8(a, c);
        func_003D8490(b, c);
    }
    *(s32 *)(arg0 + 0xD68) = v;
}
