/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

extern "C" s32 func_00521298(s32 a0, s32 a1, s32 a2, s32 *out);
extern "C" void mUpdateContext__Sync(s32 a0);
extern "C" void func_00271E40(void *arg0);

extern "C" s32 func_00271D48(void *arg0, s32 arg1, s32 arg2, s32 *arg3, s32 *arg4) {
    s32 buf0;
    s32 r;
    s32 v;
    s32 s0;
    s32 s4;

    *arg4 = 0;
    s0 = 0;
    s4 = 1;
    do {
        buf0 = 0;
        r = func_00521298(*(s32 *) ((char *) arg0 + 0x10), arg1, arg2 - 1, &buf0);
        *(s32 *) ((char *) arg0 + 0x20) = r;
        switch (r) {
        case 0:
            if (buf0 == 0) {
                mUpdateContext__Sync(1);
            } else {
                *arg3 = buf0;
                s0 = 1;
            }
            break;
        case 0xC356:
            s0 = 1;
            *arg4 = 1;
            *arg3 = buf0;
            break;
        default:
            s4 = 0;
            func_00271E40(arg0);
            s0 = 1;
            break;
        }
    } while (s0 == 0);
    return s4;
}
