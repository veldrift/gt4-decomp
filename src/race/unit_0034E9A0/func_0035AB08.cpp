typedef int s32;
typedef unsigned int u32;

extern "C" s32 func_0034C190(s32 a, s32 b);
extern "C" void func_003F8540(void *dst, const void *src);
extern "C" void func_0045CDC8(s32 a, s32 b);
extern "C" s32 func_0045D0D8(s32 a);
extern "C" void *func_005A48D8(s32 a, s32 b, s32 c);

extern "C" void func_0035AB08(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;
    s32 temp_s2;
    s32 temp_off;

    temp_s2 = arg1 + 0x10F4;
    func_003F8540((void *)(arg1 + 0x54), (const void *)func_0034C190(arg0, arg2));
    func_005A48D8(temp_s2, 0, 0x400);
    temp_off = arg2 * 0x4F0;
    temp_s0 = arg0 + temp_off;
    temp_s0 = 0xDA78 + temp_s0;
    if ((u32)func_0045D0D8(temp_s0) < 0x401U) {
        func_0045CDC8(temp_s0, temp_s2);
    }
}
