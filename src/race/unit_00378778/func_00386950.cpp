typedef int s32;

extern "C" s32 func_0035A458(void *arg0);
extern "C" s32 func_004013E8(s32 arg0, void *arg1);
extern "C" s32 func_00403260(s32 arg0, void *arg1);

extern "C" s32 func_00386950(s32 arg0, void *arg1) {
    s32 r;

    r = func_0035A458(arg1);
    if (r != 0) {
        if (r == 1) {
            return func_004013E8(arg0, arg1);
        }
    }
    return func_00403260(arg0, arg1);
}
