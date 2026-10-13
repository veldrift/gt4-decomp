typedef int s32;

extern "C" void func_0055DE18(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp = arg1 * 0x1D0;
    s32 off = temp + 0x2AB0;

    *(s32 *)(arg0 + off) |= 0x2000;
    *(s32 *)((temp + arg0) + 0x2C6C) = arg2;
}
