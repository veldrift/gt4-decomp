#include "types.h"

extern "C" void func_0045AF18(s32, u8);

extern "C" void func_0045B040(s32 arg0, u8 *arg1) {
    u8 *p = arg1;
    if (*p != 0) {
        u8 c;
        do {
            c = *p;
            p++;
            func_0045AF18(arg0, c);
        } while (*p != 0);
    }
    func_0045AF18(arg0, 0);
}
