typedef int s32;
typedef unsigned int u32;

extern "C" s32 func_00264030(void *self, s32 arg1, void *arg2);
extern "C" s32 func_002B21D0(void *self, s32 key);
extern "C" s32 func_002B2270(void *self, s32 key);

extern "C" s32 func_002B3A78(void *arg0, s32 arg1, void *arg2) {
    s32 r;

    r = func_00264030(arg0, arg1, arg2);
    if (r == 0) {
        s32 key = *(s32 *)((char *)arg2 + 0x20);
        if (func_002B21D0(arg0, key) != 0 || func_002B2270(arg0, key) != 0) {
            r = 1;
            *(s32 *)((char *)arg0 + 0x134) = *(s32 *)((char *)arg0 + 0x124);
        }
    }
    return r;
}
