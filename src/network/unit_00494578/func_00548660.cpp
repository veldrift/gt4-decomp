/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct G {
    s32 unk0;
    char pad4[0x38];
    s32 unk3C;
    char pad40[0x40];
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    char pad90[0x30];
    char unkC0[0x40];
};
extern G D_0086CB80;
extern s32 D_0064C3C8;
extern "C" void func_00576AD8(s32, s32);
extern "C" s32 func_00578168(void *, s32, s32, void *, s32);
extern "C" void func_00578480(s32);
extern "C" void func_00578500(s32);
extern "C" void func_00548660(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_00578500(D_0064C3C8);
    func_00578500(D_0086CB80.unk0);
    D_0086CB80.unk3C = 1;
    D_0086CB80.unk80 = arg1;
    D_0086CB80.unk8C = arg3;
    D_0086CB80.unk84 = arg2;
    D_0086CB80.unk88 = arg0;
    func_00576AD8(arg0, arg2);
    func_00578168(&D_0086CB80, 3, 1, D_0086CB80.unkC0, 0x40);
    func_00578480(D_0064C3C8);
}
