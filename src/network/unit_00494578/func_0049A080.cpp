#include "spr.h"
typedef int s32;
extern "C" void func_00499F18(void *, s32) throw();
extern "C" void func_0049A150(void *, s32, s32, s32, s32, s32, float);
extern "C" void func_0049FE28(void);
extern "C" void func_0049A080(s32 a, s32 b, s32 c, s32 d, float f, s32 e) {
    void *base = (void *)spr_base();
    if (a >= 3) {
        func_0049FE28();
        func_00499F18(base, e);
        return func_0049A150(base, 4, a, b, c, d, f);
    }
}
