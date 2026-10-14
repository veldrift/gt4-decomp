/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

extern "C" s32 func_00386950(s32, void *) throw();
extern "C" s32 func_00386C70(s32, void *);

extern "C" void func_00386BF8(s32 arg0, void *arg1) {
    for (s32 i = 0; i < func_00386C70(arg0, arg1); i++)
        func_00386950(arg0 + i * 0x370, arg1);
}
