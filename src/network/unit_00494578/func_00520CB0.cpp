typedef int s32;
extern s32 D_0064B43C;
extern "C" void func_00522680();
extern "C" void func_00520CB0(void) {
    if (D_0064B43C > 0) {
        if (--D_0064B43C == 0) {
            return func_00522680();
        }
    }
}
