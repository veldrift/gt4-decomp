typedef int s32;

struct func_0051CCD0_slot {
    s32 unk0;
    void *unk4;
};

extern struct func_0051CCD0_slot D_00863798;
extern void *D_0064B4B0;

extern "C" s32 func_0051CCD0(void) {
    if (D_00863798.unk0 != 0) {
        void *obj = D_0064B4B0;
        void (*fn)(void *) = *(void (**)(void *))((char *)obj + 0x18);
        fn(D_00863798.unk4);
        D_00863798.unk0 = 0;
        return 0;
    }
    return 5;
}
