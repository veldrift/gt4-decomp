#include "spr.h"
/* NOT judged with `try`: the base is one opaque `li` (see the o1 report). */
struct Spr {
    char pad[0x1D8];
    long unk1D8;
};
extern "C" void func_0049FE28(void);
extern "C" void func_0049FDF0(void) {
    Spr *p = (Spr *)spr_base();
    p->unk1D8 = 0x3FF1FFF1FFFL;
    return func_0049FE28();
}
