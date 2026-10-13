typedef int s32;

struct func_0025C3C0_obj {
    char pad0[0x5C];
    s32 unk5C;
};

extern "C" s32 func_0025C2F8(s32 arg0);
extern "C" s32 func_00265D98(s32 arg0);

extern "C" s32 func_0025C3C0(struct func_0025C3C0_obj *arg0)
{
    s32 var_s0;

    var_s0 = arg0->unk5C;
    if (var_s0 != 0)
    {
        do
        {
            if (func_00265D98(var_s0) == 0)
            {
                return var_s0;
            }
            var_s0 = func_0025C2F8(var_s0);
        } while (var_s0 != 0);
    }
    return 0;
}
