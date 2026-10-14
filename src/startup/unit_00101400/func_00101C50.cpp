typedef int s32;

extern "C" void func_00101C28(s32 (*arg0)(void));
extern "C" void func_00577F80(void);
extern "C" s32 func_00583718(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

extern s32 D_00617D88;
extern char D_005814F0[];
extern char D_0010F608[];
extern char D_0010F628[];
extern char D_0010F648[];
extern char D_0010F658[];
extern char D_0010F698[];
extern char D_0010F6A8[];
extern char D_0010F6F8[];

extern "C" void func_00101C50(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (D_00617D88 == 0) {
        D_00617D88 = 1;
        while (func_00583718(arg0, arg1, arg2, arg3) < 0) {
            func_00577F80();
        }
        func_00101C28((s32 (*)(void))D_005814F0);
        func_00101C28((s32 (*)(void))D_0010F648);
        func_00101C28((s32 (*)(void))D_0010F658);
        func_00101C28((s32 (*)(void))D_0010F698);
        func_00101C28((s32 (*)(void))D_0010F6A8);
        func_00101C28((s32 (*)(void))D_0010F608);
        func_00101C28((s32 (*)(void))D_0010F628);
        func_00101C28((s32 (*)(void))D_0010F6F8);
    }
}
