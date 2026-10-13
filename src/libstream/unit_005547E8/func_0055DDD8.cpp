/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

extern "C" void func_0055DDD8(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    s32 temp = arg1 * 0x1D0;
    s32 off1 = temp + 0x2AB0;
    s32 off2 = temp + 0x2C30;

    *(s32 *)(arg0 + off1) |= 2;
    *(s16 *)(arg0 + off2 + 0xC) = arg2;
    *(s16 *)(arg0 + off2 + 0xE) = arg3;
}
