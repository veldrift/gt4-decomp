typedef int s32;

extern "C" void func_00570410(void *arg0, void *arg1, s32 arg2, s32 arg3);

extern char D_00863EC0[];
extern char D_00863F00[];

extern s32 D_0064B444;

extern "C" void func_00522AA0(s32 arg0) {
    if (D_0064B444 != 0 && arg0 >= 0) {
        func_00570410(D_00863EC0, D_00863F00, arg0, 0x1F4);
    }
}
