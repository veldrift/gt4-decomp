typedef int s32;

extern "C" void func_00335DD8(void *arg0, s32 arg1);

extern "C" void func_00335E28(void *arg0) {
    char *self = (char *)arg0;
    char *v = self + 0x170;
    *(s32 *)(v + 0x4) = 0;
    *(s32 *)(v + 0x1C) = 0;
    *(s32 *)(v + 0x18) = 0;
    *(s32 *)(v + 0x20) = 0;
    func_00335DD8(arg0, 0);
    *(s32 *)(self + 0x1E0) = 0;
}
