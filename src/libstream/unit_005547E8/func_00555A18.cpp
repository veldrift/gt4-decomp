/* compiler: ee-gcc2.96-nsa-nosib */
typedef int s32;
typedef signed char s8;

struct Copy60 {
    s8 unk0;
    char pad1[0x3];
    s32 unk4;
    char pad8[0xC];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
};

extern "C" int func_00561040(int a0, int *inout, Copy60 *in);
extern "C" void func_005A48D8(void *, s32, s32);

extern "C" void func_00555A18(s32 arg0, s32 arg1) {
    char *temp_s1;
    struct Copy60 *temp_s0;

    temp_s1 = (char *)(arg0 + arg1 * 0x114);
    temp_s0 = (struct Copy60 *)(temp_s1 + 0xCC);
    func_005A48D8(temp_s0, 0, 0x3C);
    temp_s0->unk0 = 7;
    temp_s0->unk4 = -1;
    temp_s0->unk1C = 0x80;
    temp_s0->unk20 = 0x80;
    temp_s0->unk14 = 0x80;
    temp_s0->unk18 = 0x80;
    func_00561040(*(s32 *)temp_s1, (s32 *)(temp_s1 + 0x108), temp_s0);
}
