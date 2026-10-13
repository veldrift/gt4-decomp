typedef int s32;

struct S {
    char pad[0x56A];
    signed char f;
};

extern "C" void func_00464C38(void *arg0, s32 arg1);

extern "C" s32 func_00345598(S *arg0) {
    s32 k = 4;
    if (arg0->f == k) {
        return 0;
    }
    func_00464C38(arg0, 7);
    return 1;
}
