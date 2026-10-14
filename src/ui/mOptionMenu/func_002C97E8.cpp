/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct S;
struct Obj;
struct Arg0 { char pad[0xC4]; S *unkC4; };
extern "C" s32 func_00208428(S *);
extern "C" s32 func_00206878(S *);
extern "C" s32 func_0025C2E8(S *);
extern "C" s32 func_00265D98(Obj *);
extern "C" u32 func_002661C8(S *);
extern "C" s32 func_002C97E8(Arg0 *arg0, s32 arg1) {
    S *var_s0;
    s32 var_s1;
    s32 var_s3;
    s32 result = -1;
    S *temp = arg0->unkC4;
    if (temp != 0) {
        var_s3 = 0;
        var_s1 = func_00208428(temp) - 1;
        var_s0 = (S *)func_00206878(arg0->unkC4);
        while (var_s0 != 0) {
            if (func_00265D98((Obj *)var_s0) == 0) {
                if (var_s1 <= arg1 && func_002661C8(var_s0) == 0) {
                    var_s3 = 1;
                    break;
                }
                var_s1--;
            }
            var_s0 = (S *)func_0025C2E8(var_s0);
        }
        result = var_s3 != 0 ? var_s1 : -1;
    }
    return result;
}
