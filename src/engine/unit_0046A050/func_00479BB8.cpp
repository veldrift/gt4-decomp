typedef int s32;

static inline void relocate(s32 *field, s32 base)
{
    s32 v = *field;
    if (v != 0) {
        *field = v + base;
    }
}

extern "C" void func_00479BB8(char *arg0, s32 arg1)
{
    s32 *p2c = (s32 *)(arg0 + 0x2C);
    arg0 = arg0 + 0x24;

    relocate((s32 *)arg0, arg1);
    relocate(p2c, arg1);
}
