typedef int s32;

extern "C" void func_003B05B8(void *self, void *o);
extern "C" void *func_003B08F8(void *arg0, void *arg1);

extern "C" void func_0033B650(char *arg0, void *arg1, void *arg2) {
    s32 v = *(s32 *)(arg0 + 0xE10);
    v = v ^ 1;
    *(s32 *)(arg0 + 0xE10) = v;
    func_003B08F8(arg0 + v * 0x700 + 0x10, arg1);
    func_003B05B8(arg0 + *(s32 *)(arg0 + 0xE10) * 0x700 + 0x6B0, arg2);
    if (*(s32 *)(arg0 + 0xE14) == 0) {
        s32 v2 = *(s32 *)(arg0 + 0xE10);
        *(s32 *)(arg0 + 0xE14) = 1;
        char *s1 = arg0 + v2 * 0x700;
        char *s0 = arg0 + (1 - v2) * 0x700;
        func_003B08F8(s0 + 0x10, s1 + 0x10);
        func_003B05B8(s0 + 0x6B0, s1 + 0x6B0);
    }
}
