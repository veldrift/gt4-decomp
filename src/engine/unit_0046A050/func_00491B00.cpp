typedef int s32;

extern "C" void func_00491B00(char *arg0, s32 arg1)
{
    s32 *p10 = (s32 *)(arg0 + 0x10);
    s32 temp_v0;

    arg0 = arg0 + 0xC;
    temp_v0 = *(s32 *)arg0;
    if (temp_v0 != 0) {
        *(s32 *)arg0 = temp_v0 + arg1;
    }
    temp_v0 = *p10;
    if (temp_v0 != 0) {
        *p10 = temp_v0 + arg1;
    }
}
