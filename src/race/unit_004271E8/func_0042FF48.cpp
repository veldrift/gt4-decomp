typedef int s32;

extern "C" s32 func_0042FF48(void *arg0) {
    char *self = (char *)arg0;
    s32 n = *(s32 *)(self + 0xBAC);
    if (n < 0) {
        return 0;
    }
    *(s32 *)(self + 0xA68) = n;
    __builtin_memcpy(self + 0xA6C, self + 0xBB0, 0x100);
    return 1;
}
