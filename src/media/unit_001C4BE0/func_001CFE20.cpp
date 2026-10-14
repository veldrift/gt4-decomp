typedef int s32;
typedef unsigned short u16;
typedef long long s64;

extern "C" s64 func_001CD840(s32 arg0);

extern "C" s32 func_001CFE20(void *arg0) {
    char *self = (char *)arg0;
    if ((u16)(*(u16 *)(self + 0x48) & 1) != 0) {
        return *(s32 *)(self + 0x14C);
    }
    s64 t = func_001CD840((s32)arg0) << 9;
    s32 r = (s32)(t >> 32);
    return r & 1;
}
