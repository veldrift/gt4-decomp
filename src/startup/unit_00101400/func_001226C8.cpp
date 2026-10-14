typedef int s32;
struct Obj { char pad[0x2E8]; float f2E8; char pad1[0x308 - 0x2EC]; float f308; s32 i30C; };
struct E16 { char b[16]; };
extern E16 D_00618770[];
extern "C" void func_00123608(void);
extern "C" s32 func_00123680(void *, s32);
extern "C" void func_00121DD0(void *, s32, void (*)(void), E16 *, float, float);
extern "C" void func_004A1638(s32);
extern "C" s32 func_004A1D28(void);
extern "C" void func_004A1E08(void);
extern "C" void func_004A1EB8(s32);
extern "C" void func_004A2808(s32, float);
extern "C" void func_004A2B10(float, float);
extern "C" void func_004AB040(s32);

extern "C" void func_001226C8(Obj *arg0, s32 arg1, float fp) {
    if (func_00123680(arg0, arg1) != 0) {
        float t = (arg0->f308 / (float)arg0->i30C) / arg0->f2E8;
        func_004A1638(9);
        func_004AB040(6);
        func_004A2808(0x44, 1.0f);
        s32 s = func_004A1D28();
        func_00121DD0(arg0, arg1, func_00123608, &D_00618770[arg1], fp, t);
        func_004A1E08();
        func_004AB040(9);
        func_004A2B10(0.0f, 0.0f);
        func_004A1EB8(s);
        func_004A2B10(1.0f, 0.0f);
        func_004A1EB8(s);
        func_004A2B10(0.0f, 1.0f);
        func_004A1EB8(s);
        func_004A2B10(1.0f, 1.0f);
        func_004A1EB8(s);
        func_004A2B10(0.5f, 0.5f);
        func_004A1EB8(s);
    }
}
