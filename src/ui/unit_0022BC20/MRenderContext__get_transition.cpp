typedef int s32;

extern "C" void func_0022ACC8(void *arg0, s32 arg1);
extern "C" void func_0022AD20(void *arg0, void *arg1);
extern "C" s32 func_00231098(s32 arg0);
extern "C" void func_002310F0(void *arg0, s32 arg1);
extern "C" void func_0024C7D8(void *arg0, void *arg1);
extern "C" void func_0024C808(void *arg0, s32 arg1);
extern "C" void func_0024C860(void *arg0, void *arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void func_0022CA10(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 *p1;
    s32 *p2;
    s32 *p3;
    s32 newVal;
    s32 oldVal;
    s32 t1;
    if (arg2 == 0) {
        func_0022AD20(buf0, arg1);
        p3 = buf3;
        t1 = func_00231098(buf0[0]);
        p1 = buf1;
        buf3[0] = t1;
        func_0024C7D8(p1, p3);
        if (arg0 != p1) {
            newVal = p1[0];
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_0024C808(p1, 2);
        func_0022ACC8(buf0, 2);
    } else {
        if (arg2 > 0) {
            func_0022AD20(buf0, arg1);
            p2 = buf2;
            func_0024C860(p2, arg3);
            func_002310F0((void *)buf0[0], p2[0]);
            func_0024C808(p2, 2);
            func_0022ACC8(buf0, 2);
        }
    }
}
