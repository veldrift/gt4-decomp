typedef int s32;
typedef float f32;
typedef unsigned char s8;

extern "C" void func_004071D8(s32 arg0, f32 fparg0);
extern "C" s32 func_00407208(s32 arg0, s32 arg1);

extern "C" void func_003867A0(s32 arg0, f32 fparg0) {
    s8 pad[0x100];
    s8 sp100[0x100];
    s32 temp_s0 = arg0;
    s32 temp_s2 = temp_s0 + 0x160;
    s32 temp_s1 = (s32)sp100;

    func_004071D8(temp_s1, fparg0);
    func_00407208(temp_s2, temp_s1);
    temp_s0 += 0x260;
    func_004071D8(temp_s1, fparg0);
    func_00407208(temp_s0, temp_s1);
}
