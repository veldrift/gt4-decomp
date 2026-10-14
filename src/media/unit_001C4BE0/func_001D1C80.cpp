typedef int s32;
typedef unsigned int u32;
typedef signed char s8;

extern "C" char *func_005A609C(char *dst, const char *src);
extern "C" void func_005A5DC8(char *dst, char *src);
extern "C" s32 func_004AE230(s32 arg0, s32 arg1, s32 arg2);
extern "C" s32 func_004AE268(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern "C" void *func_005A4724(void *dst, const void *src, u32 n);

extern "C" s32 func_001D1C80(s32 arg0, s8 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    char loc[0xA0];
    char *sp = loc;
    func_005A609C(sp, (char *)arg0 + 4);
    if (*arg1 != 0) {
        func_005A5DC8(sp, (char *)arg1 + 1);
    }
    if (arg4 != 0) {
        func_004AE230((s32)(loc + 0x80), (s32)sp, 1);
        func_005A4724((void *)arg2, (const void *)*(s32 *)(loc + 0x90), (u32)arg3);
    } else {
        func_004AE268((s32)(loc + 0x80), (s32)sp, arg2, arg3, 1);
    }
    return 0;
}
