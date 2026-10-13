typedef int s32;

extern "C" void func_00576788(void *a0);
extern "C" void func_005767C0(void *a0);
extern "C" void func_0057CB00(void *a0, s32 a1);
extern "C" s32 *func_0057CC10(void *a0);

extern "C" s32 func_00503E70(char *arg0) {
    s32 sp[4];
    s32 var_s1 = 0;

    sp[0] = (s32)arg0;
    func_00576788(arg0);
    s32 *temp = func_0057CC10(arg0 + 0x30);
    if (temp != 0) {
        var_s1 = *temp;
        func_0057CB00(arg0 + 0x48, var_s1);
    }
    func_005767C0((void *)sp[0]);
    return var_s1;
}
