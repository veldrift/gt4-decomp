typedef int s32;
typedef unsigned int u32;

struct S;
struct Obj;

struct Arg0 {
    char pad0[0xC4];
    S *unkC4;
};

extern "C" int func_00206868(S *arg0);
extern "C" s32 func_0025C300(S *arg0);
extern "C" s32 func_00265D98(Obj *arg0);
extern "C" u32 func_002661C8(S *arg0);

extern "C" s32 func_002C9740(Arg0 *arg0, s32 arg1)
{
    S *var_s0;
    s32 var_s1;
    s32 var_s3;
    s32 var_v0 = -1;
    S *temp = arg0->unkC4;

    if (temp != 0) {
        var_s1 = 0;
        var_s0 = (S *)func_00206868(temp);
        var_s3 = 0;
        while (var_s0 != 0) {
            if (func_00265D98((Obj *)var_s0) == 0) {
                if (var_s1 >= arg1 && func_002661C8(var_s0) == 0) {
                    var_s3 = 1;
                    break;
                }
                var_s1++;
            }
            var_s0 = (S *)func_0025C300(var_s0);
        }
        var_v0 = (var_s3 != 0) ? var_s1 : -1;
    }
    return var_v0;
}
