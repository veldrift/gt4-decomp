/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct R { char pad0[8]; s32 w; char pad1[4]; s32 x; s32 y; s32 dx; s32 dy; };

extern "C" void func_00105728(void *);
extern "C" s32 func_00105818(void *);
extern "C" void func_004A1638(s32);
extern "C" void func_004A26F0(s32);
extern "C" void func_004A2750(s32, float);
extern "C" void func_004A2980(s32);
extern "C" void func_004A3230(s32);
extern "C" void func_004A4550(s32, s32);
extern "C" void func_004A6788(float, float, float, float, float, float, float, float);
extern "C" void func_004A6F10(s32, s32);
extern "C" void func_004AB040(s32);

extern "C" void func_00342470(R *arg0) {
    func_004A3230(2);
    float z = 0.0f;
    func_00105728(arg0);
    func_004A4550(3, 0);
    func_004A4550(2, 0);
    func_004A1638(5);
    func_004A1638(4);
    func_004A26F0(1);
    func_004A2750(7, z);
    func_004A2980(0);
    func_004A6F10(1, 0xFF);
    float w = (float)arg0->w;
    func_004A6788(z, z, w, (float)func_00105818(arg0), (float)arg0->x, (float)arg0->y, (float)(arg0->x + arg0->dx), (float)(arg0->y + arg0->dy));
    func_004AB040(4);
    func_004A26F0(3);
    func_004A2980(0xFFFFFF);
}
