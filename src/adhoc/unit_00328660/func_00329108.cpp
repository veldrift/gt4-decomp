typedef int s32;

extern "C" void func_00328D50(char *arg0, s32 arg1);
extern "C" void free(s32 arg0);
extern "C" void func_00576788(s32 arg0);
extern "C" void func_005767C0(s32 arg0);

extern "C" void func_00329108(char *arg0, s32 arg1)
{
    func_00576788((s32)arg0);
    if (*(s32 *)(arg0 + 0x40) != 0 && *(s32 *)(arg0 + 0x44) != 0) {
        func_00328D50(arg0, arg1);
    } else {
        free(arg1 - 0x10);
        *(s32 *)(arg0 + 0x48) = *(s32 *)(arg0 + 0x48) - 1;
    }
    func_005767C0((s32)arg0);
}
