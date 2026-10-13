typedef int s32;

extern s32 D_00623570[];

extern "C" s32 func_00443DC0(s32 unused, s32 arg1) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_00623570[i] == arg1) return 1;
    }
    return 0;
}
