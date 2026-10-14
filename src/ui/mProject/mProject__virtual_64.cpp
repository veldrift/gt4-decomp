typedef int s32;
typedef unsigned char u8;

extern "C" void IfWidget__structor_0(s32 *arg0, void *arg1);
extern "C" s32 func_00206868(s32 *arg0);
extern "C" void func_00229EC8(s32 *arg0) throw();
extern "C" void func_0025A810(s32 arg0, s32 *arg1);
extern "C" s32 func_0025C300(s32 arg0);
extern "C" void func_0026A0E8(s32 *arg0, s32 *arg1);
extern "C" void func_0026A118(s32 *arg0, s32 arg1);

extern "C" void mProject__virtual_64(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 sp10;
    s32 v_s0;
    s32 *p_s2;

    IfWidget__structor_0(arg0, arg1);
    v_s0 = func_00206868(arg0);
    p_s2 = &sp10;
    if (v_s0 != 0) {
        do {
            sp10 = 0;
            func_0026A0E8(buf0, p_s2);
            func_0025A810(v_s0, buf0);
            func_0026A118(buf0, 2);
            v_s0 = func_0025C300(v_s0);
        } while (v_s0 != 0);
    }
    func_00229EC8(arg0);
}
