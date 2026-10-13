/* compiler: ee-gcc2.96-nosched1 */
typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32;

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

void func_0033DD18(void *arg0) {
    s32 one = 1;
    s32 hundred = 0x100;
    M2C_FIELD(arg0, s32 *, 0xE344) = one;
    M2C_FIELD(arg0, s32 *, 0xE330) = hundred;
    M2C_FIELD(arg0, s32 *, 0xE34C) = 0;
    M2C_FIELD(arg0, s32 *, 0xE334) = one;
    M2C_FIELD(arg0, s32 *, 0xE338) = one;
    M2C_FIELD(arg0, s32 *, 0xE33C) = one;
    M2C_FIELD(arg0, s32 *, 0xE340) = one;
    M2C_FIELD(arg0, s32 *, 0xE348) = 0;
}
