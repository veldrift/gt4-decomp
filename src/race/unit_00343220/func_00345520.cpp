typedef int s32;
typedef unsigned char u8;
typedef signed char s8;

extern "C" s32 func_00345218(void *arg0);
extern "C" void func_00463C28(void *arg0, s32 arg1, s32 arg2);
extern "C" void func_00464C38(void *arg0, s32 arg1);

extern "C" s32 func_00345520(char *arg0) {
    if (*(s8 *)(arg0 + 0x56A) == 4) {
        return 0;
    }
    if (*(u8 *)(*(s32 *)(arg0 + 4) + 0xCBE1) == 0) {
        if (func_00345218(arg0) != 0) {
            func_00463C28(arg0 + 0x14, 6, 1);
        }
    }
    func_00464C38(arg0, 6);
    return 1;
}
