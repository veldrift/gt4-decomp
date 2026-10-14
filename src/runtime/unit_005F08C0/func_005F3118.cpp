typedef int s32;

extern "C" void func_003D62A8(void *, s32);
extern "C" void RaceInformation__structor_1(void *, s32);
extern "C" void func_005C1628(void *);

extern "C" void func_005F3118(void *arg0, s32 arg1) {
    if ((char *)arg0 + 0x130 != 0) {
        char *p0 = (char *)arg0 + 0xa90;
        while ((char *)arg0 + 0x130 != p0) {
            p0 -= 0x190;
            func_003D62A8(p0, 0x2);
        }
    }
    RaceInformation__structor_1(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_005C1628(arg0);
    }
}
