typedef int s32;
typedef signed char s8;

extern char D_00645570[];

extern "C" char *func_004F9F70(char *base, s32 idx);
extern "C" void func_004FA048(char *base, char *p);

extern "C" s32 func_001FBB08(s32 idx, s32 unused, s32 off, s32 def) {
    char *base = D_00645570;
    s32 r = def;
    char *p = func_004F9F70(base, idx);
    if (p != 0) {
        r = *(s8 *)(p + off);
    }
    func_004FA048(base, p);
    return r;
}
