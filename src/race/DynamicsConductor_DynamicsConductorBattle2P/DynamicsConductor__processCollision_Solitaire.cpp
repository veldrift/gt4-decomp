typedef int s32;

extern "C" void func_003F4B20(void);
extern "C" void func_003F4C18(char *arg0, s32 arg1);
extern "C" void func_0045BF20(char *arg0, s32 arg1);

extern "C" void DynamicsConductor__processCollision_Solitaire(char *arg0, s32 arg1) {
    s32 i = arg1;
    func_003F4B20();
    while (i < *(s32 *)(arg0 + 0xF8A0)) {
        func_0045BF20(arg0 + 0xDA6C, i);
        i += 1;
    }
    return func_003F4C18(arg0, i);
}
