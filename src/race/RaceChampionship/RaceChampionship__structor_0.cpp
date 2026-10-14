/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern char RaceChampionship__vtable[];
extern char ResultChampionship__vtable[];
extern "C" s32 func_0033CF48(void);
extern "C" void DynamicsConductorSinglePlayer__structor_1(void *);
extern "C" void func_00393700(void *);
extern "C" void func_003BAB90(void *);
extern "C" void RacePause__structor_0(void *);
extern "C" void func_003C31C8(void *, void *);
extern "C" s32 RaceSinglePlayer__structor_0(void);
extern "C" void func_003D7700(void *);
extern "C" void func_003D8490(void *, void *);
extern "C" void func_003DCA28(void *);
extern "C" void func_003DD4B8(void *, void *);
extern "C" s32 ResultArcade__structor_0(void *);
extern "C" void func_003DF898(void *, void *);

extern "C" int RaceChampionship__structor_0(char *arg0) {
    char *p = arg0 + 0x22708;
    s32 i = 5;
    RaceSinglePlayer__structor_0();
    *(char **)(arg0 + 0x64) = RaceChampionship__vtable;
    DynamicsConductorSinglePlayer__structor_1(arg0 + 0x125C0);
    do {
        func_00393700(p);
        p += 8;
    } while (--i != -1);
    char *s4 = arg0 + 0x22738;
    char *s3 = arg0 + 0x22C9C;
    char *s5 = arg0 + 0x22CD4;
    ResultArcade__structor_0(s4);
    *(char **)(s4 + 0xC) = ResultChampionship__vtable;
    *(s32 *)(s4 + 0x560) = 0;
    char *s1 = arg0 + 0x24018;
    char *s0 = arg0 + 0x24120;
    RacePause__structor_0(s3);
    func_003D7700(s5);
    func_003DCA28(s1);
    func_003BAB90(s0);
    *(char **)(arg0 + 0xE408) = s1;
    *(char **)(arg0 + 0xE410) = s0;
    *(char **)(arg0 + 0x70) = arg0 + 0x125C0;
    if (func_0033CF48() == 0) {
        char *b = arg0 + 0xE350;
        *(s32 *)(s3 + 0x2C) = 1;
        func_003C31C8(s3, b);
        func_003D8490(s5, b);
        func_003DD4B8(s1, b);
        func_003DF898(s4, b);
    }
    *(s32 *)(arg0 + 0xD68) = 0xE;
}
