typedef int s32;

extern "C" void func_00590A88(void);
extern "C" s32 func_005B68D0(char *arg0);
extern "C" s32 func_005B5698(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

extern s32 D_00645430;
extern char D_0068BE30[];
extern char D_0068BE38[];

extern "C" void func_001027D0(void) {
    if (D_00645430 != 0) {
        if (func_005B68D0(D_0068BE30) >= 0) {
            do {
            } while (func_005B5698(D_0068BE38, 0x4402, 0, 0, 0, 0) < 0);
        }
    }
    func_00590A88();
}
