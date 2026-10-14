/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Q { char pad[0x18]; s32 f18; };
struct V4 { float x, y, z, w; };
extern Q *D_00618304;
extern char D_00618340[];
extern char D_00618400[];
extern "C" int func_00499728(void *);
extern "C" void func_0049CC48(s32);
extern "C" void func_0049FD50(s32, void *, void *, s32, s32, s32);
extern "C" void func_004A1638(s32);
extern "C" void func_004A2808(s32, float);
extern "C" void RaceEntryCar__update(s32);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A5A90(float, float, float, float, float, float);
extern "C" void func_004A7454(void);
extern "C" void func_004AA1D8(float, float, float, float);
extern "C" void func_004AB040(s32);

extern "C" void func_00102EC0(V4 *arg0) {
    float one = 1.0f;
    Q *s1 = D_00618304;
    s32 s2 = s1->f18;
    RaceEntryCar__update(1);
    func_004A53F8();
    func_004A7454();
    func_004A5A90(-320.0f, 320.0f, -224.0f, 224.0f, -1.0f, one);
    RaceEntryCar__update(0);
    func_004A53F8();
    func_004A7454();
    func_004AB040(0xF);
    func_004AB040(0x11);
    func_004AB040(5);
    func_004AB040(4);
    func_004A1638(2);
    func_004AB040(8);
    func_004A1638(6);
    func_004A2808(0x44, one);
    func_00499728(s1);
    func_0049CC48(s2);
    func_004AA1D8(arg0->x, arg0->y, arg0->z, arg0->w);
    func_0049FD50(4, D_00618340, D_00618400, 0, 0, 0);
    RaceEntryCar__update(1);
    func_004A5400();
    RaceEntryCar__update(0);
    func_004A5400();
}
