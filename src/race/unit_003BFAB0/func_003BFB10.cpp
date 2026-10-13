typedef int s32;

extern "C" void func_005A48D8(void *dst, int value, unsigned int n);
extern "C" char D_00622F4C[];

extern "C" void func_003BFB10(void *arg0)
{
    char *src = *(char **)D_00622F4C + 0x38CB0;
    s32 *d = (s32 *)arg0;

    d[0] = *(s32 *)(src + 0x10C0);
    d[1] = *(s32 *)(src + 0x10E4);
    d[2] = *(s32 *)(src + 0x10C4);
    d[3] = *(s32 *)(src + 0x10FC);
    d[4] = *(s32 *)(src + 0x10E4);
    d[5] = *(s32 *)(src + 0x1100);
    d[6] = *(s32 *)(src + 0x1104);
    d[7] = *(s32 *)(src + 0x1108);
    func_005A48D8((char *)arg0 + 0x20, 0, 0x40);
}
