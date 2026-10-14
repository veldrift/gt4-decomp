/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
extern "C" void func_00499F18(void *, int) throw();
extern "C" void func_0049A150(void *, int, int, int, int, int, float);
extern "C" void func_0049FE28();
extern "C" void func_00499FB0(int a, int b, int c, int d, int e, float f) {
    void *p = (void *)spr_base();
    if (a >= 3) {
        func_0049FE28();
        func_00499F18(p, e);
        return func_0049A150(p, 5, a, b, c, d, f);
    }
}
