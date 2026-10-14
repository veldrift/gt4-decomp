typedef int s32;

struct Frame {
    char obj[0xD0];
    s32 d0;
    s32 d4;
    s32 d8;
    s32 dc;
    char tail[0x150 - 0xE0];
};

extern "C" void func_004AFE28(void *self);
extern "C" s32 func_004AFA20(void *self, void *arg);
extern "C" void func_004AFE60(void *self, s32 mode);
extern "C" s32 func_004AFED8(void *self, void *name, s32 mode);
extern "C" s32 func_004AFF60(void *self);
extern "C" void func_005A609C(void *a, void *b);

extern "C" s32 func_0054E290(void *arg0, void *arg1, s32 *arg2, s32 *arg3, void *arg4) {
    struct Frame f;
    s32 var_s0;

    func_004AFE28(&f);
    var_s0 = 0;
    if (func_004AFED8(&f, arg1, 3) >= 0) {
        f.d0 = 0;
        var_s0 = func_004AFA20(&f, &f.d0) != 0;
        func_004AFF60(&f);
        *arg2 = f.d4;
        *arg3 = f.d8;
        func_005A609C(arg4, &f.dc);
    }
    func_004AFE60(&f, 2);
    return var_s0;
}
