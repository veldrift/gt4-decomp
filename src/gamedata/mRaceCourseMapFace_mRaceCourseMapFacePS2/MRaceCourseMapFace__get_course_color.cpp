typedef int s32;

struct Vec4;

extern "C" void func_001298C8(void *arg0, void *arg1);
extern "C" void func_00129870(void *arg0, s32 arg1);
extern "C" Vec4 *func_002030E8(Vec4 *arg0, Vec4 *arg1);
extern "C" void func_00203620(void *arg0, s32 arg1);
extern "C" void func_00203678(void *arg0, void *arg1);
extern "C" void func_00204558(void *arg0, s32 arg1);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);

extern "C" void func_0012A268(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    s32 buf2[4];
    s32 *p_s2;
    s32 *p_b1;
    s32 newVal;
    s32 oldVal;
    func_001298C8(buf0, arg1);
    if (arg2 == 0) {
        p_s2 = buf2;
        func_00204558(p_s2, buf0[0] + 0xA0);
        if (arg0 != p_s2) {
            newVal = *p_s2;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_00203620(p_s2, 2);
    } else if (arg2 == 1) {
        p_b1 = buf2;
        func_00203678(p_b1, arg3);
        func_002030E8((Vec4 *)(buf0[0] + 0xA0), (Vec4 *)(p_b1[0] + 0x10));
        func_00203620(p_b1, 2);
    }
    func_00129870(buf0, 2);
}
