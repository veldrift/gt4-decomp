#include "spr.h"
struct Scratch { char pad[0xb60]; char buffer[1]; };
extern "C" int func_004AC034(void *, int);
extern "C" int func_004A7B18(int arg0) {
    Scratch *p = (Scratch *)spr_base();
    return func_004AC034(p->buffer, arg0);
}
