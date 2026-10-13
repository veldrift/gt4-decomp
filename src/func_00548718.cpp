typedef int s32;

struct Obj {
    char pad[0x40];
    s32 unk40;
    char pad2[0xC0 - 0x44];
    s32 unkC0;
};

extern "C" void func_00578500(s32 arg0);
extern struct Obj D_0086CB80;

extern "C" s32 func_00548718(void) {
    func_00578500(D_0086CB80.unk40);
    return D_0086CB80.unkC0 == 0;
}
