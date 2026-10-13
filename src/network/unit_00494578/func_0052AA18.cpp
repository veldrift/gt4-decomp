extern "C" void func_005A48D8(void *, int, int);

struct func_0052AA18_arg0 {
    char pad0[4];
    char *unk4;
    char pad8[0x50 - 0x8];
    unsigned int unk50;
};

extern "C" void *func_0052AA18(struct func_0052AA18_arg0 *arg0)
{
    unsigned int s1 = 0;
    unsigned int n = arg0->unk50;
    char *s0 = arg0->unk4;

    if (n != 0) {
        do {
            if (*(unsigned int *)s0 == 0) {
                func_005A48D8(s0, 0, 0x49C);
                *(unsigned int *)(s0 + 0x84) = s1;
                return s0;
            }
            s1++;
            s0 += 0x49C;
        } while (s1 < n);
    }
    return 0;
}
