typedef int s32;
typedef float f32;

extern "C" void func_001978D0(void *arg0, void *arg1);
extern "C" void func_0022AD20(void *arg0, void *arg1);
extern "C" f32 func_0019AA50(s32 arg0, s32 arg1);
extern "C" void func_0022ACC8(void *arg0, s32 arg1);
extern "C" void func_00197878(void *arg0, s32 arg1);
extern "C" void func_002F9360(void *arg0, f32 fparg0);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);
extern "C" void func_002F7B68(void *arg0, s32 arg1);

extern "C" void MPhotoRenderFace__getPrinterProgress(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    s32 spare[4];
    s32 buf1[4];
    s32 *p0;
    s32 v_s2;
    s32 newVal;
    s32 oldVal;
    f32 fv;

    func_001978D0(buf0, arg1);
    p0 = buf1;
    v_s2 = buf0[0];
    func_0022AD20(p0, arg3);
    fv = func_0019AA50(v_s2, p0[0]);
    func_0022ACC8(p0, 2);
    func_00197878(buf0, 2);
    func_002F9360(buf0, fv);
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
    func_002F7B68(buf0, 2);
}
