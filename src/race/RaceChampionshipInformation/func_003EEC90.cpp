typedef int s32;

extern "C" char *func_003EEC90(char *self, s32 value) {
    s32 misses = 0;
    char *cur = self + 0x180;
    char *a2 = self + 0x300;
    s32 one = 1;
    char *v1 = a2;

    do {
        if (*(s32 *)(v1 - 4) == value) {
            if (misses == 0) {
                *(s32 *)a2 = one;
            } else {
                *(s32 *)v1 = 0;
            }
            return cur;
        }
        misses++;
        cur += 0x188;
        v1 += 0x188;
        a2 += 1;
    } while (misses < 6);

    return 0;
}
