typedef int s32;

struct func_004540A8_unk4 {
    char pad0[0x8C];
    s32 unk8C;
};

struct func_004540A8_arg0 {
    char pad0[0x4];
    struct func_004540A8_unk4 *unk4;
};

extern "C" s32 func_004574E0(void);

extern "C" s32 func_004540A8(struct func_004540A8_arg0 *arg0) {
    s32 value = arg0->unk4->unk8C;
    if (value >= 0) {
        return value;
    }
    return func_004574E0();
}
