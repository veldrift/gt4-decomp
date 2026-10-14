typedef int s32;
extern "C" void MNetwork__fileGet(s32 *);
extern "C" void func_0023B1D8(void *, int);
extern "C" void func_0023B478(void *);
extern "C" void func_0023CA78(s32, const char *, const char *);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00312318(void *, int);
extern "C" void func_00312370(void *, void *);
extern "C" char *func_00314AD8(s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern char D_006959E0[];

extern "C" void MNetwork__showFile(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 s0;
    s32 newVal;
    s32 oldVal;
    MNetwork__fileGet(arg0);
    if (*arg0 == 0) {
        func_002FE278(buf0, 0);
        if (arg0 != buf0) {
            newVal = buf0[0];
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002FC870(buf0, 2);
        return;
    }
    func_00312370(buf0, arg0);
    p_s2 = buf1;
    func_0023B478(p_s2);
    s0 = *p_s2;
    func_0023CA78(s0, func_00314AD8(buf0[0]), D_006959E0);
    func_0023B1D8(p_s2, 2);
    func_002FE278(p_s2, 1);
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
    func_002FC870(p_s2, 2);
    func_00312318(buf0, 2);
}
