#include "types.h"

extern "C" void GT4Model__BinStreamWriter__write8u(s32, u8);

extern "C" void func_0045B040(s32 arg0, u8 *arg1) {
    u8 *p = arg1;
    if (*p != 0) {
        u8 c;
        do {
            c = *p;
            p++;
            GT4Model__BinStreamWriter__write8u(arg0, c);
        } while (*p != 0);
    }
    GT4Model__BinStreamWriter__write8u(arg0, 0);
}
