typedef int s32;

extern "C" void func_00554258(void *self);
extern "C" void *exception__structor_0(s32 n);

extern s32 D_0064CCFC;

extern "C" s32 func_00554350(void) {
    s32 cur = D_0064CCFC;
    if (cur == 0) {
        s32 t = (s32)exception__structor_0(0x40);
        func_00554258((void *)t);
        D_0064CCFC = t;
        return t;
    }
    return cur;
}
