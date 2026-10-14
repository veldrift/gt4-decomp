/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern "C" s32 func_005A6AB0(void *, void *, s32);
struct Dst { char pad[0x70C]; char unk70C[0x1C]; };
extern "C" void func_004FB3C0(char *arg0, char *arg1, s32 arg2) {
    char *s0 = arg0 + 0x70C;
    *(s32 *)(s0 + 0x14) = arg2;
    *(s32 *)(s0 + 0x18) = *(s32 *)(arg1 + 0x30);
    func_005A6AB0(arg0 + 0x728, arg1 + 0x134, 0x40);
    func_005A6AB0(arg0 + 0x768, arg1 + 0x34, 0x100);
    *(s32 *)(s0 + 0x15C) = *(s32 *)(arg1 + 0x20);
    *(s32 *)(s0 + 0x160) = *(s32 *)(arg1 + 0x24);
    *(s32 *)(s0 + 0x164) = *(s32 *)(arg1 + 0x28);
    *(s32 *)(s0 + 0x168) = *(s32 *)(arg1 + 0x2C);
    *(s32 *)(s0 + 0x16C) = *(s32 *)(arg1 + 0x174);
    *(s32 *)(s0 + 0x170) = *(s32 *)(arg1 + 0x178);
    *(s32 *)(s0 + 0x174) = *(s32 *)(arg1 + 0x17C);
    *(s32 *)(s0 + 0x178) = *(s32 *)(arg1 + 0x180);
    *(s32 *)(s0 + 0x17C) = 2;
    func_005A6AB0(s0, arg0 + 0xAF8, 0x11);
}
