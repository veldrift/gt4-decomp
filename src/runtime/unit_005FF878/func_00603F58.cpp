typedef int s32;
typedef unsigned short u16;

extern "C" void *func_00450040(void **arg0, s32 arg1);

extern "C" void *func_00603F58(void **arg0, s32 arg1, s32 arg2) {
    char *base = (char *)func_00450040(arg0, arg1);
    u16 n = *(u16 *)(base + 0xA);
    char *p = base + 0x10;
    return (void *)(p + n * arg2);
}
