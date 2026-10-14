typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern "C" void func_00397DA0(void *self, f32 f);
extern "C" void ModelSet2__render(s32 a0, s32 a1);
extern "C" void func_004A2980(s32 a0);
extern "C" void func_004A3078(s32 a0);
extern "C" void func_004A3230(s32 a0);
extern "C" void RaceEntryCar__update(s32 a0);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void pglPushAttrib(s32 a0);
extern "C" void func_004A5688(void);
extern "C" void func_004A74B4(f32 *a0);
extern "C" void func_004A7550(f32 *a0);

extern "C" void func_00396D40(char *arg0) {
    f32 buf[16];
    if (*(s32 *)(arg0 + 0x58) != 0) {
        pglPushAttrib(0x40);
        func_004A2980((s32)0xFF000000U);
        func_004A3078(0);
        func_004A3230(3);
        func_004A2980(-1);
        func_00397DA0(*(char **)(arg0 + 0x80) + 0x60, 1.0f);
        RaceEntryCar__update(1);
        func_004A53F8();
        func_004A7550(buf);
        buf[14] = buf[14] * 100.0f;
        func_004A74B4(buf);
        RaceEntryCar__update(0);
        ModelSet2__render(*(s32 *)(arg0 + 0x58), 0);
        RaceEntryCar__update(1);
        func_004A5400();
        RaceEntryCar__update(0);
        func_004A5688();
    }
}
