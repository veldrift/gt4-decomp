typedef int s32;

extern "C" void RaceLoggerBuffer__clearSector(char *a) {
    s32 i;
    s32 j;
    char *ap = a + 0x84;
    for (i = 0; i < 2; i++) {
        char *v = *(char **)ap + 0x3EE4;
        for (j = 3; j >= 0; j--) {
            *(s32 *)v = 0;
            v -= 0x14F4;
        }
        ap += 8;
    }
}
