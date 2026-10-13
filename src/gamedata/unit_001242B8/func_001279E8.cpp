typedef int s32;

extern s32 *D_006187A8;
extern s32 D_006187B0[];
extern "C" s32 func_0057F238(void *arg0, s32 arg1);

extern "C" void func_001279E8(void *arg0, void *arg1) {
    s32 *state = D_006187A8;
    if (state != 0) {
        s32 index = 0;
        *state = 0;
        for (; index < 0x17; index++) {
            if (func_0057F238(arg1, D_006187B0[index]) == 0) {
                *D_006187A8 = index;
                break;
            }
        }
    }
}
