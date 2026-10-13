typedef int s32;
typedef unsigned char u8;

extern "C" void func_003A3EC8(char *arg0, s32 arg1, s32 arg2);
extern "C" void func_003A3B38(char *arg0, float arg1);

extern "C" void func_003BD4F0(char *arg0, char *arg1, float fparg0) {
    s32 var_s1 = 0;
    char *s2 = arg0 + 0x1398;
    char *a = *(char **)(arg1 + 0x60);
    char *b = *(char **)(a + 0x8);
    char *c = *(char **)b;
    char *d = *(char **)(c + 0x18);

    if (*(u8 *)s2 != 0) {
        var_s1 = *(s32 *)(arg0 + 0x437C) != 0;
    }
    s32 temp_s1 = var_s1 & 0xFF;

    func_003A3EC8(s2, *(signed char *)(d + 0x5B3), 1);

    s32 *w = (s32 *)s2;
    *w = (*w & ~0xFF) | temp_s1;

    func_003A3B38(s2, fparg0);

    s32 *w2 = (s32 *)(arg0 + 0x1668);
    *w2 = (*w2 & ~0xFF) | temp_s1;
}
