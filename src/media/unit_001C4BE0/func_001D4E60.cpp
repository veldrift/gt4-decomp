/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
extern "C" void func_001D4C18(s32, s32, s32, s32, s32) throw();
extern "C" void func_001D4CA8(void *, unsigned int, float, void *, unsigned int) throw();
extern "C" unsigned func_00572C90(const unsigned char *, unsigned);
extern "C" void func_005792E8(s32 *, s32);
extern "C" int func_00579420(void *, s32);
extern "C" void func_005D2750(void *, u32, s32, s32);
extern "C" s32 func_001D4E60(s32 *a, s32 size, s32 key, s32 flag, float f0, float f1) {
    char sp[0x9D0];
    s32 sp9D0[4];
    s32 sz = size - 8;
    func_001D4CA8(a, size, f1, a, 4);
    if (flag != 0) {
        func_00579420(sp, *a ^ key);
        func_001D4C18((s32)(a + 1), ((size + 0x3F) & ~0x3F) - 4, (s32)sp, 0, 0);
    }
    s32 *p = a + 1;
    u32 end = size + 0x3F;
    func_001D4CA8(p, (end & ~0x3F) - 4, f0, p, 4);
    func_00579420(sp, *p + *a);
    func_005792E8(sp9D0, *p ^ *a);
    func_005D2750((a + 2), sz, (s32)sp, (s32)sp9D0);
    *p ^= key;
    return ((*p ^ func_00572C90((const unsigned char *)(a + 2), sz)) == 0) ? sz : -1;
}
