typedef int s32;
typedef unsigned int u32;

extern "C" s32 D_00655F20;
extern "C" s32 D_00657080;

extern "C" s32 func_00581638(void) {
    if (D_00655F20 == 1) {
        return *(s32 *)((u32)&D_00657080 | 0x20000000);
    }
    return 0;
}
