typedef int s32;

extern char D_00645570[];

extern "C" s32 func_001F1368(void *arg0);
extern "C" void func_001F6B28(void *arg0, s32 arg1);
extern "C" void mUpdateContext__Sync(s32 frames);
extern "C" s32 func_004F66F0(char *arg0);

extern "C" s32 func_001F4DA8(void *arg0) {
    s32 r;
    while (func_004F66F0(D_00645570) == 0) {
        mUpdateContext__Sync(1);
    }
    r = func_001F1368(arg0);
    if (r != 0) {
        func_001F6B28(arg0, 0);
    }
    return r;
}
