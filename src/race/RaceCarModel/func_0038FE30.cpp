typedef int s32;

struct Obj;

extern "C" s32 func_004510E0(Obj **arg0);
extern "C" void func_0044F4A8(void);
void func_003B0FD0(s32 *arg0, s32 arg1);
extern "C" void func_003B1C98(s32 arg0, s32 *arg1);

extern "C" s32 func_0038FE30(s32 arg0, s32 arg1) {
    s32 self = arg0;
    s32 temp_s2;
    s32 result;

    temp_s2 = self + 0x5E0;
    result = func_004510E0((Obj **)(self + 0x18));
    if (result == 0) {
        return result;
    }
    func_0044F4A8();
    func_003B0FD0((s32 *)temp_s2, result);
    if (arg1 != 0) {
        func_003B1C98(self + 0xE20, (s32 *)temp_s2);
    }
    return 1;
}
