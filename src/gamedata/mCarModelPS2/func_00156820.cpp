typedef int s32;
extern "C" s32 func_0049CE00(void);
extern "C" void ModelSet2__registerExternalTexSet(s32, s32);
extern "C" void func_00456918(float);
extern "C" void ModelSet2__texLOD(s32);
extern "C" void func_004568B0(float);
extern "C" void func_004568A0(float);
extern "C" void func_004AB040(s32);
extern "C" void func_004A1638(s32);
extern "C" void pglFrontFace(s32);
extern "C" void func_004A19B0(s32);
extern "C" void func_004A7550(void *);
extern "C" void func_004A7890(float, float, float);
extern "C" void func_004A53F8(void);
extern "C" void func_004A7A54(void);
extern "C" void func_004A7774(void *);
extern "C" void func_004A7B18(void *);
extern "C" void func_004A5400(void);
extern "C" void func_00156820(s32 enabled) {
    char temporary[0x40];
    ModelSet2__registerExternalTexSet(0, func_0049CE00());
    func_00456918(1.0f);
    ModelSet2__texLOD(0);
    func_004568B0(1.3f);
    func_004568A0(1.1f);
    func_004AB040(8);
    func_004A1638(15);
    pglFrontFace(0);
    func_004A19B0(2);
    if (enabled != 0) {
        pglFrontFace(1);
        func_004A1638(21);
        func_004A7550(temporary);
        func_004A7890(1.0f, -1.0f, 1.0f);
        func_004A53F8();
        func_004A7A54();
        func_004A7774(temporary);
        func_004A7550(temporary);
        func_004A7B18(temporary);
        func_004A5400();
    }
}
