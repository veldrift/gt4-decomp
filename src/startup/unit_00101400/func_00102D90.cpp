typedef int s32;
extern "C" {
void func_0049FD50(s32, void *, s32, s32, s32, s32);
void func_004A1638(s32);
void func_004A2808(s32, float);
void RaceEntryCar__update(s32);
void func_004A53F8(void);
void func_004A5400(void);
void func_004A5A90(float, float, float, float, float, float);
void func_004A7454(void);
void func_004AA1D8(float, float, float, float);
void func_004AB040(s32);
}
extern char D_00618340[];
struct V { float a, b, c, d; };
extern "C" void func_00102D90(V *arg0) {
    RaceEntryCar__update(1);
    func_004A53F8();
    func_004A7454();
    func_004A5A90(-320.0f, 320.0f, -224.0f, 224.0f, -1.0f, 1.0f);
    RaceEntryCar__update(0);
    func_004A53F8();
    func_004A7454();
    func_004AB040(0xF);
    func_004AB040(0x11);
    func_004AB040(5);
    func_004AB040(4);
    func_004A1638(2);
    func_004AB040(8);
    func_004AB040(6);
    func_004A1638(6);
    func_004A2808(0x44, 1.0f);
    func_004AA1D8(arg0->a, arg0->b, arg0->c, arg0->d);
    func_0049FD50(4, D_00618340, 0, 0, 0, 0);
    RaceEntryCar__update(1);
    func_004A5400();
    RaceEntryCar__update(0);
    func_004A5400();
}
