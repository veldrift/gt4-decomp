typedef int s32;
extern "C" void *RaceInformation__structor_0(s32 *arg0);
extern "C" void func_003D6268(char *arg0);
extern "C" char D_00678718[];

extern "C" void func_005F30A0(void *arg0) {
    RaceInformation__structor_0((s32 *)arg0);
    *(void **)((char *)arg0 + 0x12C) = D_00678718;

    char *p = (char *)arg0 + 0x130;
    for (s32 i = 5; i != -1; i--) {
        func_003D6268(p);
        p += 0x190;
    }

    *(s32 *)((char *)arg0 + 0xAA8) = 0;
}
