typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

struct func_003E9190_arg0 {
    u8 *unk0;
    s16 unk4;
};

extern "C" s32 func_003E9190(struct func_003E9190_arg0 *arg0, s32 arg1)
{
    s32 v;
    s32 count = 0;

    v = arg0->unk4;
    if (v >= 0) {
        do {
            s32 inc = count + 1;
            u32 w = *(u32 *)(arg0->unk0 + (v << 6));
            s32 f = (s32)((w >> 13) & 7);
            v = ((s32)(w << 19)) >> 19;
            if ((f ^ arg1) == 0) {
                count = inc;
            }
        } while (v >= 0);
    }
    return count;
}
