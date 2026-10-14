typedef int s32;
typedef long s64;
typedef unsigned long u64;

extern "C" int func_00449770(int, s64);

extern "C" int func_00443FB8(char *base, s64 arg1) {
    s32 idx = (s32)(arg1 >> 32);
    u64 lo = (u64)arg1 & 0xFFFFFFFFUL;
    s32 v = *(s32 *)(base + idx * 4 + 0x134);
    if (v == 0) {
        return -1;
    }
    return func_00449770(v, (s64)(s32)lo);
}
