extern "C" {
typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64;
typedef float f32; typedef double f64;
typedef int s128 __attribute__((mode(TI))); typedef unsigned int u128 __attribute__((mode(TI)));
#define NULL 0
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
typedef int M2C_UNK;
typedef signed char M2C_UNK8;
typedef short M2C_UNK16;
typedef int M2C_UNK32;
typedef long long M2C_UNK64;
void func_0038A010();                            /* extern */
void func_00399300(s32, M2C_UNK);                /* extern */
void func_003D33C0(s32);                         /* extern */

void func_0033C3E8(s32 arg0) {
    func_0038A010();
    func_00399300(arg0 + 0xE170, 0);
    func_003D33C0(arg0 + 0x3628);
}

}
