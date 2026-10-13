typedef int s32;

extern "C" void *func_002CBDA0(void *self);
extern "C" void *func_00326750(unsigned int size, int align, const char *name);
extern char D_0069C898[];
extern int D_00619938;

extern "C" s32 func_002CBDD0(s32 arg0) {
    if (arg0 != 0) {
        D_00619938 = 0;
    } else if (D_00619938 == 0) {
        int s0 = (int)func_00326750(0x10, 4, D_0069C898);
        func_002CBDA0((void *)s0);
        D_00619938 = s0;
    }
    return D_00619938;
}
