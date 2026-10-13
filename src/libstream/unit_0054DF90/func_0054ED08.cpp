typedef int s32;

struct Obj {
    char pad0[0x3E8];
    void *p3E8;
    char pad1[0x404 - 0x3EC];
    s32 f404;
};

extern s32 D_00654D8C;
extern s32 D_00654D88;

extern "C" void func_00574E78(void *arg0);
extern "C" void func_00574EB0(void *arg0);
extern "C" void func_0054FDA8(void *arg0);
extern "C" void func_005ADCC0(s32 arg0);
extern "C" s32 func_005ADCE0(s32 arg0);

extern "C" s32 func_0054ED08(Obj *arg0, s32 arg1) {
    s32 var_s1 = arg1;

    if (var_s1 != 0) {
        func_00574E78((char *)arg0 + 0x2C0);
    }
    func_005ADCE0(D_00654D8C);
    if (arg0->f404 != 0) {
        arg0->f404 = 3;
        func_0054FDA8(arg0->p3E8);
        D_00654D88 = 1;
    } else {
        var_s1 = 0;
    }
    func_005ADCC0(D_00654D8C);
    if (var_s1 != 0) {
        func_00574EB0((char *)arg0 + 0x2C0);
    }
    return 0;
}
