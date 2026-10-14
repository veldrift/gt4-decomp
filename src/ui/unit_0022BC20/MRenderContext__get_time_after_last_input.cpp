typedef int s32;
extern "C" void func_0022ACC8(void *, s32) throw();
extern "C" s32 func_0022AD20(void *, s32) throw();
extern "C" float func_00251908(s32);
extern "C" void func_00251950(s32, float);
extern "C" void func_002F7B68(void *, s32);
extern "C" void func_002F7BC0(void *, s32);
extern "C" float func_002F9158(s32);
extern "C" void func_002F9360(void *, float);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

extern "C" void MRenderContext__get_time_after_last_input(s32 *arg0, s32 arg1, s32 sel, s32 arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    if (sel == 0) {
        func_0022AD20(buf0, arg1);
        float f = func_00251908(*(s32 *)(buf0[0] + 0x10));
        s32 *p1 = buf1;
        func_002F9360(p1, f);
        if (arg0 != p1) {
            s32 newVal = *p1;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            s32 oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002F7B68(p1, 2);
        func_0022ACC8(buf0, 2);
    } else if (sel > 0) {
        func_002F7BC0(buf0, arg3);
        s32 *p2 = buf2;
        func_0022AD20(p2, arg1);
        s32 h = *(s32 *)(p2[0] + 0x10);
        func_00251950(h, func_002F9158(buf0[0]));
        func_0022ACC8(p2, 2);
        func_002F7B68(buf0, 2);
    }
}
