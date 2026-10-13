typedef int s32;

extern "C" s32 func_005B1BB0(void *arg0);
extern s32 D_00654AC0;
extern char D_00873F00[];

extern "C" s32 func_005616E8(s32 arg0, s32 *arg1) {
    s32 r;
    if (arg0 == 0) {
        do {
            r = func_005B1BB0(D_00873F00);
        } while (r != 0);
        if (arg1 != 0) {
            *arg1 = D_00654AC0;
        }
        return r;
    }
    r = func_005B1BB0(D_00873F00);
    if (r == 0) {
        if (arg1 != 0) {
            *arg1 = D_00654AC0;
        }
    }
    return r;
}
