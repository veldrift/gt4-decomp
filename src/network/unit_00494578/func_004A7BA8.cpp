#include "spr.h"
struct Work { char pad[0x150]; long flags; };
enum Mode { ZERO = 0, TWO = 2, THREE = 3 };
extern "C" int func_004A7BA8(void) {
    Work *p = (Work *)spr_base();
    Mode mode = (Mode)(int)(p->flags & 3);
    switch (mode) {
    case ZERO: return 0;
    case TWO: return 3;
    case THREE: return 4;
    }
    return 0;
}
