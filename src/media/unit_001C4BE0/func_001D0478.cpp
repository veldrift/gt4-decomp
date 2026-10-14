typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

struct S0478 {
    char pad0[0x144];
    s32 f144;
};

extern "C" s32 func_00579358(void);
extern "C" void func_001CD5F8(void *arg0, s32 arg1, s64 *bits);

extern "C" void func_001D0478(void *arg0, s32 arg1) {
    S0478 *self = (S0478 *)arg0;
    s64 sp0 = (s64)func_00579358() << 32;
    u64 lo = (u32)func_00579358();
    u64 t = (u64)sp0 | lo;
    t = t & 0xFFFE0000FFFFFFFFULL;
    u64 flag = (u64)(self->f144 != 0);
    t = t & ~1ULL;
    t = t | flag;
    sp0 = (s64)t;
    func_001CD5F8(arg0, arg1, &sp0);
}
