typedef int s32;

extern "C" int func_00499728(char *self);
extern "C" void func_0049BBB0(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0);
extern "C" void func_0049CC48(s32 a0);
extern "C" void func_004A1638(s32 a0);
extern "C" void func_004A2808(s32 a0, float f12);
extern "C" void func_004A29A8(s32 a0);
extern "C" void func_004A4550(s32 a0, s32 a1);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A7454(void);
extern "C" void func_004AB040(s32 a0);

extern "C" void func_003B8DD8(char *arg0) {
    func_004AB040(4);
    func_004A1638(6);
    func_004A1638(5);
    func_004A1638(2);
    func_004A29A8(0);
    func_004A2808(0x68, 1.0f);
    func_004AB040(0xF);
    func_004A4550(0, 1);
    func_004A4550(1, 0);
    char *v = *(char **)(arg0 + 0x88);
    if (v != 0) {
        func_00499728(v);
        func_0049CC48(*(s32 *)(*(char **)(arg0 + 0x88) + 0x18));
    }
    func_004A53F8();
    func_004A7454();
    func_0049BBB0(4, 0x32, 0x31, 0x27, 0x31);
    func_004A5400();
}
