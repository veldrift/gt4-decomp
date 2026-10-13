typedef int s32;

struct S004FE8A0 {
    char pad0[0x5A8];
    char *unk5A8;
};

extern "C" char *func_004FE8A0(struct S004FE8A0 *arg0, s32 arg1) {
    if (arg1 >= 0x40) {
        arg1 = 0x3F;
    }

    return arg0->unk5A8 + (arg1 * 0xC8) + 0x1D8;
}
