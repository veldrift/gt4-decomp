/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef long s64;
extern "C" void func_0015F388(void *, int) throw();
extern "C" void *func_0015F3E0(void *, void *) throw();
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" s32 func_002FE250(s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

extern "C" void MGame__get_max_entry(s32 *arg0, void *arg1, int arg2, void *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 newVal, oldVal;
    if (arg2 > 0) {
        func_0015F3E0(buf0, arg1);
        arg0 = buf1;
        func_002FC8C8(arg0, arg3);
        arg3 = (void *)*(s32 *)(buf0[0] + 0x10);
        arg3 = (char *)arg3 + 4;
        s32 v = func_002FE250(arg0[0]);
        *(s32 *)((char *)arg3 + 0xC0) = v;
        func_002FC870(arg0, 2);
        func_0015F388(buf0, 2);
        return;
    }
    func_0015F3E0(buf0, arg1);
    s32 *p2 = buf2;
    func_002FE278(p2, *(s32 *)(*(s32 *)(buf0[0] + 0x10) + 0xC4));
    if (arg0 != p2) {
        newVal = p2[0];
        if (newVal != 0)
            func_003285A8(newVal);
        oldVal = *arg0;
        if (oldVal != 0)
            func_003285F8(oldVal);
        *arg0 = newVal;
    }
    func_002FC870(p2, 2);
    func_0015F388(buf0, 2);
}
