typedef int s32;
extern "C" void func_001DC5F8(void *, int) throw();
extern "C" void func_001DC650(void *, void *) throw();
extern "C" s32 func_001F1030(s32, s32);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00312318(void *, int);
extern "C" void func_00312370(void *, void *);
extern "C" char *func_00314AD8(s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" int func_0057F238(const char *, const char *) throw();
extern char D_006959C8[];
extern "C" void MNetwork__initializeRTIME(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p;
    s32 v;
    s32 nv, ov;
    func_001DC650(buf0, arg1);
    v = 1;
    if (arg2 > 0) {
        p = buf1;
        func_00312370(p, arg3);
        v = func_0057F238(func_00314AD8(p[0]), D_006959C8) != 0;
        func_00312318(p, 2);
    } else {
        p = buf1;
    }
    func_002FE278(p, func_001F1030(buf0[0], v));
    if (arg0 != p) {
        nv = *p;
        if (nv != 0) func_003285A8(nv);
        ov = *arg0;
        if (ov != 0) func_003285F8(ov);
        *arg0 = nv;
    }
    func_002FC870(p, 2);
    func_001DC5F8(buf0, 2);
}
