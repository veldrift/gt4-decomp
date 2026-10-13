typedef int s32;
typedef signed char s8;

struct mFunctionDefine {
    char pad0[0xC];
    s8 *unkC;
};

extern "C" s32 func_002F47F0(s8 *arg0);                    /* extern */
extern "C" void func_002F4848(s8 *arg0, s32 arg1);         /* extern */
extern "C" void func_003067C0(s32 arg0, void *arg1, void *arg2); /* extern */
extern "C" s32 func_00322060(void *arg0);                  /* extern */

extern "C" void func_0031B908(void *arg0, void *arg1) {
    struct mFunctionDefine *self = (struct mFunctionDefine *)arg0;
    s8 **pp = &self->unkC;

    if (func_002F47F0(*pp) == 0) {
        s32 r = func_00322060(arg1);
        func_002F4848(*pp, r);
        func_003067C0(r, (s8 *)self + 8, pp);
    }
}
