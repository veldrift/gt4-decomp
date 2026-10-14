typedef int s32;

extern "C" void func_00576788(s32 arg0);
extern "C" void func_005767C0(s32 arg0);
extern "C" char *func_00328C60(char *arg0, s32 arg1);
extern "C" s32 func_00329530(void);
extern "C" char *func_00578CF0(s32 arg0, s32 arg1);

extern "C" char *func_00329050(char *arg0, s32 arg1)
{
    volatile s32 sp0 = (s32)arg0;
    func_00576788(sp0);
    if (*(s32 *)(arg0 + 0x40) != 0) {
        if (*(s32 *)(arg0 + 0x44) != 0) {
            char *r = func_00328C60(arg0, arg1 + 0x10);
            func_005767C0(sp0);
            return r;
        }
    }
    char *s0 = func_00578CF0(0x10, arg1 + 0x10);
    *(s32 *)(s0 + 0xC) = func_00329530();
    char *s2 = s0 + 0x10;
    s32 v1 = *(s32 *)(arg0 + 0x48) + 1;
    *(s32 *)(arg0 + 0x48) = v1;
    if ((unsigned int)*(s32 *)(arg0 + 0x4C) < (unsigned int)v1) {
        *(s32 *)(arg0 + 0x4C) = v1;
    }
    func_005767C0(sp0);
    return s2;
}
