/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void *RaceRoundMeterBase__structor_0(void *);
extern "C" void func_003EC5A8(char *, const char *);
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern char RaceRoundTachometerBase__vtable[];
extern char D_006A3CE8[];

extern "C" int RaceRoundTachometerBase__structor_0(char *arg0) {
    RaceRoundMeterBase__structor_0(arg0);
    *(char **)(arg0 + 0x14) = RaceRoundTachometerBase__vtable;
    func_005A48D8(arg0 + 0x5C, 0, 0x400);
    func_005A48D8(arg0 + 0x45C, 0, 0x400);
    *(int *)(arg0 + 0x85C) = 0;
    *(int *)(arg0 + 0x864) = (int)(arg0 + 0x6B) & ~0xF;
    *(int *)(arg0 + 0x868) = (int)(arg0 + 0x46B) & ~0xF;
    *(float *)(arg0 + 0x88C) = 0x1.e66666p-1f;
    *(float *)(arg0 + 0x890) = 0x1.eb851ep-6f;
    *(int *)(arg0 + 0x898) = 0x80000099;
    *(int *)(arg0 + 0x860) = 0;
    *(int *)(arg0 + 0x894) = 0;
    func_003EC5A8(arg0, D_006A3CE8);
    *(int *)(arg0 + 0x28) = 0x80000000;
    *(int *)(arg0 + 0x2C) = 0x80FFFFFF;
}
