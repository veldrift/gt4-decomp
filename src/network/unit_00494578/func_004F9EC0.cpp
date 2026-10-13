typedef int s32;

extern "C" s32 func_004F9EC0(char *self, s32 id) {
    char *base = self + 0xEE0;
    s32 *end = (s32 *)(base + *(s32 *)base * 4 + 4);
    s32 *p = (s32 *)(self + 0xEE4);
    s32 i;

    for (i = 0; p != end; p++, i++) {
        if (*p == id) return i;
    }
    return -1;
}
