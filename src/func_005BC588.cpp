typedef int s32;

extern "C" void func_005BC4C8(void);
extern s32 D_0088D7C8;

extern "C" void func_005BC588(void) {
    if (D_0088D7C8 == 0) {
        D_0088D7C8 = 1;
        return func_005BC4C8();
    }
}
