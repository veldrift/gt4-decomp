typedef int s32;

extern "C" s32 mWidget__structor_0(void *arg0);
extern "C" void func_002030A0(void *arg0);
extern "C" void func_00203118(void *arg0, s32 arg1);
extern "C" void *func_00326750(unsigned int size, s32 align, const char *name);
extern "C" s32 func_005E4EA8(void *arg0, s32 arg1, void *arg2, s32 arg3);
extern "C" void *MColor__tf(void);
extern char mColorFace__vtable[];

extern "C" void mColorFace__structor_0(char *arg0) {
    s32 pad0[4];
    void *sp10[4];
    s32 sp20[4];
    char *s0;
    char *p;

    mWidget__structor_0(arg0);
    *(char **)(arg0 + 4) = mColorFace__vtable;
    s0 = arg0 + 0xA0;
    *(char **)(s0 + 4) = 0;
    *(char **)(s0 + 8) = 0;
    *(char **)(s0 + 0xC) = 0;
    p = (char *)func_00326750(0x10, 4, (const char *)*(void **)MColor__tf());
    *(char **)(s0 + 0xC) = p + 0x10;
    *(char **)(s0 + 4) = p;
    *(char **)(s0 + 8) = p;
    sp10[0] = p;
    func_002030A0(sp20);
    *(s32 *)(s0 + 8) = func_005E4EA8(sp10[0], 1, sp20, 0);
    func_00203118(sp20, 2);
    *(s32 *)(arg0 + 0xB0) = 0;
    *(s32 *)(arg0 + 0xB4) = 0;
}
