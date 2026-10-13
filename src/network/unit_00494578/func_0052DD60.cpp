typedef int s32;

struct Obj0052DD60 {
    char pad0[0x8];
    s32 unk8;
    char pad0C[0x4];
    s32 unk10;
    s32 unk14;
};

extern "C" s32 func_0052DD60(struct Obj0052DD60 *arg0) {
    s32 temp_v0;

    if (arg0 != 0) {
        if (arg0->unk10 != 0) {
            temp_v0 = arg0->unk14;
            if (temp_v0 != 0) {
                if (arg0->unk8 != 0) {
                    return temp_v0;
                }
            }
        }
    }
    return 0;
}
