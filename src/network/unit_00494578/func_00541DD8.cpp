typedef int s32;

extern "C" s32 func_00541DD8(char *arg0, s32 *arg1) {
    s32 var_v0;
    s32 temp_v0;
    s32 temp_v1;
    s32 addr;
    s32 *slot;

    var_v0 = 2;
    if (arg1 != 0) {
        *arg1 = 0;
        if (arg0 != 0) {
            temp_v0 = *(s32 *)(arg0 + 0x840C);
            if (temp_v0 != 0) {
                temp_v1 = temp_v0 - 1;
                *(s32 *)(arg0 + 0x840C) = temp_v1;
                addr = temp_v1 * 4 + (s32)arg0;
                slot = (s32 *)(0x800C + addr);
                *arg1 = *slot;
                *slot = 0;
            }
            var_v0 = 0;
        }
    }
    return var_v0;
}
