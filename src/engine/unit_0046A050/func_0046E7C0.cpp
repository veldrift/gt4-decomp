typedef int s32;

extern "C" void *func_0046E848(void *arg0);
extern "C" char D_00688930[];

struct func_0046E7C0_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    char pad20[0x4];
    void *unk24;
};

extern "C" void *func_0046E7C0(struct func_0046E7C0_arg0 *arg0) {
    arg0->unk1C = 0;
    arg0->unk24 = D_00688930;
    return func_0046E848(arg0);
}
