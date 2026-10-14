typedef int s32;
extern "C" void func_00493C70(void *a0, void *a1, s32 a2, s32 a3, s32 a4);
extern "C" void func_004940E8(void *a0, void *a1, s32 a2, s32 a3);
extern char D_00492EA8[];
extern char D_00492ED0[];
extern "C" void func_00491380(void *a0, s32 a1, s32 a2, s32 a3, s32 t0) {
    if (t0 == 0) {
        if (a3 != 0) {
            return func_00493C70(a0, D_00492EA8, 0, a1, a2);
        }
        func_004940E8(a0, D_00492EA8, 0, a1);
        return;
    }
    if (a3 != 0) {
        return func_00493C70(a0, D_00492ED0, 0, a1, a2);
    }
    func_004940E8(a0, D_00492ED0, 1, a1);
}
