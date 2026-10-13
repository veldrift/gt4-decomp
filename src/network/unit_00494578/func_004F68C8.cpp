typedef int s32;

struct Struct_004F68C8 {
    char pad0[0x154];
    s32 unk154;
    char pad158[0x5E8 - 0x158];
    s32 unk5E8;
    s32 unk5EC;
    char pad5F0[0x3F40 - 0x5F0];
    s32 unk3F40;
};

extern "C" s32 func_004F68C8(struct Struct_004F68C8 *arg0) {
    s32 var_v1;

    if (arg0->unk154 != 0) {
        var_v1 = arg0->unk3F40;
    } else {
        var_v1 = 0;
        if ((arg0->unk5EC != 0) || (arg0->unk5E8 != 0)) {
            var_v1 = 1;
        }
    }
    return var_v1;
}
