typedef int s32;

extern "C" void func_0042FE88(void *arg0) {
    char *self = (char *)arg0;
    s32 n = *(s32 *)(self + 0xA68);
    *(s32 *)(self + 0xBAC) = n;
    __builtin_memcpy(self + 0xBB0, self + 0xA6C, 0x100);
}
