typedef int s32;
struct S { char p0[0xC4]; S *fC4; };
extern "C" S *func_00206868(S *arg0);
extern "C" S *func_0025C300(S *arg0);
extern "C" s32 func_00265D98(S *arg0);

extern "C" S *func_002C8100(S *arg0, s32 arg1) {
    S *result = 0;
    S *s0;
    s32 s1;
    if (arg0->fC4 != 0) {
        s1 = 0;
        s0 = func_00206868(arg0->fC4);
        while (s0 != 0) {
            if (func_00265D98(s0) == 0) {
                if (s1 == arg1) {
                    break;
                }
                s1 += 1;
            }
            s0 = func_0025C300(s0);
        }
        result = s0;
    }
    return result;
}
