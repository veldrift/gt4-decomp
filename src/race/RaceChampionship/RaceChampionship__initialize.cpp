/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
extern "C" void func_0038B7C0(void *, void *);
extern "C" void func_0038B8D8(void *, void *);
extern "C" void func_0038B990(void *, void *);
extern "C" void func_0038BA90(void *, void *);
extern "C" void func_0038BAB0(void *, void *);
extern "C" void RaceDisplay__virtual_06(void *, s32);
extern "C" void RaceSinglePlayer__initialize(void *, s32);
extern "C" void func_003DF970(void *, void *);

extern "C" void RaceChampionship__initialize(char *a, s32 arg1) {
    char *s3 = a + 0xE440;
    func_0038B7C0(a, 0);
    func_0038B8D8(a, 0);
    char *s2 = a + 0x22708;
    func_0038BAB0(a, 0);
    func_0038B990(a, 0);
    func_0038BA90(a, 0);
    char *s0 = a + 0x22738;
    RaceSinglePlayer__initialize(a, arg1);
    s32 v = *(s32 *)(a + 0xCC8);
    char *c = a + 0x22C9C;
    s32 f = 0;
    if ((u32)(v - 2) < 2U) {
        func_0038B7C0(a, 0);
        func_0038BAB0(a, 0);
        func_0038B990(a, 0);
        func_0038BA90(a, 0);
        func_0038B8D8(a, 0);
    } else {
        if (v == 1 || v == 3) f = 1;
        *(s32 *)(c + 0x34) = f;
        func_0038B7C0(a, a + 0x22C9C);
        func_0038B990(a, *(void **)(a + 0xE408));
        func_0038BAB0(a, a + 0x22CD4);
        *(char **)(*(char **)(a + 0xE424) + 0x14) = s2;
        func_0038BA90(a, *(void **)(a + 0xE410));
        func_0038B8D8(a, s0);
        func_003DF970(s0, s2);
    }
    RaceDisplay__virtual_06(s3, 1);
    *(char **)(s3 + 8) = a + 0x22708;
}
