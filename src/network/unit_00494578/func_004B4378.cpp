typedef int s32;

extern "C" void func_004B4378(char *arg0) {
    s32 a3 = 1;
    char *a1 = arg0 + 0x20;
    do {
        char *v0 = a1 + 0x218;
        s32 v1 = 0x3F;
        do {
            v1--;
            v0[0] = 0;
            v0[1] = 0;
            *(short *)(v0 + 2) = 0;
            *(short *)(v0 + 4) = 0;
            *(short *)(v0 + 6) = 0;
            v0 += 8;
        } while (v1 != -1);
        a3--;
        a1 += 0x41C;
    } while (a3 != -1);

    *(s32 *)(arg0 + 0x0) = 0;
    *(s32 *)(arg0 + 0x14) = 0;
    *(s32 *)(arg0 + 0x18) = 0;

    char *p8 = arg0 + 0x8;
    char *pC = arg0 + 0xC;
    s32 a0 = 0x20;
    s32 cnt = 1;
    do {
        cnt--;
        *(s32 *)(p8 + a0) = 0;
        *(s32 *)(pC + a0) = 0;
        a0 += 0x41C;
    } while (cnt >= 0);
}
