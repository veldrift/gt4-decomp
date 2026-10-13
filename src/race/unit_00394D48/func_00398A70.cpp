typedef int s32;

extern "C" void func_00398A30(void *arg0, s32 arg1, s32 arg2);

extern "C" void func_00398A70(void *arg0) {
    func_00398A30((char *)arg0 + 0x4, 0x1F, 0);
    func_00398A30((char *)arg0 + 0x28, 0x20, 0);
    func_00398A30((char *)arg0 + 0x4C, 0x21, 0);
    func_00398A30((char *)arg0 + 0x70, 0x3D, 0);
    func_00398A30((char *)arg0 + 0x94, 0x22, 0);
    func_00398A30((char *)arg0 + 0xB8, 0x23, 0);
    func_00398A30((char *)arg0 + 0xDC, 0x24, 0);
    func_00398A30((char *)arg0 + 0x100, 0x25, 0);
    func_00398A30((char *)arg0 + 0x124, 0x26, 0);
    func_00398A30((char *)arg0 + 0x148, 0x1E, 0);
    *(s32 *)((char *)arg0 + 0x24) = 1;
    *(s32 *)((char *)arg0 + 0x48) = 1;
    *(s32 *)((char *)arg0 + 0x6C) = 1;
    *(s32 *)((char *)arg0 + 0x90) = 1;
    *(s32 *)((char *)arg0 + 0xB4) = 1;
}
