typedef int s32;
typedef unsigned char u8;
typedef float f32;

struct func_003E55F8_arg0 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    char pad1C[0x44 - 0x1C];
    u8 unk44;
};

extern "C" void func_0045AF18(void *, s32);
extern "C" void func_0045B018(void *, f32);

extern "C" void func_003E55F8(struct func_003E55F8_arg0 *arg0, void *arg1) {
    func_0045AF18(arg1, arg0->unk44);
    func_0045AF18(arg1, (s32)((arg0->unk4 * 0x1.0p7f) / 0x1.921FB4p1f));
    func_0045AF18(arg1, (s32)((arg0->unk8 * 0x1.0p7f) / 0x1.921FB4p1f));
    func_0045AF18(arg1, (s32)((arg0->unkC * 0x1.0p7f) / 0x1.921FB4p1f));
    func_0045B018(arg1, arg0->unk10);
    func_0045B018(arg1, arg0->unk14);
    func_0045B018(arg1, arg0->unk18);
}
