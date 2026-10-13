typedef int s32;
typedef unsigned char u8;

extern "C" void func_0016D848(void *);
extern "C" void func_0016D7F0(void *, s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);

extern "C" void MGarage__hasRidingCar(s32 *arg0) {
    s32 buf0[4];
    s32 v_s0;
    s32 flag;
    s32 t;
    func_0016D848(buf0);
    v_s0 = *(s32 *)((char *)buf0[0] + 0x10);
    func_0016D7F0(buf0, 0x2);
    t = ~*(s32 *)((char *)((0x10000 + v_s0)) - 0x7e38);
    flag = 0;
    if (t < 0) {
        flag = 1;
    }
    func_002FE278(buf0, flag);
    if ((char *)arg0 != (char *)buf0) {
        v_s0 = buf0[0];
        if (v_s0 != 0) {
            func_003285A8(v_s0);
        }
        if (*(s32 *)(char *)arg0 != 0) {
            func_003285F8(*(s32 *)(char *)arg0);
        }
        *(s32 *)(char *)arg0 = v_s0;
    }
    func_002FC870(buf0, 0x2);
}
