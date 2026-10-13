typedef int s32;

struct S004F6B70 {
    char pad0[0x5A8];
    char *unk5A8;
};

extern "C" char *func_004F6B70(struct S004F6B70 *arg0, s32 arg1) {
    if (arg1 >= 0x10) {
        arg1 = 0xF;
    }

    return arg0->unk5A8 + (arg1 * 0x148) + 0x1D8;
}
