/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern "C" void *RaceDriverModel__structor_0(void *);
extern "C" void RaceCrewModel__structor_1(void *);
extern "C" int func_00450980(void *);
extern char RaceCarModel__vtable[];
extern "C" void RaceCarModel__structor_0(char *self) {
    *(s32 *)self = 0;
    *(void **)(self + 8) = RaceCarModel__vtable;
    *(s32 *)(self + 4) = 0;
    func_00450980(self + 0x18);
    RaceDriverModel__structor_0(self + 0x5E0);
    RaceCrewModel__structor_1(self + 0xE20);
    *(s32 *)(self + 0x1660) = 0;
    *(s32 *)(self + 0x1664) = 0;
    *(s32 *)(self + 0x1668) = 0;
    *(s32 *)(self + 0x166C) = 0;
    *(s32 *)(self + 0x1670) = 0;
    *(s32 *)(self + 0x1674) = 0;
    for (int i=0;i<2;i++) ((s32 *)(self+0x1678))[i]=0;
    *(s32 *)(self + 0xC) = 0;
    *(s32 *)(self + 0x10) = 0;
    *(s32 *)(self + 0x14) = 0;
}
