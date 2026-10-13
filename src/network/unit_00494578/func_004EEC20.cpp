typedef int s32;

extern "C" s32 func_004EF8C0(s32 *arg0, s32 *arg1, s32 arg2);

extern "C" s32 func_004EEC20(s32 *arg0) {
    s32 buf[8];
    s32 temp_v1 = *arg0;

    if (temp_v1 == 0) {
        return 0;
    }
    {
        s32 r = func_004EF8C0(arg0, buf, 8);
        return (r < 0) ? 0 : r;
    }
}
