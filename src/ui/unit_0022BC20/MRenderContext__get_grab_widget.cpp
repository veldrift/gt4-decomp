typedef int s32;
typedef signed char s8;

extern "C" void func_0022AD20(void *arg0, void *arg1);
extern "C" void func_0022ACC8(void *arg0, int arg1);
extern "C" s32 func_0022F1F0(s8 *arg0);
extern "C" void func_0022F248(s8 *arg0, s32 arg1);
extern "C" void func_002550B8(void *arg0, int arg1);
extern "C" void func_00255110(void *arg0, void *arg1);
extern "C" void func_00309348(s32 *arg0, s32 *arg1);
extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void MRenderContext__get_grab_widget(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    char *h[4];
    s32 sp10[4];
    s32 sp20[4];
    s32 sp30;
    s32 r;
    s8 *hp;
    s32 *pp;
    s32 *p_s2;
    s32 *p2;
    s32 newVal;
    s32 oldVal;
    if (arg2 == 0) {
        func_0022AD20(h, arg1);
        hp = (s8 *)h[0];
        pp = &sp30;
        r = func_0022F1F0(hp);
        p_s2 = sp10;
        sp30 = r;
        func_00309348(p_s2, pp);
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
        func_00309378(p_s2, 2);
        func_0022ACC8(h, 2);
    } else {
        if (arg2 == 1) {
            func_0022AD20(h, arg1);
            p2 = sp20;
            func_00255110(p2, arg3);
            func_0022F248((s8 *)h[0], p2[0]);
            func_002550B8(p2, 2);
            func_0022ACC8(h, 2);
        }
    }
}
