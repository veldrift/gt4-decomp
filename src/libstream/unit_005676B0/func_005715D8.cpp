#include "types.h"

extern "C" {
s32 func_00538DC0(char *);                      /* extern */

s32 func_005715D8(char *arg0) {
    s32 var_v0 = 2;
    if (arg0 != 0) {
        if (func_00538DC0(arg0 + 0x10) != 0) {
            return 1;
        }
        var_v0 = func_00538DC0(arg0 + 0x18) != 0;
    }
    return var_v0;
}

}
