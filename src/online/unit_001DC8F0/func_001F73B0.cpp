typedef int s32;

extern char D_00645570[];

extern "C" s32 func_004F68C8(char *s);
extern "C" void func_005A6AB0(char *dst, char *src, s32 n);

extern "C" void func_001F73B0(s32 unused, char *arg1) {
    char *base = D_00645570;
    if (func_004F68C8(base) != 0) {
        func_005A6AB0(base + 0xF78, arg1, 0x20);
    }
}
