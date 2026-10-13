typedef int s32;
typedef unsigned int u32;

extern s32 D_0064A274;
extern s32 D_0064A278;
extern s32 D_0064A27C;

extern "C" s32 func_0050A2E0(void **arg0);
extern "C" s32 func_00538C68(s32 *arg0);

extern "C" s32 func_0050A398(void)
{
    u32 i;

    if (D_0064A274 != 0) {
        i = 0;
        if (D_0064A278 != 0) {
            do {
                s32 off = (s32)(i << 2);
                i += 1;
                func_0050A2E0((void **)(D_0064A274 + off));
            } while (i < (u32)D_0064A278);
        }
        func_00538C68(&D_0064A274);
    }
    D_0064A274 = 0;
    D_0064A278 = 0;
    D_0064A27C = 0;
    return 0;
}
