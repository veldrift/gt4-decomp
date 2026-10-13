typedef int s32;
typedef float f32;

extern "C" void func_0011A4C0(char *arg0, s32 arg1) {
    s32 v0;
    s32 v1;

    *(f32 *)(arg0 + 0xCF44) = 0.5f;
    if (arg1 != 0) {
        v1 = 0x23;
        v0 = 0x24;
    } else {
        v1 = 0x1B;
        v0 = 0x1C;
    }
    *(s32 *)(arg0 + 0xD60) = v1;
    *(s32 *)(arg0 + 0xD64) = v0;
}
