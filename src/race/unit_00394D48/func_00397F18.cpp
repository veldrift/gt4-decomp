typedef int s32;
extern "C" void func_004A1638(s32 a);
extern "C" void func_004A5BF8(s32 a, s32 b, void *c);
extern "C" void func_004A5CC0(s32 a, void *b);
extern "C" void func_004AB040(s32 a);
extern char D_006A03D0[];
struct ObjA { char pad0[0x10]; s32 unk10; };
extern "C" void func_00397F18(ObjA *arg0) {
    s32 i = 0;
    s32 s1 = 0x65;
    char *s0 = (char *)arg0;
    func_004A5CC0(0, D_006A03D0);
    do {
        s32 mask = 1 << (i + 0xB);
        i++;
        if (arg0->unk10 & mask) {
            func_004A1638(s1);
            func_004A5BF8(s1, 0xD, s0 + 0xAD0);
            func_004A5BF8(s1, 0, s0 + 0xAE0);
            func_004A5BF8(s1, 1, s0 + 0xAF0);
            func_004A5BF8(s1, 4, s0 + 0xB00);
        } else {
            func_004AB040(s1);
        }
        s0 += 0x50;
        s1++;
    } while (i < 4);
}
