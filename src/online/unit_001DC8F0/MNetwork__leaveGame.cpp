typedef int s32;
typedef unsigned char u8;

struct RefCounter {
    s32 ref;
};

extern "C" void func_001DC650(void *arg0, void *arg1);
extern "C" void *func_001F4E18(void *arg0);
extern "C" void *func_001F4E68(void *arg0);
extern "C" void func_002FE278(void *arg0, s32 arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_001DC5F8(void *arg0, int arg1);

extern "C" void func_001E2E70(s32 *arg0, void *arg1, s32 arg2) {
    void *h[4];
    s32 buf0[4];
    s32 *p_s2;
    s32 newVal;
    s32 oldVal;
    func_001DC650(h, arg1);
    if (((arg2 == 0) && (func_001F4E18(h[0]) == 0)) || (func_001F4E68(h[0]) == 0)) {
        p_s2 = buf0;
        func_002FE278(p_s2, 0);
        if (arg0 != p_s2) {
            newVal = *p_s2;
            if (newVal != 0) {
                func_003285A8((RefCounter *)newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8((RefCounter *)oldVal);
            }
            *arg0 = newVal;
        }
        func_002FC870(p_s2, 2);
        func_001DC5F8(h, 2);
    } else {
        p_s2 = buf0;
        func_002FE278(p_s2, 1);
        if (arg0 != p_s2) {
            newVal = *p_s2;
            if (newVal != 0) {
                func_003285A8((RefCounter *)newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8((RefCounter *)oldVal);
            }
            *arg0 = newVal;
        }
        func_002FC870(p_s2, 2);
        func_001DC5F8(h, 2);
    }
}
