typedef unsigned char u8;
typedef int s32;

struct func_00430A20_arg0 {
    char pad0[2];
    u8 unk2;
};

extern "C" s32 func_00430A20(struct func_00430A20_arg0 *arg0, s32 arg1) {
    struct func_00430A20_arg0 *p = arg0;
    s32 lt = arg1 < 0xFF;
    arg1 = lt ? arg1 : 0xFF;
    if (p->unk2 < (u8)arg1) {
        p->unk2 = (u8)arg1;
        return 1;
    }
    return 0;
}
