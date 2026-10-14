/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

extern char D_00697768[];
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" void mFunctionEvent__structor_0(void *, s32, s32) throw();
extern "C" s32 func_0028E348(void *, void *);
extern "C" void func_00309348(void *, s32 *);
extern "C" void func_00309378(void *, s32);
extern "C" void func_0020DA00(void *, s32, void *);

extern "C" void func_0020D738(s32 **arg0, s32 arg1, s32 count, ...) {
    __builtin_va_list args;
    s32 obj[4];
    s32 hv[2];
    s32 *ph = hv;
    s32 i = 0;
    {
        void *p = func_00326750(0x34, 4, D_00697768);
        mFunctionEvent__structor_0(p, arg1, count);
        hv[0] = (s32)p;
    }
    func_0028E348(arg0, ph);
    __builtin_stdarg_start(args, count);
    for (; i < count; i++) {
        void *self = *arg0;
        hv[1] = __builtin_va_arg(args, s32);
        func_00309348(obj, &hv[1]);
        func_0020DA00(self, i, obj);
        func_00309378(obj, 2);
    }
    __builtin_va_end(args);
}
