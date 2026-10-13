typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad0[0xA3];
    u8 b;
};

extern "C" void func_001A0AF8(void *arg0, int arg1);
extern "C" void func_001A0B50(void *arg0);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void MRaceData__getNeedPrice(s32 *arg0) {
    s32 sp[4];
    s32 sp10[4];
    s32 *p1;
    s32 temp_a0;
    s32 temp_s0;
    s32 k;
    s32 v;

    func_001A0B50(sp);
    k = 0x2710;
    v = ((Obj *)sp[0])->b * k;
    p1 = sp10;
    func_002FE278(p1, (void *)v);
    if (arg0 != p1) {
        temp_s0 = *p1;
        if (temp_s0 != 0) {
            func_003285A8(temp_s0);
        }
        temp_a0 = *arg0;
        if (temp_a0 != 0) {
            func_003285F8(temp_a0);
        }
        *arg0 = temp_s0;
    }
    func_002FC870(p1, 2);
    func_001A0AF8(sp, 2);
}
