typedef int s32;

struct S_0054EEB8 {
    char pad[0x3E8];
    void *p3E8;
};

extern "C" s32 func_0054FA38(void *);
extern "C" s32 func_0054FA40(void *);
extern "C" s32 D_0064C4B0;

extern "C" s32 func_0054EEB8(struct S_0054EEB8 *arg0, s32 *arg1, s32 *arg2) {
    if (D_0064C4B0 == 0) {
        return 1;
    }
    if (arg1 != 0) {
        *arg1 = func_0054FA38(arg0->p3E8);
    }
    if (arg2 != 0) {
        *arg2 = func_0054FA40(arg0->p3E8);
    }
    return 0;
}
