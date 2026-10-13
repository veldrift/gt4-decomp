typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct S;
struct Struct_00451578;

extern "C" void func_003B1B60(s32 arg0);
extern "C" void func_004513E8(S *arg0, f32 arg1);
extern "C" void func_00451418(void *arg0, void *arg1);
extern "C" void func_00451578(Struct_00451578 *arg0, u32 arg1, f32 fparg0);

extern "C" void func_00391068(char *arg0) {
    char *s2 = arg0 + 0xDC0;
    if (*(s32 *)(arg0 + 0x1670) != 0) {
        s32 s3 = (s32)(arg0 + 0x5E0);
        if (*(s32 *)s2 != 0) {
            func_004513E8((S *)(arg0 + 0x18), -*(f32 *)(s2 + 4));
        }
        if (*(s32 *)(s2 + 8) != 0) {
            func_00451418(arg0 + 0x18, arg0 + 0xDD4);
        }
        if (*(s32 *)(s2 + 0x54) != 0) {
            char *s0 = arg0 + 0x18;
            func_00451578((Struct_00451578 *)s0, 0, *(f32 *)(s2 + 0x58));
            func_00451578((Struct_00451578 *)s0, 1, *(f32 *)(s2 + 0x5C));
        }
        func_003B1B60(s3);
        if (*(s32 *)(arg0 + 0x1674) != 0) {
            func_003B1B60((s32)(arg0 + 0xE20));
        }
    }
}
