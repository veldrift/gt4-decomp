typedef int s32;

extern "C" s32 (*D_0064A2F8)();

extern "C" s32 func_00514898(void) {
    s32 (*temp_v0)(void) = D_0064A2F8;

    if (temp_v0 != 0) {
        temp_v0();
    }
    return 0x2C;
}
