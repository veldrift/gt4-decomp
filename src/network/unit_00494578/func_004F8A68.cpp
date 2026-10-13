typedef int s32;

extern "C" s32 *func_004F8A68(s32 *arg0, s32 arg1) {
    s32 *ret = 0;
    s32 *end;
    s32 v;

    if (arg1 != -1) {
        end = (s32 *)((char *)arg0 + *(s32 *)((char *)arg0 + 0x200) * 0x10);
        if (arg0 != end) {
            v = *arg0;
            for (;;) {
                ret = arg0;
                if (v == arg1) {
                    return ret;
                }
                arg0 = arg0 + 4;
                if (arg0 == end) {
                    break;
                }
                v = *arg0;
            }
            ret = 0;
        }
    }
    return ret;
}
