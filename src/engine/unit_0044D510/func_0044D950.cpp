typedef int s32;

extern "C" void func_00490CA0(s32 arg0);

extern s32 PDISTD__global_font_manager;

extern "C" void func_0044D950(s32 *arg0) {
    if (*arg0 == 0) {
        *arg0 = 1;
        func_00490CA0(PDISTD__global_font_manager);
    }
}
