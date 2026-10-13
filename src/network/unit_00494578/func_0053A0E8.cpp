typedef int s32;

extern "C" s32 func_00538C68(s32 *arg0);

extern s32 D_0064C100;
extern s32 D_0064C0FC;
extern s32 D_0064C0F8;
extern s32 D_0064C104;
extern char D_0064C0F4;

extern "C" s32 func_0053A0E8(void) {
    if (D_0064C100 != 0) {
        func_00538C68(&D_0064C100);
    }
    if (D_0064C0FC != 0) {
        func_00538C68(&D_0064C0FC);
    }
    if (D_0064C0F8 != 0) {
        func_00538C68(&D_0064C0F8);
    }
    if (D_0064C104 != 0) {
        func_00538C68(&D_0064C104);
    }
    D_0064C0F4 = 0;
    return 0;
}
