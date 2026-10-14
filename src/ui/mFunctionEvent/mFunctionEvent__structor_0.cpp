/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern char mFunctionEvent__vtable[];
extern "C" void *mEvent__structor_0(void *, s32, s32);
extern "C" void func_002F9B20(void *, s32);
extern "C" void func_00309378(void *, s32);
extern "C" void *func_0030BB18(void *);
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" void *HObject__tf(void);
extern "C" s32 func_005D84B0(void *, s32, void *, s32);
static inline void init(char *s, s32 n) {
    s32 spare[4];
    void *sp10[4];
    s32 sp20[4];
    s32 size = n * 4;
    *(s32 *)(s + 4) = 0;
    *(s32 *)(s + 8) = 0;
    *(s32 *)(s + 12) = 0;
    char *p = (char *)func_00326750(size, 4, *(const char **)HObject__tf());
    *(char **)(s + 4) = p;
    *(char **)(s + 12) = p + size;
    *(char **)(s + 8) = p;
    sp10[0] = p;
    func_0030BB18(sp20);
    *(s32 *)(s + 8) = func_005D84B0(sp10[0], n, sp20, 0);
    func_00309378(sp20, 2);
}
extern "C" void mFunctionEvent__structor_0(char *self, s32 a, s32 n) {
    mEvent__structor_0(self, 0, 0);
    *(char **)(self + 4) = mFunctionEvent__vtable;
    func_002F9B20(self + 0x20, a);
    init(self + 0x24, n);
}
