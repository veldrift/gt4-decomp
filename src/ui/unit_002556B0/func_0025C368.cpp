typedef int s32;

struct Obj {
    char pad0[0x58];
    s32 unk58;
};

struct S_0025C2E0;

extern "C" s32 func_00265D98(Obj *arg0);
extern "C" s32 func_0025C2E8(S_0025C2E0 *arg0);

extern "C" s32 func_0025C368(Obj *arg0)
{
    s32 var_s0;

    var_s0 = arg0->unk58;
    if (var_s0 != 0)
    {
        do
        {
            if (func_00265D98((Obj *)var_s0) == 0)
            {
                return var_s0;
            }
            var_s0 = func_0025C2E8((S_0025C2E0 *)var_s0);
        } while (var_s0 != 0);
    }
    return 0;
}
