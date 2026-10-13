typedef int s32;

static inline void relocate(s32 *field, s32 base)
{
    s32 v = *field;
    if (v != 0) {
        *field = v + base;
    }
}

extern "C" void func_00474B08(char *arg0, s32 arg1)
{
    s32 *p18 = (s32 *)(arg0 + 0x18);
    s32 *p20 = (s32 *)(arg0 + 0x20);

    relocate(p18, arg1);
    arg0 = arg0 + 0x10;
    relocate((s32 *)arg0, arg1);
    relocate(p20, arg1);
}
