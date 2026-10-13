typedef int s32;
typedef unsigned int u32;

extern "C" void mUpdateContextPS2__virtual_67(char *arg0, s32 arg1, s32 arg2)
{
    u32 *cnt = (u32 *)(arg0 + 0x358);
    u32 n = *cnt;

    *(s32 *)((char *)cnt + 0x88) = arg1;
    if (n < 0x10) {
        arg0 += n * 4;
        *(s32 *)(arg0 + 0x35C) = arg2;
        *cnt = n + 1;
    }
}
