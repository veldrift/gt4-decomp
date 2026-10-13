typedef int s32;

struct Obj {
    char pad0[4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    char pad1[0x14 - 0x10];
    s32 unk14;
};

extern "C" s32 func_00567C48(Obj *arg0) {
    Obj *a1 = arg0;
    if (a1->unk14 != 0) {
        return -1;
    }
    return a1->unk4 - (a1->unk8 * 8 + a1->unkC);
}
