#include "spr.h"
struct Scratchpad { char padding[0x1040]; char buffer[1]; };
static inline char *buffer(Scratchpad *p, char (Scratchpad::*member)[1]) {
    return p->*member;
}
extern "C" char *func_004A7B90(void) {
    return buffer((Scratchpad *)spr_base(), &Scratchpad::buffer);
}
