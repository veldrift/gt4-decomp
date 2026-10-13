typedef int s32;

extern "C" s32 func_0057DD98(s32 *arg0);
extern char D_00689F28[];

extern "C" void func_0057DA80(s32 *arg0, s32 arg1, s32 arg2) {
    func_0057DD98(arg0);
    arg0[1] = arg1;
    arg0[2] = arg2 - 1;
    arg0[0] = (s32)D_00689F28;
    arg0[3] = 0;
}
