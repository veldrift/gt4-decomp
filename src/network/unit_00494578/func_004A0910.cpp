#include "spr.h"
struct Spr {
    char pad[0x10];
    unsigned char mode;
    char pad11[0x97];
    unsigned long value;
};
extern "C" void func_004A0910(unsigned char enable) {
    Spr *p = (Spr *)spr_base();
    unsigned long mask = (p->mode == 1) ? 3 : 2;
    switch (enable) {
        case 1:
            *(volatile unsigned long *)0x12000000 = p->value | mask;
            return;
        case 0:
            *(volatile unsigned long *)0x12000000 = p->value & ~mask;
            return;
    }
}
