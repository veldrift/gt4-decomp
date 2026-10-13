typedef int s32;
typedef unsigned short u16;

extern "C" s32 func_004C51C0(u16 *arg0, s32 arg1) {
    u16 want = (u16)arg1;
    u16 *p = arg0;
    s32 i = 0;
    u16 v = *p;

    while (v != 0) {
        if (v == want) {
            return i;
        }
        i++;
        p++;
        v = *p;
    }
    return -1;
}
