typedef float f32;
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

struct func_0034A8B0_arg0 {
    char pad0[0x4];
    char *unk4;
    char pad8[0x544 - 0x8];
    u8 unk544;
};

extern "C" s32 func_0034A8B0(struct func_0034A8B0_arg0 *arg0, f32 *arg1, f32 *arg2) {
    f32 *o1 = arg1;
    u32 idx = arg0->unk544;
    char *base = arg0->unk4;
    u32 off = ((idx * 3) << 4);
    u32 q = (u32)base + off;
    s32 k = 0xCAB8;
    char *p = (char *)(k + q);
    if (*(s32 *)(p + 0x24) == 0) {
        f32 z = 0.0f;
        *arg2 = z;
        *o1 = z;
        return 0;
    }
    *o1 = *(f32 *)(p + 0x20);
    *arg2 = *(f32 *)(p + 0x1C);
    return 1;
}
