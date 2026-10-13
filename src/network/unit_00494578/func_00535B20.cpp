typedef int s32;

extern s32 D_008686B8[];

s32 func_00535B20(s32 arg0, s32 arg1) {
    s32 *p;

    p = &D_008686B8[arg0];
    if (*p == 0) {
        *p = arg1;
        return 0;
    }
    return 0x17;
}
