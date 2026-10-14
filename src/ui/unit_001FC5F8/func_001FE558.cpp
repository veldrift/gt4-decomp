typedef int s32;

struct Obj {
    char p0[0xAC];
    s32 fAC;
    s32 fB0;
    s32 fB4;
};

extern "C" s32 func_0054ED08(char *arg0, s32 arg1);
extern "C" void func_0054F5E0(long arg0, long arg1);

extern "C" void func_001FE558(Obj *arg0) {
    if (arg0->fAC != 0) {
        arg0->fAC = 0;
    }
    func_0054F5E0(0, (long)((unsigned long)-1 >> 1));
    s32 v = arg0->fB4;
    if (v != 0) {
        func_0054ED08((char *)v, 1);
    }
}
