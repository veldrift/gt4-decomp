/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern "C" s32 D_008456C0[6][12];
extern "C" s32 D_008457E0[6];
extern "C" s32 D_008457F8[6][12];
extern "C" s32 D_00845918[6];
extern "C" char D_00845930[6];
extern "C" char D_00845938[6];
extern "C" s32 D_00845970[6][3];
extern "C" s32 D_008459B8[6][3];
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" void func_003EFF28(void) throw();
extern "C" void func_003F0100(void) {
    int i, j;
    func_005A48D8(D_008456C0, 0, 0x120);
    func_005A48D8(D_008457F8, 0, 0x120);
    for (i = 0; i < 6; i++) {
        D_008456C0[i][0] = -1;
        D_008457E0[i] = -1;
        D_008457F8[i][0] = -1;
        D_00845918[i] = -1;
        D_00845930[i] = 1;
        D_00845938[i] = 0;
    }
    func_003EFF28();
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 3; j++) {
            D_00845970[i][j] = 0;
            D_008459B8[i][j] = 0;
        }
    }
}
